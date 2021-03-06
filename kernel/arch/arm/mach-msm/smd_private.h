/* arch/arm/mach-msm/smd_private.h
 *
 * Copyright (C) 2007 Google, Inc.
 * Copyright (c) 2007-2010, Code Aurora Forum. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef _ARCH_ARM_MACH_MSM_MSM_SMD_PRIVATE_H_
#define _ARCH_ARM_MACH_MSM_MSM_SMD_PRIVATE_H_

#include <linux/types.h>
#include <linux/spinlock.h>

struct smem_heap_info {
	unsigned initialized;
	unsigned free_offset;
	unsigned heap_remaining;
	unsigned reserved;
};

struct smem_heap_entry {
	unsigned allocated;
	unsigned offset;
	unsigned size;
	unsigned reserved;
};

struct smem_proc_comm {
	unsigned command;
	unsigned status;
	unsigned data1;
	unsigned data2;
};

#define PC_APPS  0
#define PC_MODEM 1

#define VERSION_QDSP6     4
#define VERSION_APPS_SBL  6
#define VERSION_MODEM_SBL 7
#define VERSION_APPS      8
#define VERSION_MODEM     9
#define VERSION_DSPS      10

#define SMD_HEAP_SIZE 512

struct smem_shared {
	struct smem_proc_comm proc_comm[4];
	unsigned version[32];
	struct smem_heap_info heap_info;
	struct smem_heap_entry heap_toc[SMD_HEAP_SIZE];
};

#if defined(CONFIG_MSM_SMD_PKG4)
struct smsm_interrupt_info {
	uint32_t aArm_en_mask;
	uint32_t aArm_interrupts_pending;
	uint32_t aArm_wakeup_reason;
	uint32_t aArm_rpc_prog;
	uint32_t aArm_rpc_proc;
	char aArm_smd_port_name[20];
	uint32_t aArm_gpio_info;
};
#elif defined(CONFIG_MSM_SMD_PKG3)
struct smsm_interrupt_info {
  uint32_t aArm_en_mask;
  uint32_t aArm_interrupts_pending;
  uint32_t aArm_wakeup_reason;
};
#else
#error No SMD Package Specified; aborting
#endif

#if defined(CONFIG_MSM_N_WAY_SMSM)
enum {
	SMSM_APPS_STATE,
	SMSM_MODEM_STATE,
	SMSM_Q6_STATE,
	SMSM_APPS_DEM,
	SMSM_MODEM_DEM,
	SMSM_Q6_DEM,
	SMSM_POWER_MASTER_DEM,
	SMSM_TIME_MASTER_DEM,
	SMSM_NUM_ENTRIES,
};
#else
enum {
	SMSM_APPS_STATE = 1,
	SMSM_MODEM_STATE = 3,
	SMSM_NUM_ENTRIES,
};
#endif

enum {
	SMSM_APPS,
	SMSM_MODEM,
	SMSM_Q6,
	SMSM_NUM_HOSTS,
};

#define SZ_DIAG_ERR_MSG 0xC8
#define ID_DIAG_ERR_MSG SMEM_DIAG_ERR_MESSAGE
#define ID_SMD_CHANNELS SMEM_SMD_BASE_ID
#define ID_SHARED_STATE SMEM_SMSM_SHARED_STATE
#define ID_CH_ALLOC_TBL SMEM_CHANNEL_ALLOC_TBL

#define SMSM_INIT              0x00000001
#define SMSM_OSENTERED         0x00000002
#define SMSM_SMDWAIT           0x00000004
#define SMSM_SMDINIT           0x00000008
#define SMSM_RPCWAIT           0x00000010
#define SMSM_RPCINIT           0x00000020
#define SMSM_RESET             0x00000040
#define SMSM_RSA               0x00000080
#define SMSM_RUN               0x00000100
#define SMSM_PWRC              0x00000200
#define SMSM_TIMEWAIT          0x00000400
#define SMSM_TIMEINIT          0x00000800
#define SMSM_PWRC_EARLY_EXIT   0x00001000
#define SMSM_WFPI              0x00002000
#define SMSM_SLEEP             0x00004000
#define SMSM_SLEEPEXIT         0x00008000
#define SMSM_OEMSBL_RELEASE    0x00010000
#define SMSM_APPS_REBOOT       0x00020000
#define SMSM_SYSTEM_POWER_DOWN 0x00040000
#define SMSM_SYSTEM_REBOOT     0x00080000
#define SMSM_SYSTEM_DOWNLOAD   0x00100000
#define SMSM_PWRC_SUSPEND      0x00200000
#define SMSM_APPS_SHUTDOWN     0x00400000
#define SMSM_SMD_LOOPBACK      0x00800000
#define SMSM_RUN_QUIET         0x01000000
#define SMSM_MODEM_WAIT        0x02000000
#define SMSM_MODEM_BREAK       0x04000000
#define SMSM_MODEM_CONTINUE    0x08000000
#define SMSM_SYSTEM_REBOOT_USR 0x20000000
#define SMSM_SYSTEM_PWRDWN_USR 0x40000000
#define SMSM_UNKNOWN           0x80000000

#define SMSM_WKUP_REASON_RPC	0x00000001
#define SMSM_WKUP_REASON_INT	0x00000002
#define SMSM_WKUP_REASON_GPIO	0x00000004
#define SMSM_WKUP_REASON_TIMER	0x00000008
#define SMSM_WKUP_REASON_ALARM	0x00000010
#define SMSM_WKUP_REASON_RESET	0x00000020

void *smem_alloc(unsigned id, unsigned size);
void *smem_get_entry(unsigned id, unsigned *size);
int smsm_change_state(uint32_t smsm_entry,
		      uint32_t clear_mask, uint32_t set_mask);
int smsm_change_intr_mask(uint32_t smsm_entry,
			  uint32_t clear_mask, uint32_t set_mask);
int smsm_get_intr_mask(uint32_t smsm_entry, uint32_t *intr_mask);
uint32_t smsm_get_state(uint32_t smsm_entry);
void smsm_print_sleep_info(uint32_t sleep_delay, uint32_t sleep_limit,
	uint32_t irq_mask, uint32_t wakeup_reason, uint32_t pending_irqs);
void smsm_reset_modem(unsigned mode);
void smsm_reset_modem_cont(void);
void smd_sleep_exit(void);

#define SMEM_NUM_SMD_STREAM_CHANNELS        64
#define SMEM_NUM_SMD_BLOCK_CHANNELS         64

enum {
	/* fixed items */
	SMEM_PROC_COMM = 0,
	SMEM_HEAP_INFO,
	SMEM_ALLOCATION_TABLE,
	SMEM_VERSION_INFO,
	SMEM_HW_RESET_DETECT,
	SMEM_AARM_WARM_BOOT,
	SMEM_DIAG_ERR_MESSAGE,
	SMEM_SPINLOCK_ARRAY,
	SMEM_MEMORY_BARRIER_LOCATION,
	SMEM_FIXED_ITEM_LAST = SMEM_MEMORY_BARRIER_LOCATION,

	/* dynamic items */
	SMEM_AARM_PARTITION_TABLE,
	SMEM_AARM_BAD_BLOCK_TABLE,
	SMEM_RESERVE_BAD_BLOCKS,
	SMEM_WM_UUID,
	SMEM_CHANNEL_ALLOC_TBL,
	SMEM_SMD_BASE_ID,
	SMEM_SMEM_LOG_IDX = SMEM_SMD_BASE_ID + SMEM_NUM_SMD_STREAM_CHANNELS,
	SMEM_SMEM_LOG_EVENTS,
	SMEM_SMEM_STATIC_LOG_IDX,
	SMEM_SMEM_STATIC_LOG_EVENTS,
	SMEM_SMEM_SLOW_CLOCK_SYNC,
	SMEM_SMEM_SLOW_CLOCK_VALUE,
	SMEM_BIO_LED_BUF,
	SMEM_SMSM_SHARED_STATE,
	SMEM_SMSM_INT_INFO,
	SMEM_SMSM_SLEEP_DELAY,
	SMEM_SMSM_LIMIT_SLEEP,
	SMEM_SLEEP_POWER_COLLAPSE_DISABLED,
	SMEM_KEYPAD_KEYS_PRESSED,
	SMEM_KEYPAD_STATE_UPDATED,
	SMEM_KEYPAD_STATE_IDX,
	SMEM_GPIO_INT,
	SMEM_MDDI_LCD_IDX,
	SMEM_MDDI_HOST_DRIVER_STATE,
	SMEM_MDDI_LCD_DISP_STATE,
	SMEM_LCD_CUR_PANEL,
	SMEM_MARM_BOOT_SEGMENT_INFO,
	SMEM_AARM_BOOT_SEGMENT_INFO,
	SMEM_SLEEP_STATIC,
	SMEM_SCORPION_FREQUENCY,
	SMEM_SMD_PROFILES,
	SMEM_TSSC_BUSY,
	SMEM_HS_SUSPEND_FILTER_INFO,
	SMEM_BATT_INFO,
	SMEM_APPS_BOOT_MODE,
	SMEM_VERSION_FIRST,
	SMEM_VERSION_SMD = SMEM_VERSION_FIRST,
	SMEM_VERSION_LAST = SMEM_VERSION_FIRST + 24,
	SMEM_OSS_RRCASN1_BUF1,
	SMEM_OSS_RRCASN1_BUF2,
	SMEM_ID_VENDOR0,
	SMEM_ID_VENDOR1,
	SMEM_ID_VENDOR2,
	SMEM_HW_SW_BUILD_ID,
	SMEM_SMD_BLOCK_PORT_BASE_ID,
	SMEM_SMD_BLOCK_PORT_PROC0_HEAP = SMEM_SMD_BLOCK_PORT_BASE_ID +
						SMEM_NUM_SMD_BLOCK_CHANNELS,
	SMEM_SMD_BLOCK_PORT_PROC1_HEAP = SMEM_SMD_BLOCK_PORT_PROC0_HEAP +
						SMEM_NUM_SMD_BLOCK_CHANNELS,
	SMEM_I2C_MUTEX = SMEM_SMD_BLOCK_PORT_PROC1_HEAP +
						SMEM_NUM_SMD_BLOCK_CHANNELS,
	SMEM_SCLK_CONVERSION,
	SMEM_SMD_SMSM_INTR_MUX,
	SMEM_SMSM_CPU_INTR_MASK,
	SMEM_APPS_DEM_SLAVE_DATA,
	SMEM_QDSP6_DEM_SLAVE_DATA,
	SMEM_CLKREGIM_BSP,
	SMEM_CLKREGIM_SOURCES,
	SMEM_SMD_FIFO_BASE_ID,
	SMEM_USABLE_RAM_PARTITION_TABLE = SMEM_SMD_FIFO_BASE_ID +
						SMEM_NUM_SMD_STREAM_CHANNELS,
	SMEM_POWER_ON_STATUS_INFO,
	SMEM_DAL_AREA,
	SMEM_SMEM_LOG_POWER_IDX,
	SMEM_SMEM_LOG_POWER_WRAP,
	SMEM_SMEM_LOG_POWER_EVENTS,
	SMEM_ERR_CRASH_LOG,
	SMEM_ERR_F3_TRACE_LOG,
	SMEM_SMD_BRIDGE_ALLOC_TABLE,
	SMEM_SMDLITE_TABLE,
	SMEM_SD_IMG_UPGRADE_STATUS,
	SMEM_SEFS_INFO,
	SMEM_RESET_LOG,
	SMEM_RESET_LOG_SYMBOLS,
	SMEM_MEM_LAST = SMEM_RESET_LOG_SYMBOLS,
	SMEM_NUM_ITEMS,
};

