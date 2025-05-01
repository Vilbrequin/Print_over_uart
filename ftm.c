#include "ftm.h"
#include "std_types.h"
#include "S32K142_Regs.h"

#define CH6                     6UL
#define FTM3_Ch6_Ch7_IRQn       120UL

volatile char counter = '0';

void ftm_config(void){
    volatile uint32* pcc_ftm_3 = (volatile uint32*)(PCC_FTM3);
    volatile uint32* ftm_3_sc = (volatile uint32*)(FTM3_SC);
    volatile uint32* ftm_3_mode = (volatile uint32*)(FTM3_MODE);
    volatile uint32* ftm_3_combine = (volatile uint32*)(FTM3_COMBINE);
    volatile uint32* ftm3_mod = (volatile uint32*)(FTM3_MOD);
    volatile uint32* ftm_3_ch6_sc = (volatile uint32*)(FTM3_BASE_ADDRESS + CnSC_OFFSET(CH6));

    // Disable the clock to configure FTM Clock Source PCS[26:24] bits
    *pcc_ftm_3 &= ~CGC_MASK;

    // Select the clock source for the FTM3 Module as SOSCDIV1 (8MHz), by setting PCS[26:24] = 0b001
    *pcc_ftm_3 &= ~PCS_MASK;
    *pcc_ftm_3 |= (1 << 24);

    // Enable the Clock
    *pcc_ftm_3 |= CGC_MASK;

    // Select external clock as clock for the ftm counter, by setting FTM3_SC[CLKS] = 0b11
    *ftm_3_sc &= ~SC_CLK_MASK;
    *ftm_3_sc |= SC_CLK_MASK;

    // Select the Prescale factor as divisin by 1 by clearing the FTM3_SC[PS] = 0b000
    *ftm_3_sc &= ~SC_PS;

    // Configure the FTM3_CH6 to Input Capture Mode as follow:
    
    // first we need to disable write protection MODE[WPDIS] = 0b1
    *ftm_3_mode |= MODE_WPDIS_MASK;

    // Disable Combine Mode COMBINE[COMBINE3] = 0b0
    // Disable Dual Edge Capture Mode COMBINE[DECAPEN3] = 0b0
    // Disable Modifided Combine Mode COMBINE[MCOMBINE3] = 0b0
    *ftm_3_combine &= ~(COMBINE_COMBINE3_MASK | COMBINE_DECAPEN3_MASK| COMBINE_MCOMBINE3_MASK);

    // Configure the FTM to operate in Up Counting mode SC[CPWMS] = 0b0
    *ftm_3_sc &= ~SC_CPWMS;

    // Enable Timer Overflow Interrupt
    *ftm_3_sc |= SC_TOIE;

    // Now set the Input Capture Mode for Channel 6 & select edge as rising edge
    *ftm_3_ch6_sc &= ~CH6_SC_MSB_MSA_MASK;
    
    *ftm_3_ch6_sc &= ~CH6_SC_ELSB_ELSA_MASK;
    *ftm_3_ch6_sc |= (1 << 2);

    // Set the Modulo value as 0xFFFF
    *ftm3_mod = 0xFFFF;

    
}

void FTM3_Ovf_Reload_IRQHandler(void){  
    volatile uint32* ftm_3_sc = (volatile uint32*)(FTM3_SC);
    volatile uint32 temp = *ftm_3_sc;
    *ftm_3_sc = temp &~SC_TOF;
    counter = 'A';
}