#define WMI_ECHO_CMDID 1
#define WMI_ACCESS_MEMORY_CMDID 2
#define WMI_GET_FW_VERSION 3
#define WMI_DISABLE_INTR_CMDID 4
#define WMI_ENABLE_INTR_CMDID 5
#define WMI_ATH_INIT_CMDID 6
#define WMI_ABORT_TXQ_CMDID 7
#define WMI_STOP_TX_DMA_CMDID 8
#define WMI_ABORT_TX_DMA_CMDID 9
#define WMI_DRAIN_TXQ_CMDID 10
#define WMI_DRAIN_TXQ_ALL_CMDID 11
#define WMI_START_RECV_CMDID 12
#define WMI_STOP_RECV_CMDID 13
#define WMI_FLUSH_RECV_CMDID 14
#define WMI_SET_MODE_CMDID 15
#define WMI_NODE_CREATE_CMDID 16
#define WMI_NODE_REMOVE_CMDID 17
#define WMI_VAP_REMOVE_CMDID 18
#define WMI_VAP_CREATE_CMDID 19
#define WMI_REG_READ_CMDID 20
#define WMI_REG_WRITE_CMDID 21
#define WMI_RC_STATE_CHANGE_CMDID 22
#define WMI_RC_RATE_UPDATE_CMDID 23
#define WMI_TARGET_IC_UPDATE_CMDID 24
#define WMI_TX_AGGR_ENABLE_CMDID 25
#define WMI_TGT_DETACH_CMDID 26
#define WMI_NODE_UPDATE_CMDID 27
#define WMI_INT_STATS_CMDID 28
#define WMI_TX_STATS_CMDID 29
#define WMI_RX_STATS_CMDID 30
#define WMI_BITRATE_MASK_CMDID 31
#define WMI_REG_RMW_CMDID 32

#define AR_GPIO_IN_OUT 0x4048

#define ATH_HTC_RATE_MAX 30

struct reg_write {
    __be32 reg;
    __be32 val;
};

struct reg_rmw {
    __be32 reg;
    __be32 set;
    __be32 clr;
} __packed;

struct ath9k_htc_rateset {
    u8 rs_nrates;
    u8 rs_rates[ATH_HTC_RATE_MAX];
};

struct ath9k_htc_rate {
    struct ath9k_htc_rateset legacy_rates;
    struct ath9k_htc_rateset ht_rates;
} __packed;

struct ath9k_htc_target_rate {
    u8                    sta_index;
    u8                    isnew;
    __be32                capflags;
    struct ath9k_htc_rate rates;
};
