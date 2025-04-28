#ifndef CLOCK_CONFIG_H
#define CLOCK_CONFIG_H

#define BIT_IS_SET(reg, bit)        ((reg & (1 << bit)) != 0)

void SOSC_init_8MHz(void);
void SPLL_init_160MHz(void);
void NormalRUNmode_80MHz(void);

#endif