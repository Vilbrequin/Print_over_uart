// SW2 -> input (PTC 12)
// Capture that input then Red LED ON (PTD 16)
// After that when SW2 Clicked wait until the next Click then RED LED ON
// Search a way how to print into screen !
#include "main.h"
#include <stdint.h>
#include <stdio.h>
#include <ewl_misra_types.h>

#define PCR_OFFSET(pin) (((pin) * 0x04))
#define CnSC_OFFSET(channel) (0x0C + (channel * 0x08))
#define IS_BIT_SET(val, bit) (((val) & (1 << (bit))) != 0)

#define PCC_CGC_MASK ( 1 << 30)

#define PTC12 12UL // SW2
#define PTD15 15UL // RED LED
#define PTB02 02UL // FTM1_CH0
#define PTC07 07UL // LPUART1_TX

#define CH0 0U

#define PORTC_IRQn  61
static void NVIC_EnableIRQ(uint8_t IRQn)
{
    volatile uint32_t* NVIC_ISER = (volatile uint32_t*)((uint8_t*)ISER_BASE_ADDRESS + (4 * (IRQn / 32)));
    
    *NVIC_ISER |= (1 << (IRQn % 32));
}
void WDOG_disable (void)
{
    volatile uint32_t* cnt = (volatile uint32_t*)(CNT);
    volatile uint32_t* toval = (volatile uint32_t*)(TOVAL);
    volatile uint32_t* cs = (volatile uint32_t*)(CS);
    
  *cnt=0xD928C520;     /* Unlock watchdog */
  *toval=0x0000FFFF;   /* Maximum timeout value */
  *cs = 0x00002100;    /* Disable watchdog */
}
void SOSC_init_8MHz(){
    volatile uint32_t* scg_sosccsr = (volatile uint32_t*)(SCG_SOSCCSR);
    volatile uint32_t* scg_soscdiv = (volatile uint32_t*)(SCG_SOSCDIV);
    volatile uint32_t* scg_sosccfg = (volatile uint32_t*)(SCG_SOSCCFG);
    
    *scg_sosccsr &= ~(1 << 23); // LK = 0;
    *scg_sosccsr = 0x00000000;

    *scg_soscdiv &= ~((0x7 << 8) | (0x7 << 0));
    *scg_soscdiv |= ((0x1 << 8) | (0x1 << 0));
    
    *scg_sosccfg &= ~((0x3 << 4) | (1 << 3) | (1 << 2));
    *scg_sosccfg |= ((0x2 << 4) | (0x1 << 2));

    *scg_sosccsr |= (1 << 0);
    
    while(!(*scg_sosccsr & SCG_SOSCCSR_SOSCVLD_MASK));  
}
void SPLL_init_160MHz(){
    volatile uint32_t* scg_spllcsr = (volatile uint32_t*)(SCG_SPLLCSR);
    volatile uint32_t* scg_splldiv = (volatile uint32_t*)(SCG_SPLLDIV);
    volatile uint32_t* scg_spllcfg = (volatile uint32_t*)(SCG_SPLLCFG);
    
    *scg_spllcsr &= ~(1 << 23); // LK = 0;
    *scg_spllcsr = 0x00000000;

    *scg_splldiv &= ~((0x7 << 8) | (0x7 << 0));
    *scg_splldiv |= ((0x3 << 8) | (0x2 << 0));
    
    *scg_spllcfg &= ~((0x1F << 16) | (0x7 << 8));
    *scg_spllcfg |= ((0x18 << 16) | (0x0 << 8));

    *scg_spllcsr |= (1 << 0);
    
    while(!(*scg_spllcsr & SCG_SPLLCSR_SPLLVLD_MASK));    
}
void NormalRUNmode_80MHz(){
    volatile uint32_t* scg_rccr = (volatile uint32_t*)(SCG_RCCR);
    volatile uint32_t* scg_csr = (volatile uint32_t*)(SCG_CSR);
    
    *scg_rccr = 0x06010012;
    if(((*scg_csr & SCG_CSR_SCS_MASK) >> SCG_CSR_SCS_SHIFT) != 0x06){}
}
void enable_pcc(){
    volatile uint32_t* pcc_port_b = (volatile uint32_t*)(PCC_PORT_B);
    volatile uint32_t* pcc_port_c = (volatile uint32_t*)(PCC_PORT_C);
    volatile uint32_t* pcc_port_d = (volatile uint32_t*)(PCC_PORT_D);
    volatile uint32_t* pcc_ftm_1 = (volatile uint32_t*)(PCC_FTM_1);
    volatile uint32_t* pcc_lpuart1 = (volatile uint32_t*)(PCC_LPUART1);

    *pcc_port_b |= PCC_CGC_MASK;
    *pcc_port_c |= PCC_CGC_MASK;
    *pcc_port_d |= PCC_CGC_MASK;
    *pcc_ftm_1 |= PCC_CGC_MASK;
    *pcc_lpuart1 &= ~PCC_CGC_MASK;
    *pcc_lpuart1 |= (1 << 24) | PCC_CGC_MASK ;
}

