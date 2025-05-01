#ifndef S32K142_REG_H_
#define S32K142_REG_H_

// PCC PERIPHERAL
#define PCC_BASE_ADDRESS                0x40065000UL
#define PCC_PORTC_OFFSET                0x12CUL
#define PCC_PORTD_OFFSET                0x130UL
#define PCC_FTM3_OFFSET                 0x98UL
#define PCC_LPUART1_OFFSET              0x1ACUL

#define PCC_PORTC                       (PCC_BASE_ADDRESS + PCC_PORTC_OFFSET)
#define PCC_PORTD                       (PCC_BASE_ADDRESS + PCC_PORTD_OFFSET)
#define PCC_FTM3                        (PCC_BASE_ADDRESS + PCC_FTM3_OFFSET)
#define PCC_LPUART1                     (PCC_BASE_ADDRESS + PCC_LPUART1_OFFSET)

// PCC Masks
#define CGC_MASK                        (1 << 30)
#define PCS_MASK                        (7 << 24)


// PORT PERIPHERAL
#define PORT_C_BASE_ADDRESS             0x4004B000UL
#define PORT_D_BASE_ADDRESS             0x4004C000UL

// PORT MACRO FUNCTION
#define PCR_OFFSET(pin)                 (((pin) * 0x04UL))

// PORT Masks
#define MUX_MASK                        (0x7 << 8)


// GPIO PERIPHERAL
#define GPIOC_BASE_ADDRESS              0x400FF080UL
#define GPIOD_BASE_ADDRESS              0x400FF0C0UL
#define PDDR_OFFSET                     0x14UL
#define PIDR_OFFSET                     0x18UL
#define PDIR_OFFSET                     0x10UL
#define PTOR_OFFSET                     0x0CUL
#define PSOR_OFFSET                     0x04UL

#define GPIOC_PDDR                      (GPIOC_BASE_ADDRESS + PDDR_OFFSET)
#define GPIOD_PDDR                      (GPIOD_BASE_ADDRESS + PDDR_OFFSET)
#define GPIOC_PIDR                      (GPIOC_BASE_ADDRESS + PIDR_OFFSET)
#define GPIOC_PDIR                      (GPIOC_BASE_ADDRESS + PDIR_OFFSET)
#define GPIOD_PTOR                      (GPIOD_BASE_ADDRESS + PTOR_OFFSET)
#define GPIOD_PSOR                      (GPIOD_BASE_ADDRESS + PSOR_OFFSET)

// LPUART1 PERIPHERAL
#define LPUART1_BASE_ADDRESS            0x4006B000UL
#define LPUART1_STAT_OFFSET             0x14UL
#define LPUART1_DATA_OFFSET             0x1CUL
#define LPUART1_BAUD_OFFSET             0x10UL
#define LPUART1_CTRL_OFFSET             0x18UL

#define LPUART1_STAT                    (LPUART1_BASE_ADDRESS + LPUART1_STAT_OFFSET)
#define LPUART1_DATA                    (LPUART1_BASE_ADDRESS + LPUART1_DATA_OFFSET)
#define LPUART1_BAUD                    (LPUART1_BASE_ADDRESS + LPUART1_BAUD_OFFSET)
#define LPUART1_CTRL                    (LPUART1_BASE_ADDRESS + LPUART1_CTRL_OFFSET)

// LPUART1 Masks
#define LPUART1_CTRL_TE_RE              (0x3UL << 8)
#define LPUART1_STAT_TDRE               (1 << 23)

// FTM3 PERIPHERAL
#define FTM3_BASE_ADDRESS               0x40026000UL
#define FTM3_SC_OFFSET                  0x0UL
#define FTM3_CNT_OFFSET                 0x4UL
#define FTM3_MOD_OFFSET                 0x8UL
#define FTM3_MODE_OFFSET                0x54UL
#define FTM3_COMBINE_OFFSET             0x64UL