enum {
	SMEM_APPS_Q6_SMSM = 3,
	SMEM_Q6_APPS_SMSM = 5,
	SMSM_NUM_INTR_MUX = 8,
};

#define SMD_SS_CLOSED            0x00000000
#define SMD_SS_OPENING           0x00000001
#define SMD_SS_OPENED            0x00000002
#define SMD_SS_FLUSHING          0x00000003
#define SMD_SS_CLOSING           0x00000004
#define SMD_SS_RESET             0x00000005
#define SMD_SS_RESET_OPENING     0x00000006

#define SMD_BUF_SIZE             8192
#define SMD_CHANNELS             64
#define SMD_HEADER_SIZE          20

/* 'type' field of smd_alloc_elm structure
 * has the following breakup
 * bits 0-7   -> channel type
 * bits 8-11  -> xfer type
 * bits 12-31 -> reserved
 */
struct smd_alloc_elm {
	char name[20];
	uint32_t cid;
	uint32_t type;
	uint32_t ref_count;
};

#define SMD_CHANNEL_TYPE(x) ((x) & 0x000000FF)
#define SMD_XFER_TYPE(x)    (((x) & 0x00000F00) >> 8)

struct smd_half_channel {
	unsigned state;
	unsigned char fDSR;
	unsigned char fCTS;
	unsigned char fCD;
	unsigned char fRI;
	unsigned char fHEAD;
	unsigned char fTAIL;
	unsigned char fSTATE;
	unsigned char fBLOCKREADINTR;
	unsigned tail;
	unsigned head;
};

