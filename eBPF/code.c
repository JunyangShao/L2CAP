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
    struct hci_conn	*hcon;
    void	*hchan;	
    unsigned int	mtu;
};

struct l2cap_hdr {
__le16     len;
__le16     cid;
};

typedef struct {
	__u8 b[6];
} __packed bdaddr_t;

#define HCI_MAX_PAGES	3
#define HCI_MAX_AD_LENGTH		31

enum conn_reasons {
	CONN_REASON_PAIR_DEVICE,
	CONN_REASON_L2CAP_CHAN,
	CONN_REASON_SCO_CONNECT,
};

enum suspended_state {
	BT_RUNNING = 0,
	BT_SUSPEND_DISCONNECT,
	BT_SUSPEND_CONFIGURE_WAKE,
};

struct hci_conn {
	struct list_head list;

	atomic_t	refcnt;

	bdaddr_t	dst;
	__u8		dst_type;
	bdaddr_t	src;
	__u8		src_type;
	bdaddr_t	init_addr;
	__u8		init_addr_type;
	bdaddr_t	resp_addr;
	__u8		resp_addr_type;
	__u16		handle;
	__u16		state;
	__u8		mode;
	__u8		type;
	__u8		role;
	bool		out;
	__u8		attempt;
	__u8		dev_class[3];
	__u8		features[HCI_MAX_PAGES][8];
	__u16		pkt_type;
	__u16		link_policy;
	__u8		key_type;
	__u8		auth_type;
	__u8		sec_level;
	__u8		pending_sec_level;
	__u8		pin_length;
	__u8		enc_key_size;
	__u8		io_capability;
	__u32		passkey_notify;
	__u8		passkey_entered;
	__u16		disc_timeout;
	__u16		conn_timeout;
	__u16		setting;
	__u16		auth_payload_timeout;
	__u16		le_conn_min_interval;
	__u16		le_conn_max_interval;
	__u16		le_conn_interval;
	__u16		le_conn_latency;
	__u16		le_supv_timeout;
	__u8		le_adv_data[HCI_MAX_AD_LENGTH];
	__u8		le_adv_data_len;
	__u8		le_tx_phy;
	__u8		le_rx_phy;
	__s8		rssi;
	__s8		tx_power;
	__s8		max_tx_power;
	unsigned long	flags;

	enum conn_reasons conn_reason;

	__u32		clock;
	__u16		clock_accuracy;

	unsigned long	conn_info_timestamp;

	__u8		remote_cap;
	__u8		remote_auth;
	__u8		remote_id;

	unsigned int	sent;

	struct sk_buff_head data_q;
	struct list_head chan_list;

	struct delayed_work disc_work;
	struct delayed_work auto_accept_work;
	struct delayed_work idle_work;
	struct delayed_work le_conn_timeout;
	struct work_struct  le_scan_cleanup;

	struct device	dev;
	struct dentry	*debugfs;

	struct hci_dev	*hdev;
	void		*l2cap_data;
	void		*sco_data;
};

#define HCI_MAX_AMP_ASSOC_SIZE	672

struct amp_assoc {
	__u16	len;
	__u16	offset;
	__u16	rem_len;
	__u16	len_so_far;
	__u8	data[HCI_MAX_AMP_ASSOC_SIZE];
};

struct discovery_state {
	int			type;
	enum {
		DISCOVERY_STOPPED,
		DISCOVERY_STARTING,
		DISCOVERY_FINDING,
		DISCOVERY_RESOLVING,
		DISCOVERY_STOPPING,
	} state;
	struct list_head	all;	/* All devices found during inquiry */
	struct list_head	unknown;	/* Name state not known */
	struct list_head	resolve;	/* Name needs to be resolved */
	__u32			timestamp;
	bdaddr_t		last_adv_addr;
	u8			last_adv_addr_type;
	s8			last_adv_rssi;
	u32			last_adv_flags;
	u8			last_adv_data[HCI_MAX_AD_LENGTH];
	u8			last_adv_data_len;
	bool			report_invalid_rssi;
	bool			result_filtering;
	bool			limited;
	s8			rssi;
	u16			uuid_count;
	u8			(*uuids)[16];
	unsigned long		scan_start;
	unsigned long		scan_duration;
};

struct hci_conn_hash {
	struct list_head list;
	unsigned int     acl_num;
	unsigned int     amp_num;
	unsigned int     sco_num;
	unsigned int     le_num;
	unsigned int     le_num_slave;
};

#define HCI_MAX_NAME_LENGTH		248
#define HCI_MAX_SHORT_NAME_LENGTH	10
#define HCI_MAX_EIR_LENGTH		240