void config_io(){
    volatile uint32_t* port_b_pcr_02 = (volatile uint32_t*)(PORT_B_BASE_ADDRESS + PCR_OFFSET(PTB02));
    volatile uint32_t* port_c_pcr_12 = (volatile uint32_t*)(PORT_C_BASE_ADDRESS + PCR_OFFSET(PTC12));
    volatile uint32_t* port_c_pcr_07 = (volatile uint32_t*)(PORT_C_BASE_ADDRESS + PCR_OFFSET(PTC07));
    volatile uint32_t* port_d_pcr_15 = (volatile uint32_t*)(PORT_D_BASE_ADDRESS + PCR_OFFSET(PTD15));
    
    volatile uint32_t* gpio_c_pddr = (volatile uint32_t*)(GPIOC_PDDR);
    volatile uint32_t* gpio_d_pddr = (volatile uint32_t*)(GPIOD_PDDR);
    volatile uint32_t* gpio_c_pidr = (volatile uint32_t*)(GPIOC_PIDR);
    

    // Clear MUX
    *port_c_pcr_12 &= ~(7 << 8);
    *port_c_pcr_07 &= ~(7 << 8);
    *port_d_pcr_15 &= ~(7 << 8);
    *port_b_pcr_02 &= ~(7 << 8);
    
    // Set PTC12 as GPIO + enable interruption on rising edge
    *port_c_pcr_12 |= (1 << 8);
    *port_c_pcr_12 &= ~(0xF << 16);
    *port_c_pcr_12 |= (0x9 << 16);
    *port_c_pcr_12 &= ~(3 << 0);
    *port_c_pcr_12 |= (3 << 0);
    
    

    // Set PTD15 as GPIO
    *port_d_pcr_15 |= (1 << 8);

    // Set PTB02 as FTM1_CH0
    *port_b_pcr_02 |= (2 << 8);


    // Configure PTC12 as an Input
    *gpio_c_pidr &= ~(1 << PTC12);
    *gpio_c_pddr &= ~(1 << PTC12);

    // Configure PTD15 as Output
    *gpio_d_pddr |= (1 << PTD15);

    // configure PTC07 TO LPUART01_TX
    *port_c_pcr_07 |= (2 << 8);
}

