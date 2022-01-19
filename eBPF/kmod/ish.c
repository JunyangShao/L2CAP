#include<linux/module.h>
#include<linux/version.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/kprobes.h>


#include <linux/debugfs.h>
#include <linux/crc16.h>
#include <linux/filter.h>

#include <net/bluetooth/bluetooth.h>
#include <net/bluetooth/hci_core.h>
#include <net/bluetooth/l2cap.h>

static unsigned int counter = 0;
struct l2cap_conn * conn;
struct sk_buff * skb;
static struct kprobe kp;
static struct kprobe kp2;


int kpb_pre_l2cap_recv_frame(struct kprobe *p, struct pt_regs *regs){
	// printk("r15=%p,r14=%p,r13=%p,r12=%p,rbp=%p,rbx=%p,r11=%p,r10=%p,r9=%p,r8=%p,rax=%p,rcx=%p,rdx=%p,rsi=%p,rdi=%p,orig_rax=%p,rip=%p,cs=%p,eflags=%p,rsp=%p,ss=%p", 
	// regs->r15,regs->r14,regs->r13,regs->r12,regs->bp,regs->bx,regs->r11,regs->r10,regs->r9,regs->r8,regs->ax,regs->cx,
	// regs->dx,regs->si,regs->di,regs->orig_ax,regs->ip,regs->cs,regs->flags,regs->sp,regs->ss);
	// printk("l2cap_recv_frame pre_handler: counter=%u, conn=%p, skb=%p\n", counter, regs->r13, regs->r12);
	conn = regs->r13;
	skb = regs->r12;
	return 0;
}

void kpb_post_l2cap_recv_frame(struct kprobe *p, struct pt_regs *regs, unsigned long flags){
	counter++;
	// printk("l2cap_recv_frame post_handler: counter=%u, conn=%p, skb=%p\n", counter++, conn, skb);
}

int kpb_pre_l2cap_sig_channel(struct kprobe *p, struct pt_regs *regs){
	struct hci_conn *hcon = conn->hcon;
	struct l2cap_cmd_hdr *cmd;

	int err;

	l2cap_raw_recv(conn, skb);

	if (hcon->type != ACL_LINK)
		goto drop;

	while (skb->len >= L2CAP_CMD_HDR_SIZE) {
		u16 len;

		cmd = (void *) skb->data;
		skb_pull(skb, L2CAP_CMD_HDR_SIZE);

		len = le16_to_cpu(cmd->len);

		BT_DBG("code 0x%2.2x len %d id 0x%2.2x", cmd->code, len,
		       cmd->ident);

		if (len > skb->len || !cmd->ident) {
			BT_DBG("corrupted command");
			break;
		}

		err = l2cap_bredr_sig_cmd(conn, cmd, len, skb->data);
		if (err) {
			struct l2cap_cmd_rej_unk rej;

			BT_ERR("Wrong link type (%d)", err);

			rej.reason = cpu_to_le16(L2CAP_REJ_NOT_UNDERSTOOD);
			l2cap_send_cmd(conn, cmd->ident, L2CAP_COMMAND_REJ,
				       sizeof(rej), &rej);
		}

		skb_pull(skb, len);
	}

drop:
	kfree_skb(skb);
	// printk("l2cap_sig_channel pre_handler: counter=%u, conn=%p, skb=%p\n", counter, conn, skb);
	return 0;
}

void kpb_post_l2cap_sig_channel(struct kprobe *p, struct pt_regs *regs, unsigned long flags){
	// printk("l2cap_sig_channel post_handler: counter=%u, conn=%p, skb=%p\n", counter, conn, skb);
}

int minit(void)
{
	printk("Module inserted\n ");

	kp.pre_handler = kpb_pre_l2cap_recv_frame;
	kp.post_handler = kpb_post_l2cap_recv_frame;
	kp.addr = (kprobe_opcode_t *)0xffffffffc05540c0;

	kp2.pre_handler = kpb_pre_l2cap_sig_channel;
	kp2.post_handler = kpb_post_l2cap_sig_channel;
	kp2.addr = (kprobe_opcode_t *)0xffffffffc0552da0;

	register_kprobe(&kp);
	register_kprobe(&kp2);
	return 0;
}

void mexit(void)
{
	unregister_kprobe(&kp);
	unregister_kprobe(&kp2);
	printk("Module removed\n ");
}
module_init(minit);
module_exit(mexit);
MODULE_AUTHOR("Junyang Shao");
MODULE_DESCRIPTION("Trying to read something out of l2cap_sig_channel");
MODULE_LICENSE("GPL");