enum suspend_tasks {
	SUSPEND_PAUSE_DISCOVERY,
	SUSPEND_UNPAUSE_DISCOVERY,

	SUSPEND_PAUSE_ADVERTISING,
	SUSPEND_UNPAUSE_ADVERTISING,

	SUSPEND_SCAN_DISABLE,
	SUSPEND_SCAN_ENABLE,
	SUSPEND_DISCONNECTING,

	SUSPEND_POWERING_DOWN,

	SUSPEND_PREPARE_NOTIFIER,
	__SUSPEND_NUM_TASKS
};

struct hci_dev {
	struct list_head list;
	struct mutex	lock;

	char		name[8];
	unsigned long	flags;
	__u16		id;
	__u8		bus;
	__u8		dev_type;
	bdaddr_t	bdaddr;
	bdaddr_t	setup_addr;
	bdaddr_t	public_addr;
	bdaddr_t	random_addr;
	bdaddr_t	static_addr;
	__u8		adv_addr_type;
	__u8		dev_name[HCI_MAX_NAME_LENGTH];
	__u8		short_name[HCI_MAX_SHORT_NAME_LENGTH];
	__u8		eir[HCI_MAX_EIR_LENGTH];
	__u16		appearance;
	__u8		dev_class[3];
	__u8		major_class;
	__u8		minor_class;
	__u8		max_page;
	__u8		features[HCI_MAX_PAGES][8];
	__u8		le_features[8];
	__u8		le_white_list_size;
	__u8		le_resolv_list_size;
	__u8		le_num_of_adv_sets;
	__u8		le_states[8];
	__u8		commands[64];
	__u8		hci_ver;
	__u16		hci_rev;
	__u8		lmp_ver;
	__u16		manufacturer;
	__u16		lmp_subver;
	__u16		voice_setting;
	__u8		num_iac;
	__u8		stored_max_keys;
	__u8		stored_num_keys;
	__u8		io_capability;
	__s8		inq_tx_power;
	__u8		err_data_reporting;
	__u16		page_scan_interval;
	__u16		page_scan_window;
	__u8		page_scan_type;
	__u8		le_adv_channel_map;
	__u16		le_adv_min_interval;
	__u16		le_adv_max_interval;
	__u8		le_scan_type;
	__u16		le_scan_interval;
	__u16		le_scan_window;
	__u16		le_scan_int_suspend;
	__u16		le_scan_window_suspend;
	__u16		le_scan_int_discovery;
	__u16		le_scan_window_discovery;
	__u16		le_scan_int_adv_monitor;
	__u16		le_scan_window_adv_monitor;
	__u16		le_scan_int_connect;
	__u16		le_scan_window_connect;
	__u16		le_conn_min_interval;
	__u16		le_conn_max_interval;
	__u16		le_conn_latency;
	__u16		le_supv_timeout;
	__u16		le_def_tx_len;
	__u16		le_def_tx_time;
	__u16		le_max_tx_len;
	__u16		le_max_tx_time;
	__u16		le_max_rx_len;
	__u16		le_max_rx_time;
	__u8		le_max_key_size;
	__u8		le_min_key_size;
	__u16		discov_interleaved_timeout;
	__u16		conn_info_min_age;
	__u16		conn_info_max_age;
	__u16		auth_payload_timeout;
	__u8		min_enc_key_size;
	__u8		max_enc_key_size;
	__u8		pairing_opts;
	__u8		ssp_debug_mode;
	__u8		hw_error_code;
	__u32		clock;
	__u16		advmon_allowlist_duration;
	__u16		advmon_no_filter_duration;
	__u8		enable_advmon_interleave_scan;

	__u16		devid_source;
	__u16		devid_vendor;
	__u16		devid_product;
	__u16		devid_version;

	__u8		def_page_scan_type;
	__u16		def_page_scan_int;
	__u16		def_page_scan_window;
	__u8		def_inq_scan_type;
	__u16		def_inq_scan_int;
	__u16		def_inq_scan_window;
	__u16		def_br_lsto;
	__u16		def_page_timeout;
	__u16		def_multi_adv_rotation_duration;
	__u16		def_le_autoconnect_timeout;
	__s8		min_le_tx_power;
	__s8		max_le_tx_power;

	__u16		pkt_type;
	__u16		esco_type;
	__u16		link_policy;
	__u16		link_mode;

	__u32		idle_timeout;
	__u16		sniff_min_interval;
	__u16		sniff_max_interval;

	__u8		amp_status;
	__u32		amp_total_bw;
	__u32		amp_max_bw;
	__u32		amp_min_latency;
	__u32		amp_max_pdu;
	__u8		amp_type;
	__u16		amp_pal_cap;
	__u16		amp_assoc_size;
	__u32		amp_max_flush_to;
	__u32		amp_be_flush_to;