void config_uart(){
    volatile uint32_t* lpuart_1_baud = (volatile uint32_t*)(LPUART1_BAUD);
    volatile uint32_t* lpuart_1_ctrl = (volatile uint32_t*)(LPUART1_CTRL);

    *lpuart_1_ctrl &= ~(3 << 18);

    *lpuart_1_baud &= ~(0x1FFF << 0);
    *lpuart_1_baud |= (0x34 << 0); // 490 cuz clk = 80MHz ==> 80MHz / ((16 + 1)*9600) OSR = 16

    *lpuart_1_ctrl |= (1 << 19);
}
void send_char(const char c){
    volatile uint32_t* lpuart_1_stat = (volatile uint32_t*)(LPUART1_STAT);
    volatile uint32_t* lpuart_1_data = (volatile uint32_t*)(LPUART1_DATA);

    while(!(IS_BIT_SET(*lpuart_1_stat, 23)));
        *lpuart_1_data = c;
}

void send_str(const char* str, int size){
    int i = 0;
    for(i = 0; i < size; i++){
        send_char(*(str + i));
    }
}

__attribute__((weak)) int_t __write_console(__file_handle handle, uchar_t *buffer, size_t *count) {
    for(size_t i = 0; i < *count; i++) {
        send_char(buffer[i]);
    }
    return *count;
}
void config_ftm(){
    // configure ftm in input capture mode
    volatile uint32_t* ftm_1_mode = (volatile uint32_t*)((uint8_t*)FTM_1_BASE_ADDRESS + MODE_FTM_1_OFFSET);
    volatile uint32_t* ftm_1_combine = (volatile uint32_t*)((uint8_t*)FTM_1_BASE_ADDRESS + COMBINE_OFFSET);
    volatile uint32_t* ftm_1_sc = (volatile uint32_t*)((uint8_t*)FTM_1_BASE_ADDRESS + SC_OFFSET);
    volatile uint32_t* ftm_1_c0sc = (volatile uint32_t*)((uint8_t*)FTM_1_BASE_ADDRESS + CnSC_OFFSET(CH0));
    
    // WPDIS = 1
    *ftm_1_mode |= (1 << 2);
    // DECAPEN = 0
    *ftm_1_combine &= ~(1 << 2);
    // MCOMBINE = 0
    *ftm_1_combine &= ~(1 << 7);
    // COMBINE = 0
    *ftm_1_combine &= ~(1 << 0);
    // CPWMS = 0
    *ftm_1_sc &= ~(1 << 5);
    // MSB:MSA = 0:0, and
    *ftm_1_c0sc &= ~(3 << 4);
    // ELSB:ELSA ≠ 0:0 // Rising Edge
    *ftm_1_c0sc &= ~(3 << 2);
    *ftm_1_c0sc |= (1 << 2);
}
void no_interrupt(){
    // Click to SW2 -> LED ON
    volatile uint32_t* port_c_pdir = (volatile uint32_t*)(GPIOC_PDIR);
    volatile uint32_t* port_d_ptor = (volatile uint32_t*)(GPIOD_PTOR);
    
    if(IS_BIT_SET(*port_c_pdir, PTC12)){
        *port_d_ptor |= (1 << PTD15);
    }

}
void delay(){
    int i = 1000000;
    while (i > 0)
    {
        i--;
    }
}

int main(){
    WDOG_disable();
    SOSC_init_8MHz();
    SPLL_init_160MHz();
    NormalRUNmode_80MHz();
    enable_pcc();
    config_io();
    config_uart();
    const char* msg = "Houssame !\r\n";
    send_str(msg, 10);
    while (1)
    {
        send_str("Houssame !\r\n", 10);
        delay(1000);
    }
    
    NVIC_EnableIRQ(PORTC_IRQn);
    // 5. Enable global interrupts
    __asm volatile ("cpsie i");
    while(1){}
    return 0;
}

void PORTC_IRQHandler(void){
    volatile uint32_t* port_c_pcr_12 = (volatile uint32_t*)(PORT_C_BASE_ADDRESS + PCR_OFFSET(PTC12));
    volatile uint32_t* port_d_psor = (volatile uint32_t*)(GPIOD_PSOR);
    if(IS_BIT_SET(*port_c_pcr_12, 24)){
        *port_c_pcr_12 |= (1 << 24);
        *port_d_psor |= (1 << PTD15);
    }
}