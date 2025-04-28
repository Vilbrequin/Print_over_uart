#include "uart.h"
#include "std_types.h"
#include "S32K142_Regs.h"

#define TDRE 23UL

void config_uart(void)
{
    volatile uint32* pcc_lpuart1 = (volatile uint32*)(PCC_LPUART1);
    volatile uint32 *lpuart1_ctrl = (volatile uint32 *)(LPUART1_CTRL);
    volatile uint32 *lpuart1_baud = (volatile uint32 *)(LPUART1_BAUD);

    // Enable the LPUART1 Module and select the SOSCDIV2 as function clock
    *pcc_lpuart1 &= ~(CGC_MASK | PCS_MASK);
    *pcc_lpuart1 |= (CGC_MASK | (1 << 24)); // CLock option 1 is SOSCDIV2 (see Table 27-9. Peripheral module clocking)

    // Diable Transmitter and receiver to write set the Baud rate correctly
    *lpuart1_ctrl &= ~LPUART1_CTRL_TE_RE;

    // Set the Baud Rate
    // the functioanl clock (baud clock) is SIRCDIV2_CLK = 8MHz
    // SBR[12:0] is calculated using this formula: "baud clock / ((OSR+1) × SBR) = desired baud rate"
    *lpuart1_baud &= ~(0xFFF << 0);
    *lpuart1_baud |= (0x34 << 0);

    // Enable TE & RE
    *lpuart1_ctrl |= (1 << 19);
}

void send_char(const char c)
{
    volatile uint32 *lpuart1_stat = (volatile uint32 *)(LPUART1_STAT);
    volatile uint32 *lpuart1_data = (volatile uint32 *)(LPUART1_DATA);

    // wait until the datat register is empty
    while(!(BIT_IS_SET(*lpuart1_stat, 23)));

    // write the character into the data register
    *lpuart1_data = c;
}

void send_str(const char *str, int size)
{
    for (int i = 0; i < size; i++)
    {
        send_char(*str++);
    }
}