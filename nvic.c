#include "S32K142_Regs.h"
#include "nvic.h"

void NVIC_EnableIRQ(uint8 IRQn)
{
    volatile uint32 *NVIC_ISER = (volatile uint32 *)((uint8 *)ISER_BASE_ADDRESS + (4 * (IRQn / 32)));

    *NVIC_ISER |= (1 << (IRQn % 32));
}