	struct amp_assoc	loc_assoc;

	__u8		flow_ctl_mode;

	unsigned int	auto_accept_delay;

	unsigned long	quirks;

	atomic_t	cmd_cnt;
	unsigned int	acl_cnt;
	unsigned int	sco_cnt;
	unsigned int	le_cnt;

	unsigned int	acl_mtu;
	unsigned int	sco_mtu;
	unsigned int	le_mtu;
	unsigned int	acl_pkts;
	unsigned int	sco_pkts;
	unsigned int	le_pkts;

	__u16		block_len;
	__u16		block_mtu;
	__u16		num_blocks;
	__u16		block_cnt;

	unsigned long	acl_last_tx;
	unsigned long	sco_last_tx;
	unsigned long	le_last_tx;

	__u8		le_tx_def_phys;
	__u8		le_rx_def_phys;

	struct workqueue_struct	*workqueue;
	struct workqueue_struct	*req_workqueue;

	struct work_struct	power_on;
	struct delayed_work	power_off;
	struct work_struct	error_reset;

	__u16			discov_timeout;
	struct delayed_work	discov_off;

	struct delayed_work	service_cache;

	struct delayed_work	cmd_timer;

	struct work_struct	rx_work;
	struct work_struct	cmd_work;
	struct work_struct	tx_work;

	struct work_struct	discov_update;
	struct work_struct	bg_scan_update;
	struct work_struct	scan_update;
	struct work_struct	connectable_update;
	struct work_struct	discoverable_update;
	struct delayed_work	le_scan_disable;
	struct delayed_work	le_scan_restart;

	struct sk_buff_head	rx_q;
	struct sk_buff_head	raw_q;
	struct sk_buff_head	cmd_q;

	struct sk_buff		*sent_cmd;

	struct mutex		req_lock;
	wait_queue_head_t	req_wait_q;
	__u32			req_status;
	__u32			req_result;
	struct sk_buff		*req_skb;

	void			*smp_data;
	void			*smp_bredr_data;

	struct discovery_state	discovery;

	int			discovery_old_state;
	bool			discovery_paused;
	int			advertising_old_state;
	bool			advertising_paused;

	struct notifier_block	suspend_notifier;
	struct work_struct	suspend_prepare;
	enum suspended_state	suspend_state_next;
	enum suspended_state	suspend_state;
	bool			scanning_paused;
	bool			suspended;
	u8			wake_reason;
	bdaddr_t		wake_addr;
	u8			wake_addr_type;

	wait_queue_head_t	suspend_wait_q;
	DECLARE_BITMAP(suspend_tasks, __SUSPEND_NUM_TASKS);

	struct hci_conn_hash	conn_hash;

	struct list_head	mgmt_pending;
	struct list_head	blacklist;
};

struct l2cap_cmd_hdr {
	__u8       code;
	__u8       ident;
	__le16     len;
} __packed;

/* Connection and socket states */
enum {
	BT_CONNECTED = 1, /* Equal to TCP_ESTABLISHED to make net code happy */
	BT_OPEN,
	BT_BOUND,
	BT_LISTEN,
	BT_CONNECT,
	BT_CONNECT2,
	BT_CONFIG,
	BT_DISCONN,
	BT_CLOSED
};

#define L2CAP_HDR_SIZE		4
#define L2CAP_CID_SIGNALING	0x0001

#define LE_LINK		0x80

#define BDADDR_BREDR		0x00
#define BDADDR_LE_PUBLIC	0x01
#define BDADDR_LE_RANDOM	0x02

#define ADDR_LE_DEV_PUBLIC		0x00

struct bdaddr_list {
	struct list_head list;
	bdaddr_t bdaddr;
	u8 bdaddr_type;
};


#define my_skb_pull

BPF_ARRAY(skb_array, struct sk_buff, 1);
BPF_ARRAY(lh_array, struct l2cap_hdr, 1);
BPF_ARRAY(hcon_array, struct hci_conn, 1);

BPF_ARRAY(hdev_array, struct hci_dev, 1);
BPF_ARRAY(tmp_bdaddr_list_array, struct bdaddr_list, 1);

#define my_list_next_entry(pos, member) \
	my_list_entry((pos)->member.next, typeof(*(pos)), member)

#define my_list_first_entry(ptr, type, member) \
	my_list_entry((ptr)->next, type, member)

#define my_list_entry(ptr, type, member) \
	my_container_of(ptr, type, member)

#define my_container_of(ptr, type, member) ({			\
const typeof(((type *)0)->member) * __mptr = (ptr);	\
(type *)((char *)__mptr - offsetof(type, member)); })

