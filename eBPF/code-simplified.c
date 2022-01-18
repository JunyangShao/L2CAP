#include <uapi/linux/ptrace.h>
#include <linux/skbuff.h>
#include <linux/byteorder/little_endian.h>
#include <linux/types.h>
#include <linux/list.h>
#include <linux/workqueue.h>
#include <linux/device.h>
#include <linux/dcache.h>
#include <linux/mutex.h>
#include <linux/wait.h>
#include <linux/notifier.h>


struct l2cap_conn{
    void	*hcon;
    void	*hchan;	
    unsigned int	mtu;
};

struct l2cap_hdr {
	__le16     len;
	__le16     cid;
};

struct l2cap_cmd_hdr {
	__u8       code;
	__u8       ident;
	__le16     len;
} __packed;

int kprobe__l2cap_recv_frame(struct pt_regs *ctx, struct l2cap_conn *conn, void* skb)
{
	bpf_trace_printk("Hello, mtu = %d\n, conn = %p, skb=%p\n", conn->mtu, conn, skb);
	return 0;
}

