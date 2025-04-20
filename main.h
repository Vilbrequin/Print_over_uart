#define PORT_B_BASE_ADDRESS         0x4004A000UL
#define PORT_C_BASE_ADDRESS         0x4004B000UL
#define PORT_D_BASE_ADDRESS         0x4004C000UL

#define GPIOC_BASE_ADDRESS          0x400FF080UL
#define GPIOD_BASE_ADDRESS          0x400FF0C0UL
#define PDDR_OFFSET                 0x14UL
#define PIDR_OFFSET                 0x18UL
#define PDIR_OFFSET                 0x10UL
#define PTOR_OFFSET                 0x0CUL
#define PSOR_OFFSET                 0x04UL


#define GPIOC_PDDR                  (GPIOC_BASE_ADDRESS + PDDR_OFFSET)
#define GPIOD_PDDR                  (GPIOD_BASE_ADDRESS + PDDR_OFFSET)

#define GPIOC_PIDR                  (GPIOC_BASE_ADDRESS + PIDR_OFFSET)

#define GPIOC_PDIR                  (GPIOC_BASE_ADDRESS + PDIR_OFFSET)

#define GPIOD_PTOR                  (GPIOD_BASE_ADDRESS + PTOR_OFFSET)

#define GPIOD_PSOR                  (GPIOD_BASE_ADDRESS + PSOR_OFFSET)

#define PCC_BASE_ADDRESS            0x40065000UL
#define PCC_PORT_B_OFFSET           0x128UL
#define PCC_PORT_C_OFFSET           0x12CUL
#define PCC_PORT_D_OFFSET           0x130UL
#define PCC_FTM_1_OFFSET            0xE4UL

#define PCC_PORT_B                  (PCC_BASE_ADDRESS + PCC_PORT_B_OFFSET)
#define PCC_PORT_C                  (PCC_BASE_ADDRESS + PCC_PORT_C_OFFSET)
#define PCC_PORT_D                  (PCC_BASE_ADDRESS + PCC_PORT_D_OFFSET)
#define PCC_FTM_1                   (PCC_BASE_ADDRESS + PCC_FTM_1_OFFSET)

#define FTM_1_BASE_ADDRESS          0x40039000UL
#define SC_OFFSET                   0x0UL
#define CNT_OFFSET                  0x4UL
#define MOD_OFFSET                  0x8UL
#define CV_0_FTM_1_OFFSET           0x10UL
#define CHN_0_FTM_1_OFFSET          0xCUL
#define MODE_FTM_1_OFFSET           0x54UL
#define COMBINE_OFFSET              0x64UL

#define ISER_BASE_ADDRESS           0xE000E100UL
// TODO: verify later why it does not work with defined types
/* MemManage: The processor attempted an instruction fetch from a location that does not permit execution.
HardFault: A fault has been escalated to a hard fault.*/
// Standard Types
// typedef unsigned char           boolean;
// typedef unsigned char           uint8;
// typedef char                    int8;
// typedef unsigned short          uint16;
// typedef short                   int16;
// typedef unsigned long           uint32;
// typedef long                    int32;
// typedef unsigned long long      uint64;
// typedef long long               int64;
// typedef float                   float32;
// typedef double                  double64;


#define LPUART1_BASE    0x4006B000UL
#define LPUART1_STAT_OFFSET 0x14UL
#define LPUART1_DATA_OFFSET 0x1CUL
#define LPUART1_BAUD_OFFSET 0x10UL
#define LPUART1_CTRL_OFFSET 0x18UL

#define LPUART1_CTRL (LPUART1_BASE + LPUART1_CTRL_OFFSET)
#define LPUART1_BAUD (LPUART1_BASE + LPUART1_BAUD_OFFSET)
#define LPUART1_STAT (LPUART1_BASE + LPUART1_STAT_OFFSET)
#define LPUART1_DATA (LPUART1_BASE + LPUART1_DATA_OFFSET)

#define LPUART1_OFFSET  0x1ACUL
#define PCC_LPUART1     (PCC_BASE_ADDRESS + LPUART1_OFFSET)



#define SCG_BASE_ADDRESS 0x40064000
#define SCG_RCCR_OFFSET  0x14UL
#define SCG_CSR_OFFSET  0x10UL

#define SCG_SPLLCSR_OFFSET  0x600U
#define SCG_SPLLDIV_OFFSET  0x604UL
#define SCG_SPLLCFG_OFFSET  0x608UL

#define SCG_SOSCCSR_OFFSET  0x100U
#define SCG_SOSCDIV_OFFSET  0x104UL
#define SCG_SOSCCFG_OFFSET  0x108UL

#define SCG_CSR         (SCG_BASE_ADDRESS + SCG_CSR_OFFSET)
#define SCG_RCCR        (SCG_BASE_ADDRESS + SCG_RCCR_OFFSET)

#define SCG_SPLLCSR     (SCG_BASE_ADDRESS + SCG_SPLLCSR_OFFSET)
#define SCG_SPLLDIV     (SCG_BASE_ADDRESS + SCG_SPLLDIV_OFFSET)
#define SCG_SPLLCFG     (SCG_BASE_ADDRESS + SCG_SPLLCFG_OFFSET)

#define SCG_SOSCCSR     (SCG_BASE_ADDRESS + SCG_SOSCCSR_OFFSET)
#define SCG_SOSCDIV     (SCG_BASE_ADDRESS + SCG_SOSCDIV_OFFSET)
#define SCG_SOSCCFG     (SCG_BASE_ADDRESS + SCG_SOSCCFG_OFFSET)


#define WDOG_BASE_ADDRESS   0x40052000UL
#define WDOG_CNT_OFFSET          0x04UL
#define WDOG_TOVAL_OFFSET        0x08UL
#define WDOG_CS_OFFSET           0x00UL
#define CNT                 (WDOG_BASE_ADDRESS + WDOG_CNT_OFFSET)
#define TOVAL               (WDOG_BASE_ADDRESS + WDOG_TOVAL_OFFSET)
#define CS                  (WDOG_BASE_ADDRESS + WDOG_CS_OFFSET)


#define SCG_SOSCCSR_SOSCVLD_MASK                 0x1000000u

#define SCG_SPLLCSR_SPLLVLD_MASK                 0x1000000u

#define SCG_CSR_SCS_MASK                         0xF000000u
#define SCG_CSR_SCS_SHIFT                        24u


typedef int UARTError;