extern spinlock_t smem_lock;


int smsm_check_for_modem_crash(void);
void *smem_find(unsigned id, unsigned size);
void *smem_get_entry(unsigned id, unsigned *size);
void smd_diag(void);

typedef struct
{
	uint32_t magic_num;
	uint32_t apps_boot_reason;

} acer_bootmode_id_type;

typedef enum
{
	ACER_AMSS_BOOT_IN_NORMAL,
	ACER_AMSS_BOOT_IN_AMSS_FTM,
	ACER_AMSS_BOOT_IN_OS_FTM,
	ACER_AMSS_BOOT_IN_CHARGING_ONLY,
	ACER_AMSS_BOOT_IN_AMSS_DOWNLOAD,
	ACER_AMSS_BOOT_IN_OS_USB_FTM,
	ACER_AMSS_BOOT_IN_OS_DOWNLOAD,
	ACER_AMSS_BOOT_IN_SDDL_AMSS,
	ACER_AMSS_BOOT_IN_SDDL_OS,
	ACER_AMSS_BOOT_IN_SDDL_DIFF,
	ACER_AMSS_BOOT_IN_AMSS_CRASH_REBOOT,
	ACER_AMSS_BOOT_IN_OS_CRASH_REBOOT,
	ACER_AMSS_BOOT_IN_FTM,
	ACER_AMSS_BOOT_IN_AMSS_DOWNLOAD_DISPLAY,
	ACER_AMSS_BOOT_IN_SDDL_AMSS_DISPLAY,
	ACER_AMSS_BOOT_IN_POWER_CUT,
	ACER_AMSS_BOOT_IN_SW_RESET,
	ACER_AMSS_BOOT_IN_HW_RESET,
	ACER_AMSS_BOOT_IN_EFS_FORMAT,
	ACER_AMSS_BOOT_IN_ARM9_FATAL_ERROR,
	ACER_AMSS_BOOT_IN_WDOG,
	ACER_AMSS_BOOT_IN_BATT_REMOVE,
	ACER_AMSS_BOOT_IN_PMIC_RTC,
	ACER_AMSS_BOOT_IN_LOW_BATT,
	ACER_AMSS_BOOT_IN_UNKOWN,
	ACER_AMSS_BOOT_IN_MAX=30,
	ACER_AMSS_BOOT_IN_AMSS_DOWNLOAD_ALL,
	ACER_AMSS_BOOT_IN_FORMAT_EFS,
	ACER_AMSS_BOOT_INVALID = 0x7FFFFFFF,
} acer_amss_boot_mode_t;