#define my_list_for_each_entry(pos, head, member)				\
	for (bpf_probe_read_kernel(pos, sizeof(struct bdaddr_list), my_list_first_entry(head, typeof(*pos), member));	\
	     !list_entry_is_head(pos, head, member);			\
	     bpf_probe_read_kernel(pos, sizeof(struct bdaddr_list), my_list_next_entry(pos, member)))

static inline __attribute__((always_inline)) int bacmp(const bdaddr_t *ba1, const bdaddr_t *ba2)
{
	return memcmp(ba1, ba2, sizeof(bdaddr_t));
}

static inline __attribute__((always_inline)) struct bdaddr_list *hci_bdaddr_list_lookup(struct list_head *bdaddr_list,
					 bdaddr_t *bdaddr, u8 type)
{
    int key = 0;
	struct bdaddr_list *b = tmp_bdaddr_list_array.lookup(&key);

    if(!b) return NULL;

	my_list_for_each_entry(b, bdaddr_list, list) {
		if (!bacmp(&b->bdaddr, bdaddr) && b->bdaddr_type == type)
			return b;
	}

	return NULL;
}

#define READY4RELEASE1
#define READY4RELEASE2

int kprobe__l2cap_recv_frame(struct pt_regs *ctx, struct l2cap_conn *conn/*, struct sk_buff *skb_orig*/)
{
#ifdef READY4RELEASE1
#else
    int key = 0;
    struct sk_buff* skb = skb_array.lookup(&key);
    struct l2cap_hdr* lh = lh_array.lookup(&key);
    struct hci_conn* hcon = hcon_array.lookup(&key);
	struct hci_dev* hdev = hdev_array.lookup(&key);
    if(skb){
        bpf_probe_read_kernel(skb, sizeof(struct sk_buff), (void* ) skb_orig);
        if(lh){
            bpf_probe_read_kernel(lh, sizeof(struct l2cap_hdr), (void *) skb->data);
        }
    }
    if(hcon){
        bpf_probe_read_kernel(hcon, sizeof(struct hci_conn), (void *) conn->hcon);   
    }
	if(hdev){
		bpf_probe_read_kernel(hdev, sizeof(struct hci_dev), (void *) hcon->hdev);
	}
	u16 cid;
    u16 len;
	__le16 psm;
	if (hcon->state != BT_CONNECTED) {
		return 0;
	}
	if(!skb || !lh || !hcon || !hdev){
        return 0;
    }


    /*
        -Findings-
        Reading from the sk_buff will create verification errors.
        I think a better workaround will be reading everything out of it and pass it to the user space :')
        Will be a TODO
    */
	// skb_pull(skb, L2CAP_HDR_SIZE);
	
    if(skb->len < L2CAP_HDR_SIZE)
        return 0;

	cid = __le16_to_cpu(lh->cid);
	len = __le16_to_cpu(lh->len);

    unsigned int skb_len = skb->len - L2CAP_HDR_SIZE;

	if (len != skb_len) {
		return 0;
	}


    // replace func call with plain codes.
    struct bdaddr_list * ret1;
    u8 ret2;
	u8 link_type = hcon->type;
	u8 bdaddr_type = hcon->dst_type;
	if (link_type == LE_LINK) {
		if (bdaddr_type == ADDR_LE_DEV_PUBLIC)
			ret2 =  BDADDR_LE_PUBLIC;
		else
			ret2 = BDADDR_LE_RANDOM;
	}
	else
		ret2 = BDADDR_BREDR;

	ret1 = hci_bdaddr_list_lookup(&hdev->blacklist, &hcon->dst,
		ret2);
	if (hcon->type == LE_LINK && ret1) {
		return 0;
	}


	switch (cid) {
	case L2CAP_CID_SIGNALING:
        // pass {conn,skb} to User Space here
		break;
    	default:
        break;
	}
#endif
#ifdef READY4RELEASE2
    int key = 0;
    struct sk_buff* skb = skb_array.lookup(&key);
    struct l2cap_hdr* lh = lh_array.lookup(&key);
    struct hci_conn* hcon = hcon_array.lookup(&key);
    if(skb){
        bpf_probe_read_kernel(skb, sizeof(struct sk_buff), (void* ) skb_orig);
        if(lh){
            bpf_probe_read_kernel(lh, sizeof(struct l2cap_hdr), (void *) skb->data);
        }
    }
	if(hcon){
        bpf_probe_read_kernel(hcon, sizeof(struct hci_conn), (void *) conn->hcon);   
    }
	u16 cid;
	cid = __le16_to_cpu(lh->cid);
	switch (cid) {
		case L2CAP_CID_SIGNALING:
		{
			struct l2cap_cmd_hdr *cmd;
		}
	}
#endif
    return 0;
}

