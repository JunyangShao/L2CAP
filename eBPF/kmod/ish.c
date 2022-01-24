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

int counter = 0;

struct l2cap_conn * conn;
struct sk_buff * skb;
static struct kprobe kp;
static struct kprobe kp2;


u16 dstChanID;
__le16 l2psm;
// we can just put above into the l2cap_conn case
u8 can_putConn;

u16 srcChanID;
u16 mtuVal;
// we can just put above into the l2cap_conf case
u8 can_putConf;

static struct l2cap_chan *__l2cap_get_chan_by_dcid(struct l2cap_conn *conn,
						   u16 cid)
{
	struct l2cap_chan *c;
	// int counti = 0;
	list_for_each_entry(c, &conn->chan_l, list) {
		// printk("iterating dcid...%d\n",counti++);
		if (c->dcid == cid)
			return c;
	}
	// printk("not found dcid...\n");
	return NULL;
}

static struct l2cap_chan *__l2cap_get_chan_by_scid(struct l2cap_conn *conn,
						   u16 cid)
{
	struct l2cap_chan *c;
	// int counti = 0;

	list_for_each_entry(c, &conn->chan_l, list) {
		// printk("iterating scid...%d\n",counti++);
		if (c->scid == cid)
			return c;
	}
	// printk("not found scid...\n");
	return NULL;
}

static struct l2cap_chan *l2cap_global_chan_by_psm(int state, __le16 psm,
						   bdaddr_t *src,
						   bdaddr_t *dst,
						   u8 link_type)
{
	struct l2cap_chan *c, *c1 = NULL;
	
	LIST_HEAD(chan_list);
	list_for_each_entry(c, &chan_list, global_l) {
		if (state && c->state != state)
			continue;

		if (link_type == ACL_LINK && c->src_type != BDADDR_BREDR)
			continue;

		if (link_type == LE_LINK && c->src_type == BDADDR_BREDR)
			continue;

		if (c->psm == psm) {
			int src_match, dst_match;
			int src_any, dst_any;

			/* Exact match. */
			src_match = !bacmp(&c->src, src);
			dst_match = !bacmp(&c->dst, dst);
			if (src_match && dst_match) {
				return c;
			}

			/* Closest match */
			src_any = !bacmp(&c->src, BDADDR_ANY);
			dst_any = !bacmp(&c->dst, BDADDR_ANY);
			if ((src_match && dst_any) || (src_any && dst_match) ||
			    (src_any && dst_any))
				c1 = c;
		}
	}
	return c1;
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


int kpb_pre_l2cap_recv_frame(struct kprobe *p, struct pt_regs *regs){
	// printk("r15=%p,r14=%p,r13=%p,r12=%p,rbp=%p,rbx=%p,r11=%p,r10=%p,r9=%p,r8=%p,rax=%p,rcx=%p,rdx=%p,rsi=%p,rdi=%p,orig_rax=%p,rip=%p,cs=%p,eflags=%p,rsp=%p,ss=%p", 
	// regs->r15,regs->r14,regs->r13,regs->r12,regs->bp,regs->bx,regs->r11,regs->r10,regs->r9,regs->r8,regs->ax,regs->cx,
	// regs->dx,regs->si,regs->di,regs->orig_ax,regs->ip,regs->cs,regs->flags,regs->sp,regs->ss);
	// printk("l2cap_recv_frame pre_handler: counter=%u, conn=%p, skb=%p\n", counter++, regs->r13, regs->r12);
	
	conn = regs->r13;
	skb = regs->r12;

	dstChanID = 0;
	l2psm = 0;
	can_putConn = 0;

	srcChanID = 0;
	mtuVal = 0;
	can_putConf = 0;

	return 0;
}


int kpb_pre_l2cap_sig_channel(struct kprobe *p, struct pt_regs *regs){
	struct hci_conn *hcon = conn->hcon;
	if (hcon->type != ACL_LINK)
		return 0;

	struct l2cap_cmd_hdr *cmd;
	int skb_len = skb->len;
	int offsets = 0;
	while(skb_len >= L2CAP_CMD_HDR_SIZE){
		u16 len;
		cmd = ((void *) skb->data ) + offsets;
		offsets += L2CAP_CMD_HDR_SIZE;
		skb_len -= L2CAP_CMD_HDR_SIZE;
		len = le16_to_cpu(cmd->len);
		if (len > skb_len || !cmd->ident) {
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
			struct l2cap_chan *chan = NULL, *pchan;
			// pchan = l2cap_global_chan_by_psm(BT_LISTEN, l2psm, &conn->hcon->src,
			// 		 &conn->hcon->dst, ACL_LINK);
			// if (!pchan)
			// 	continue;

			chan = __l2cap_get_chan_by_dcid(conn, dstChanID);
			if(chan){
				continue;
			}
			// printk("cmd->code=%d, dstChanID=%d, l2psm=%d\n", cmd->code, dstChanID, l2psm);return 0;
			/* Parameters for P Module */
			can_putConn = 1;
			/* Parameters for P Module */

			/* All Parameters get */
			printk("dstChanID = %d, l2psm = %d, can_putConn=%d", dstChanID, l2psm, can_putConn);
			/* All Parameters get */
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
			chan = __l2cap_get_chan_by_scid(conn, srcChanID);
			if (!chan) {
				continue;
			}

			/* Parameters for P Module */	
			can_putConf = 1;
			/* Parameters for P Module */	

			if (chan->state != BT_CONFIG && chan->state != BT_CONNECT2 &&
	    	chan->state != BT_CONNECTED) {
				continue;
			}
			if (chan->conf_len + len2 > sizeof(chan->conf_req)) {
				continue;
			}
			if (flags & L2CAP_CONF_FLAG_CONTINUATION) {
				continue;
			}

			unsigned char chan_buf[640];
			int chan_buflen = chan->conf_len + len2;
			int chan_buf_offset = 0;
			memcpy(chan_buf, chan->conf_req, chan->conf_len);
			memcpy(chan_buf + chan->conf_len, req->data, len2);
			int type, olen;
			unsigned long val;
			u16 mtu = L2CAP_DEFAULT_MTU;
			// printk("cmd->code=%d, srcChanID=%d\n", cmd->code, srcChanID);return 0;

			while (chan_buflen >= L2CAP_CONF_OPT_SIZE) {
				int tmp = l2cap_get_conf_opt2(chan_buf + chan_buf_offset, &type, &olen, &val);
				chan_buf_offset += tmp;
				chan_buflen 	-= tmp;
				if(type == L2CAP_CONF_MTU){
					if (olen != 2)
					mtu = val;

					/* Parameters for P Module */	
					mtuVal = mtu;
					/* Parameters for P Module */	

					/* All Parameters get */
					printk("srcChanID = %d, mtuVal = %d, can_putConf=%d", srcChanID, mtuVal, can_putConf);
					/* All Parameters get */
					break;
				}
			}
		}
		offsets += L2CAP_CMD_HDR_SIZE;
		skb_len -= L2CAP_CMD_HDR_SIZE;
	}

	return 0;
}




int minit(void)
{
	printk("Module inserted\n ");

	kp.pre_handler = kpb_pre_l2cap_recv_frame;
	kp.addr = (kprobe_opcode_t *)0xffffffffc089be60;

	kp2.pre_handler = kpb_pre_l2cap_sig_channel;
	kp2.addr = (kprobe_opcode_t *)0xffffffffc089ab40;

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
