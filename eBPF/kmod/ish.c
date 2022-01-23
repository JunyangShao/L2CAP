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

struct l2cap_conn * conn;
struct sk_buff * skb;
static struct kprobe kp;
static struct kprobe kp2;
u16 dstChanID;
__le16 l2psm;
u16 srcChanID;

int kpb_pre_l2cap_recv_frame(struct kprobe *p, struct pt_regs *regs){
	// printk("r15=%p,r14=%p,r13=%p,r12=%p,rbp=%p,rbx=%p,r11=%p,r10=%p,r9=%p,r8=%p,rax=%p,rcx=%p,rdx=%p,rsi=%p,rdi=%p,orig_rax=%p,rip=%p,cs=%p,eflags=%p,rsp=%p,ss=%p", 
	// regs->r15,regs->r14,regs->r13,regs->r12,regs->bp,regs->bx,regs->r11,regs->r10,regs->r9,regs->r8,regs->ax,regs->cx,
	// regs->dx,regs->si,regs->di,regs->orig_ax,regs->ip,regs->cs,regs->flags,regs->sp,regs->ss);
	// printk("l2cap_recv_frame pre_handler: counter=%u, conn=%p, skb=%p\n", counter, regs->r13, regs->r12);
	conn = regs->r13;
	skb = regs->r12;
	return 0;
}


int kpb_pre_l2cap_sig_channel(struct kprobe *p, struct pt_regs *regs){

	struct hci_conn *hcon = conn->hcon;
	if (hcon->type != ACL_LINK)
		goto drop;

	struct l2cap_cmd_hdr *cmd;
	unsigned int skb_len = skb->len;
	unsigned int offsets = 0;
	while(skb_len >= L2CAP_CMD_HDR_SIZE){
		u16 len;
		cmd = ((void *) skb->data ) + offsets;
		offsets += L2CAP_CMD_HDR_SIZE;
		skb_len -= L2CAP_CMD_HDR_SIZE;
		len = le16_to_cpu(cmd->len);
		if (len > skb->len || !cmd->ident) {
			break;
		}
		// at this moment, cmd is fully pulled.
		if(cmd->code == L2CAP_CONN_REQ){
			struct l2cap_conn_req *req = (struct l2cap_conn_req *) ((void *)skb->data + offsets);
			if (len < sizeof(struct l2cap_conn_req))
				continue;

			/* Parameters for P Module */	
			u16 dstChanID = __le16_to_cpu(req->scid);
			__le16 l2psm = req->psm;
			/* Parameters for P Module */
		}
		else if(cmd->code == L2CAP_CONF_REQ){
			struct l2cap_conf_req *req = (struct l2cap_conf_req *) ((void *)skb->data + offsets);
			if (len < sizeof(*req))
				continue;
			u16 flags = __le16_to_cpu(req->flags);
			int len2 = len - sizeof(*req);

			/* Parameters for P Module */	
			u16 srcChanID  = __le16_to_cpu(req->dcid);
			/* Parameters for P Module */	
		
			struct l2cap_chan *chan;
			chan = l2cap_get_chan_by_scid(conn, srcChanID);
			if (!chan) {
				goto unlock;
			}
			if (chan->state != BT_CONFIG && chan->state != BT_CONNECT2 &&
	    	chan->state != BT_CONNECTED) {
				goto unlock;
			}
			if (chan->conf_len + len2 > sizeof(chan->conf_req)) {
				goto unlock;
			}
			if (flags & L2CAP_CONF_FLAG_CONTINUATION) {
				goto unlock;
			}
			unsigned char chan_buf[64];
			int chan_buflen = chan->conf_len + len2;
			int chan_buf_offset = 0;
			memcpy(chan_buf, chan->conf_req, chan->conf_len);
			memcpy(chan_buf + chan->conf_len, req->data, len2);
			int type, olen;
			unsigned long val;
			u16 mtu = L2CAP_DEFAULT_MTU;
			while (chan_buflen >= L2CAP_CONF_OPT_SIZE) {
				int tmp = l2cap_get_conf_opt2(chan_buf + chan_buf_offset, &type, &olen, &val);
				chan_buf_offset += tmp;
				chan_buflen 	-= tmp;
				if(type == L2CAP_CONF_MTU){
					if (olen != 2)
					mtu = val;
					break;
				}
			}

unlock:
			l2cap_chan_unlock(chan);
			continue;
		}
	}

}

static inline int l2cap_get_conf_opt2(void *ptr, int *type, int *olen,
				     unsigned long *val)
{
	struct l2cap_conf_opt *opt = ptr;
	int len;

	len = L2CAP_CONF_OPT_SIZE + opt->len;

	*type = opt->type;
	*olen = opt->len;

	switch (opt->len) {
	case 1:
		*val = *((u8 *) opt->val);
		break;

	case 2:
		*val = get_unaligned_le16(opt->val);
		break;

	case 4:
		*val = get_unaligned_le32(opt->val);
		break;

	default:
		*val = (unsigned long) opt->val;
		break;
	}

	return len;
}


int minit(void)
{
	printk("Module inserted\n ");

	kp.pre_handler = kpb_pre_l2cap_recv_frame;
	kp.addr = (kprobe_opcode_t *)0xffffffffc05540c0;

	kp2.pre_handler = kpb_pre_l2cap_sig_channel;
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