typedef enum
{
	ACER_UART_LOG_TO_UART1,
	ACER_UART_LOG_TO_UART3,
	ACER_UART_LOG_OFF,
	ACER_UART_LOG_INVALID = 0x7FFFFFFF,
} acer_uart_log_switch_t;

typedef enum
{
	ACER_BATT_TEMP_OK,			// Charger temperature is ok
	ACER_BATT_TEMP_ERROR_LV0,		// Disable charging, Power from Battery
	ACER_BATT_TEMP_ERROR_LV1,		// Disable charging, Power form AC/USB
	ACER_BATT_TEMP_ERROR_LV2,		// Charging current set 100 mA
	ACER_BATT_TEMP_INVALID = 0x7FFFFFFF,
} acer_batt_temp_info_t;

typedef enum
{
	ACER_CHARGER_TYPE_IS_AC,
	ACER_CHARGER_TYPE_IS_USB,
	ACER_CHARGER_TYPE_NO_CHARGER,
	ACER_CHARGER_TYPE_INVALID =  0x7FFFFFFF,
} acer_charger_type_t;

#if defined(CONFIG_MACH_ACER_A4)
typedef enum
{
	ACER_HW_VERSION_EVT,
	ACER_HW_VERSION_DVT1,
	ACER_HW_VERSION_DVT1_1,
	ACER_HW_VERSION_DVT2,
	ACER_HW_VERSION_DVT2_1,
	ACER_HW_VERSION_DVT3,
	ACER_HW_VERSION_PVT,
	ACER_HW_VERSION_UNKNOW,
	ACER_HW_VERSION_INVALID =  0x7FFFFFFF,
} acer_hw_version_t;
#elif defined(CONFIG_MACH_ACER_A5)
typedef enum
{
	ACER_HW_VERSION_EVT1,
	ACER_HW_VERSION_EVT2_1,
	ACER_HW_VERSION_DVT1,
	ACER_HW_VERSION_DVT2,
	ACER_HW_VERSION_DVT2_2_AND_PVT,
	ACER_HW_VERSION_PPR,
	ACER_HW_VERSION_UNKNOW,
	ACER_HW_VERSION_INVALID =  0x7FFFFFFF,
} acer_hw_version_t;
#else
#error No HW ID definition
#endif

