#include "S32K142_Regs.h"
#include "uart.h"
#include "clock_config.h"
#include "std_types.h"
#include <ewl_misra_types.h>
#include <stdio.h>

#define PTC07               0x07UL // LPUART1_TX
#define LPUART1_TX_MASK     (0x02 << 8)

void port_init(void)
{
    volatile uint32 *pcc_port_c = (volatile uint32 *)(PCC_PORTC);
    volatile uint32 *port_c_pcr_7 = (volatile uint32 *)((uint8 *)PORT_C_BASE_ADDRESS + PCR_OFFSET(PTC07));

    // Enable the Port C Clock (via Clock Gate Control Bit)
    *pcc_port_c |= CGC_MASK;

    // Set the PTC07 as LPUART1 ALT FUNC
    *port_c_pcr_7 &= ~MUX_MASK;       // clear MUX[10:8]
    *port_c_pcr_7 |= LPUART1_TX_MASK; // Set MUX[10:8] = 0b010
}

void WDOG_disable(void)
{
    volatile uint32* cnt = (volatile uint32*)(WDOG_CNT);
    volatile uint32* toval = (volatile uint32*)(WDOG_TOVAL);
    volatile uint32* cs = (volatile uint32*)(WDOG_CS);

    *cnt = 0xD928C520;   /* Unlock watchdog */
    *toval = 0x0000FFFF; /* Maximum timeout value */
    *cs = 0x00002100;    /* Disable watchdog */
}

void delay()
{
    long long int i = 100000;
    while (i > 0)
    {
        i--;
    }
}
__attribute__((weak)) int_t __write_console(__file_handle handle, uchar_t *buffer, size_t *count) {
    for(size_t i = 0; i < *count; i++) {
        send_char(buffer[i]);
    }
    return *count;
}

int main(){
    WDOG_disable();
    SOSC_init_8MHz();
    SPLL_init_160MHz();
    NormalRUNmode_80MHz();
    port_init();
    config_uart();
    const char* msg = "Houssame !\r\n";
    send_str(msg, 10);
    while (1)
    {
        send_str(msg, 10);
        delay(1000);
    }
    while(1){}
    return 0;
}