#define FTM3_SC                         (FTM3_BASE_ADDRESS + FTM3_SC_OFFSET)
#define FTM3_CNT                        (FTM3_BASE_ADDRESS + FTM3_CNT_OFFSET)
#define FTM3_MOD                        (FTM3_BASE_ADDRESS + FTM3_MOD_OFFSET)
#define FTM3_MODE                       (FTM3_BASE_ADDRESS + FTM3_MODE_OFFSET)
#define FTM3_COMBINE                    (FTM3_BASE_ADDRESS + FTM3_COMBINE_OFFSET)

// FTM3 MACRO FUNCTIONS
#define CnSC_OFFSET(channel)            (0xCUL + (channel * 0x8UL))
#define CnV_OFFSET(channle)             (0x10UL + (channel * 0x8UL))

// FTM3 MACROS
#define SC_CLK_MASK                     (3 << 3)
#define SC_PS                           (7 << 0)
#define SC_CPWMS                        (1 << 5)
#define SC_TOIE                         (1 << 8)
#define SC_TOF                          (1 << 9)
#define MODE_WPDIS_MASK                 (1 << 2)
#define COMBINE_COMBINE3_MASK           (1 << 24)
#define COMBINE_DECAPEN3_MASK           (1 << 26)
#define COMBINE_MCOMBINE3_MASK          (1 << 31)
#define CH6_SC_MSB_MSA_MASK             (3 << 4)
#define CH6_SC_ELSB_ELSA_MASK           (3 << 2)


// SCG PERIPHERAL
#define SCG_BASE_ADDRESS                0x40064000UL
#define SCG_RCCR_OFFSET                 0x14UL
#define SCG_CSR_OFFSET                  0x10UL
#define SCG_SPLLCSR_OFFSET              0x600U
#define SCG_SPLLDIV_OFFSET              0x604UL
#define SCG_SPLLCFG_OFFSET              0x608UL
#define SCG_SOSCCSR_OFFSET              0x100U
#define SCG_SOSCDIV_OFFSET              0x104UL
#define SCG_SOSCCFG_OFFSET              0x108UL

#define SCG_RCCR                        (SCG_BASE_ADDRESS + SCG_RCCR_OFFSET)
#define SCG_CSR                         (SCG_BASE_ADDRESS + SCG_CSR_OFFSET)
#define SCG_SPLLCSR                     (SCG_BASE_ADDRESS + SCG_SPLLCSR_OFFSET)
#define SCG_SPLLDIV                     (SCG_BASE_ADDRESS + SCG_SPLLDIV_OFFSET)
#define SCG_SPLLCFG                     (SCG_BASE_ADDRESS + SCG_SPLLCFG_OFFSET)
#define SCG_SOSCCSR                     (SCG_BASE_ADDRESS + SCG_SOSCCSR_OFFSET)
#define SCG_SOSCDIV                     (SCG_BASE_ADDRESS + SCG_SOSCDIV_OFFSET)
#define SCG_SOSCCFG                     (SCG_BASE_ADDRESS + SCG_SOSCCFG_OFFSET)

// SCG Masks
#define SCG_VLD_MASK                    0x1000000UL
#define SCG_SPLLCSR_SPLLVLD_MASK        0x1000000UL
#define SCG_CSR_SCS_MASK                0xF000000UL
#define SCG_CSR_SCS_SHIFT               24UL
#define SCG_EN_MASK                     (1 << 0)
#define SCG_LK_MASK                     (1 << 23)
#define SCG_DIV1_MASK                   (7 << 0)
#define SCG_DIV2_MASK                   (7 << 8)
                  


// WDOG PERIPHERAL
#define WDOG_BASE_ADDRESS               0x40052000UL
#define WDOG_CNT_OFFSET                 0x04UL
#define WDOG_TOVAL_OFFSET               0x08UL
#define WDOG_CS_OFFSET                  0x00UL
#define WDOG_CNT                        (WDOG_BASE_ADDRESS + WDOG_CNT_OFFSET)
#define WDOG_TOVAL                      (WDOG_BASE_ADDRESS + WDOG_TOVAL_OFFSET)
#define WDOG_CS                         (WDOG_BASE_ADDRESS + WDOG_CS_OFFSET)


// NVIC ISER
#define ISER_BASE_ADDRESS               0xE000E100UL

#endif /* S32K142_REG_H_ */