typedef enum
{
	ACER_OS_NORMAL_MODE,
	ACER_OS_IDLE_MODE,
	ACER_OS_SUSPEND_MODE,
	ACER_OS_INVALID_MODE = 0x7FFFFFFF,
} acer_os_pwr_state_t;

typedef struct {
	acer_amss_boot_mode_t		acer_amss_boot_mode;
	acer_uart_log_switch_t		acer_uart_log_switch;
	acer_batt_temp_info_t		acer_batt_temp_info;
	acer_charger_type_t		acer_charger_type;
	acer_bootmode_id_type		acer_bootmode_info;
	char				acer_amss_sw_version[15];
	acer_hw_version_t		acer_hw_version;
	unsigned char			acer_batt_capacity;
	unsigned char			acer_factory_sn[32];
	acer_os_pwr_state_t		acer_os_pwr_state;
	unsigned char			acer_os_sw_version[64];
	unsigned char			acer_device_imei[9];
	unsigned char			acer_device_bt_mac[6];
} acer_smem_flag_t;

typedef struct {
	uint8_t  device_name[32];	/**< Device name string */
	uint32_t maker_id;		/**< Maker Identification */
	uint32_t device_id;		/**< Device Identification */
	uint32_t version_id;		/**< Device Version ID, if any */
	uint32_t block_count;		/**< Number of total blocks in device */
} flash_info_type;

typedef struct {
	flash_info_type	flash_info;
	uint32_t reserved[20];
} amss_boot_smem_flag_t;

#define Acer_MAX_QUEUE_BUFLEN 1024
#define Acer_MAX_QUEUE_SIZE 16
typedef struct
{
	unsigned short  type;
	unsigned short  X0;
	unsigned short  Y0;
	unsigned short  len;
	unsigned char buf[Acer_MAX_QUEUE_BUFLEN];
} acer_queue_buf_t;

typedef struct
{
	unsigned short  lock;
	unsigned short  write_p;
	unsigned short  read_p;
	acer_queue_buf_t queue[Acer_MAX_QUEUE_SIZE];
} acer_queue_t;

#endif
