#include "clock_config.h"
#include "std_types.h"
#include "S32K142_Regs.h"

void SOSC_init_8MHz(void)
{
    volatile uint32* scg_sosc_cfg = (volatile uint32 *)(SCG_SOSCCFG);
    volatile uint32* scg_sosc_csr = (volatile uint32 *)(SCG_SOSCCSR);
    volatile uint32* scg_sosc_div = (volatile uint32 *)(SCG_SOSCDIV);

    // Disable the SOSC to Configure the device correctlly
    *scg_sosc_cfg &= ~SCG_LK_MASK;
    *scg_sosc_csr &= ~SCG_EN_MASK;

    // Configure the System oscillator as follow
    // RANGE[5:4] = 0b10 => Medium frequency range selected for the crytstal oscillator
    // HGO = 0 => Configure crystal oscillator for low-gain operation
    // EREFS = 1 => Internal crystal oscillator of OSC selected (XTAL)
    *scg_sosc_cfg &= ~((3 << 4) | (1 << 3) | (1 << 2));
    *scg_sosc_cfg |= ((2 << 4) | (1 << 2));

    // Configure the System Oscillator Dividers
    // SOSCDIV2[10:8] = 0b001 => functional Clock used by LPUART1
    // SOSCDIV1[2:0] = 0b001 => functional Clock used by FlexTimer Module
    *scg_sosc_div &= ~(SCG_DIV2_MASK | SCG_DIV1_MASK);
    *scg_sosc_div |= ((1 << 8) | (1 << 0));

    *scg_sosc_csr |= SCG_EN_MASK;

    while (!(*scg_sosc_csr & SCG_VLD_MASK));
}

void SPLL_init_160MHz(void)
{
    volatile uint32* scg_spll_cfg = (volatile uint32 *)(SCG_SPLLCFG);
    volatile uint32* scg_spll_csr = (volatile uint32 *)(SCG_SPLLCSR);
    volatile uint32* scg_spll_div = (volatile uint32 *)(SCG_SPLLDIV);

    // Disable the Sysytem PLL to correctly configure the device
    *scg_spll_cfg &= ~SCG_LK_MASK;
    *scg_spll_csr &= ~SCG_EN_MASK;

    // Configure the System Phased Locked Loop as follow:
    // the MULT and PREDIV Bitfields are calculated via this two formulas:
    // "SPLL_CLK = (VCO_CLK)/2" and "VCO_CLK = SPLL_SOURCE/(PREDIV + 1) X (MULT + 16)"
    // MULT[20:16] = 0b11000 => the multiplication factor applied to the PLL reference clock frequency
    // PREDIV[10:8] = 0b000 => the amount to divide down the reference clock for the System PLL
    *scg_spll_cfg &= ~((0x1F << 16) | (0x07 << 8));
    *scg_spll_cfg |= ((0x18 << 16));

    *scg_spll_csr |= SCG_EN_MASK;

    while (!(*scg_spll_csr & SCG_VLD_MASK));
}

void NormalRUNmode_80MHz(void){
    volatile uint32* scg_rccr = (volatile uint32*)(SCG_RCCR);
    volatile uint32* scg_csr = (volatile uint32*)(SCG_CSR);

    // Configure the RUN Mode as follow:
    // SCS[27:24] = 0b110 => Choose SPLL_CLK as the System Clock Source
    // DIVCORE[19:16] = 0b0001 => [SYS_CLK]: Divide the Source CLock by 2
    // DIVBUS[7:4] = 0b0001 => [BUS_CLK]: Divide the SYS_CLK By 2
    // DIVSLOW[3:0] = 0b0010 => [FLASH_CLK]: ivide the SYS_CLK By 4
    *scg_rccr = 0x06010012;
    
    // Monitor if the SPLL is correctly selected
    if(((*scg_csr & SCG_CSR_SCS_MASK) >> SCG_CSR_SCS_SHIFT) != 6){}
}