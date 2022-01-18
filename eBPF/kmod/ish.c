#include<linux/module.h>
#include<linux/version.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/kprobes.h>

static unsigned int counter = 0;
unsigned long conn;
unsigned long skb;
static struct kprobe kp;
static struct kprobe kp2;


int kpb_pre_l2cap_recv_frame(struct kprobe *p, struct pt_regs *regs){
	// printk("r15=%p,r14=%p,r13=%p,r12=%p,rbp=%p,rbx=%p,r11=%p,r10=%p,r9=%p,r8=%p,rax=%p,rcx=%p,rdx=%p,rsi=%p,rdi=%p,orig_rax=%p,rip=%p,cs=%p,eflags=%p,rsp=%p,ss=%p", 
	// regs->r15,regs->r14,regs->r13,regs->r12,regs->bp,regs->bx,regs->r11,regs->r10,regs->r9,regs->r8,regs->ax,regs->cx,
	// regs->dx,regs->si,regs->di,regs->orig_ax,regs->ip,regs->cs,regs->flags,regs->sp,regs->ss);
	printk("l2cap_recv_frame pre_handler: counter=%u, conn=%p, skb=%p\n", counter, regs->r13, regs->r12);
	conn = regs->r13;
	skb = regs->r12;
	return 0;
}

void kpb_post_l2cap_recv_frame(struct kprobe *p, struct pt_regs *regs, unsigned long flags){
	printk("l2cap_recv_frame post_handler: counter=%u, conn=%p, skb=%p\n", counter++, conn, skb);
}

int kpb_pre_l2cap_sig_channel(struct kprobe *p, struct pt_regs *regs){
	printk("l2cap_sig_channel pre_handler: counter=%u, conn=%p, skb=%p\n", counter, conn, skb);
	return 0;
}

void kpb_post_l2cap_sig_channel(struct kprobe *p, struct pt_regs *regs, unsigned long flags){
	printk("l2cap_sig_channel post_handler: counter=%u, conn=%p, skb=%p\n", counter, conn, skb);
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
