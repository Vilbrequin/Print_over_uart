/* ---------------------------------------------------------------------------------------*/
/*  @author:  Houssame ELBIADE                                                            */
/*  @file:    startup_S32K142.c                                                           */
/*  @purpose: GNU Compiler Collection Startup File                                        */
/*  @version: 1.0                                                                         */
/*  @date:    2024-12-19                                                                  */
/* ---------------------------------------------------------------------------------------*/

typedef unsigned int uint32_t;

void Reset_Handler(void);
void Default_Handler(void);
void NMI_Handler(void)                      __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler(void)                __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler(void)                __attribute__ ((weak, alias("Default_Handler")));                           
void BusFault_Handler(void)                 __attribute__ ((weak, alias("Default_Handler")));                                
void UsageFault_Handler(void)               __attribute__ ((weak, alias("Default_Handler")));                                                                             
void SVC_Handler(void)                      __attribute__ ((weak, alias("Default_Handler")));                                     
void DebugMon_Handler(void)                 __attribute__ ((weak, alias("Default_Handler")));                                                                             
void PendSV_Handler(void)                   __attribute__ ((weak, alias("Default_Handler")));                                  
void SysTick_Handler(void)                  __attribute__ ((weak, alias("Default_Handler")));                                                                              
void DMA0_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));                                 
void DMA1_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));                                 
void DMA2_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));                                 
void DMA3_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));                                 
void DMA4_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));                                 
void DMA5_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));                                 
void DMA6_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));                                 
void DMA7_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));                                 
void DMA8_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));                                 
void DMA9_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));                                 
void DMA10_IRQHandler(void)                 __attribute__ ((weak, alias("Default_Handler")));                                
void DMA11_IRQHandler(void)                 __attribute__ ((weak, alias("Default_Handler")));                                
void DMA12_IRQHandler(void)                 __attribute__ ((weak, alias("Default_Handler")));                                
void DMA13_IRQHandler(void)                 __attribute__ ((weak, alias("Default_Handler")));                                
void DMA14_IRQHandler(void)                 __attribute__ ((weak, alias("Default_Handler")));                                
void DMA15_IRQHandler(void)                 __attribute__ ((weak, alias("Default_Handler")));                                
void DMA_Error_IRQHandler(void)             __attribute__ ((weak, alias("Default_Handler")));                            
void MCM_IRQHandler(void)                   __attribute__ ((weak, alias("Default_Handler")));                                  
void FTFC_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));                                 
void Read_Collision_IRQHandler(void)        __attribute__ ((weak, alias("Default_Handler")));                       
void LVD_LVW_IRQHandler(void)               __attribute__ ((weak, alias("Default_Handler")));                              
void FTFC_Fault_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void WDOG_EWM_IRQHandler(void)              __attribute__ ((weak, alias("Default_Handler")));                             
void RCM_IRQHandler(void)                   __attribute__ ((weak, alias("Default_Handler")));                                  
void LPI2C0_Master_IRQHandler(void)         __attribute__ ((weak, alias("Default_Handler")));                        
void LPI2C0_Slave_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));                         
void LPSPI0_IRQHandler(void)                __attribute__ ((weak, alias("Default_Handler")));                               
void LPSPI1_IRQHandler(void)                __attribute__ ((weak, alias("Default_Handler")));                               
void Reserved44_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void Reserved45_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void Reserved46_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void LPUART0_RxTx_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));                         
void Reserved48_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void LPUART1_RxTx_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));                         
void Reserved50_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void Reserved51_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void Reserved52_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void Reserved53_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void Reserved54_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void ADC0_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));                                 
void ADC1_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));                                 
void CMP0_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));                                 
void Reserved58_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void Reserved59_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void ERM_single_fault_IRQHandler(void)      __attribute__ ((weak, alias("Default_Handler")));                     
void ERM_double_fault_IRQHandler(void)      __attribute__ ((weak, alias("Default_Handler")));                     
void RTC_IRQHandler(void)                   __attribute__ ((weak, alias("Default_Handler")));                                  
void RTC_Seconds_IRQHandler(void)           __attribute__ ((weak, alias("Default_Handler")));                          
void LPIT0_Ch0_IRQHandler(void)             __attribute__ ((weak, alias("Default_Handler")));                            
void LPIT0_Ch1_IRQHandler(void)             __attribute__ ((weak, alias("Default_Handler")));                            
void LPIT0_Ch2_IRQHandler(void)             __attribute__ ((weak, alias("Default_Handler")));                            
void LPIT0_Ch3_IRQHandler(void)             __attribute__ ((weak, alias("Default_Handler")));                            
void PDB0_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));                                 
void Reserved69_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void Reserved70_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void Reserved71_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void Reserved72_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void SCG_IRQHandler(void)                   __attribute__ ((weak, alias("Default_Handler")));                                  
void LPTMR0_IRQHandler(void)                __attribute__ ((weak, alias("Default_Handler")));                               
void PORTA_IRQHandler(void)                 __attribute__ ((weak, alias("Default_Handler")));                                
void PORTB_IRQHandler(void)                 __attribute__ ((weak, alias("Default_Handler")));                                
void PORTC_IRQHandler(void)                 __attribute__ ((weak, alias("Default_Handler")));                                
void PORTD_IRQHandler(void)                 __attribute__ ((weak, alias("Default_Handler")));                                
void PORTE_IRQHandler(void)                 __attribute__ ((weak, alias("Default_Handler")));                                
void SWI_IRQHandler(void)                   __attribute__ ((weak, alias("Default_Handler")));                                  
void Reserved81_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void Reserved82_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void Reserved83_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void PDB1_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));                                 
void FLEXIO_IRQHandler(void)                __attribute__ ((weak, alias("Default_Handler")));                               
void Reserved86_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void Reserved87_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void Reserved88_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void Reserved89_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void Reserved90_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void Reserved91_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void Reserved92_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void Reserved93_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void CAN0_ORed_IRQHandler(void)             __attribute__ ((weak, alias("Default_Handler")));                            
void CAN0_Error_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void CAN0_Wake_Up_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));                         
void CAN0_ORed_0_15_MB_IRQHandler(void)     __attribute__ ((weak, alias("Default_Handler")));                   
void CAN0_ORed_16_31_MB_IRQHandler(void)    __attribute__ ((weak, alias("Default_Handler")));                  
void Reserved99_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                          
void Reserved100_IRQHandler(void)           __attribute__ ((weak, alias("Default_Handler")));                         
void CAN1_ORed_IRQHandler(void)             __attribute__ ((weak, alias("Default_Handler")));                            
void CAN1_Error_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void Reserved103_IRQHandler(void)           __attribute__ ((weak, alias("Default_Handler")));                         
void CAN1_ORed_0_15_MB_IRQHandler(void)     __attribute__ ((weak, alias("Default_Handler")));                    
void Reserved105_IRQHandler(void)           __attribute__ ((weak, alias("Default_Handler")));                          
void Reserved106_IRQHandler(void)           __attribute__ ((weak, alias("Default_Handler")));                          
void Reserved107_IRQHandler(void)           __attribute__ ((weak, alias("Default_Handler")));                          
void Reserved108_IRQHandler(void)           __attribute__ ((weak, alias("Default_Handler")));                          
void Reserved109_IRQHandler(void)           __attribute__ ((weak, alias("Default_Handler")));                          
void Reserved110_IRQHandler(void)           __attribute__ ((weak, alias("Default_Handler")));                          
void Reserved111_IRQHandler(void)           __attribute__ ((weak, alias("Default_Handler")));                          
void Reserved112_IRQHandler(void)           __attribute__ ((weak, alias("Default_Handler")));                          
void Reserved113_IRQHandler(void)           __attribute__ ((weak, alias("Default_Handler")));                          
void Reserved114_IRQHandler(void)           __attribute__ ((weak, alias("Default_Handler")));                          
void FTM0_Ch0_Ch1_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));                         
void FTM0_Ch2_Ch3_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));                         
void FTM0_Ch4_Ch5_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));                         
void FTM0_Ch6_Ch7_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));                         
void FTM0_Fault_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void FTM0_Ovf_Reload_IRQHandler(void)       __attribute__ ((weak, alias("Default_Handler")));                      
void FTM1_Ch0_Ch1_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));                         
void FTM1_Ch2_Ch3_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));                         
void FTM1_Ch4_Ch5_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));                         
void FTM1_Ch6_Ch7_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));                         
void FTM1_Fault_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void FTM1_Ovf_Reload_IRQHandler(void)       __attribute__ ((weak, alias("Default_Handler")));                      
void FTM2_Ch0_Ch1_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));                         
void FTM2_Ch2_Ch3_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));                         
void FTM2_Ch4_Ch5_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));                         
void FTM2_Ch6_Ch7_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));                         
void FTM2_Fault_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void FTM2_Ovf_Reload_IRQHandler(void)       __attribute__ ((weak, alias("Default_Handler")));                      
void FTM3_Ch0_Ch1_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));                         
void FTM3_Ch2_Ch3_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));                         
void FTM3_Ch4_Ch5_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));                         
void FTM3_Ch6_Ch7_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));                         
void FTM3_Fault_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));                           
void FTM3_Ovf_Reload_IRQHandler(void)       __attribute__ ((weak, alias("Default_Handler")));

// First address of stack (highest address in SRAM_U, stack grows downwards)
extern uint32_t _stack_top;

// First address of .data section in PROGRAM_FLASH
extern uint32_t _flash_sdata;

// Fisrt address of .data section in SRAM_U
extern uint32_t _sdata;

// Last address of .data section in SRAM_U
extern uint32_t _edata;

// Fisrt address of .bss section in SRAM_U
extern uint32_t _sbss;

// Last address of .bss section in SRAM_U
extern uint32_t _ebss;


// Main
extern int main(void);

const uint32_t VectorTable[] __attribute__ ((section (".isr_vector"))) = {
    (uint32_t)&_stack_top,
    (uint32_t)Reset_Handler,
    (uint32_t)NMI_Handler,
    (uint32_t)HardFault_Handler,
    (uint32_t)MemManage_Handler,                           
    (uint32_t)BusFault_Handler,                                
    (uint32_t)UsageFault_Handler,                              
    (uint32_t)0,                                          
    (uint32_t)0,                                               
    (uint32_t)0,                                               
    (uint32_t)0,                                               
    (uint32_t)SVC_Handler,                                     
    (uint32_t)DebugMon_Handler,                                
    (uint32_t)0,                                               
    (uint32_t)PendSV_Handler,                                  
    (uint32_t)SysTick_Handler,                                          
    (uint32_t)DMA0_IRQHandler,                                 
    (uint32_t)DMA1_IRQHandler,                                 
    (uint32_t)DMA2_IRQHandler,                                 
    (uint32_t)DMA3_IRQHandler,                                 
    (uint32_t)DMA4_IRQHandler,                                 
    (uint32_t)DMA5_IRQHandler,                                 
    (uint32_t)DMA6_IRQHandler,                                 
    (uint32_t)DMA7_IRQHandler,                                 
    (uint32_t)DMA8_IRQHandler,                                 
    (uint32_t)DMA9_IRQHandler,                                 
    (uint32_t)DMA10_IRQHandler,                                
    (uint32_t)DMA11_IRQHandler,                                
    (uint32_t)DMA12_IRQHandler,                                
    (uint32_t)DMA13_IRQHandler,                                
    (uint32_t)DMA14_IRQHandler,                                
    (uint32_t)DMA15_IRQHandler,                                
    (uint32_t)DMA_Error_IRQHandler,                            
    (uint32_t)MCM_IRQHandler,                                  
    (uint32_t)FTFC_IRQHandler,                                 
    (uint32_t)Read_Collision_IRQHandler,                       
    (uint32_t)LVD_LVW_IRQHandler,                              
    (uint32_t)FTFC_Fault_IRQHandler,                           
    (uint32_t)WDOG_EWM_IRQHandler,                             
    (uint32_t)RCM_IRQHandler,                                  
    (uint32_t)LPI2C0_Master_IRQHandler,                        
    (uint32_t)LPI2C0_Slave_IRQHandler,                         
    (uint32_t)LPSPI0_IRQHandler,                               
    (uint32_t)LPSPI1_IRQHandler,                               
    (uint32_t)Reserved44_IRQHandler,                           
    (uint32_t)Reserved45_IRQHandler,                           
    (uint32_t)Reserved46_IRQHandler,                           
    (uint32_t)LPUART0_RxTx_IRQHandler,                         
    (uint32_t)Reserved48_IRQHandler,                           
    (uint32_t)LPUART1_RxTx_IRQHandler,                         
    (uint32_t)Reserved50_IRQHandler,                           
    (uint32_t)Reserved51_IRQHandler,                           
    (uint32_t)Reserved52_IRQHandler,                           
    (uint32_t)Reserved53_IRQHandler,                           
    (uint32_t)Reserved54_IRQHandler,                           
    (uint32_t)ADC0_IRQHandler,                                 
    (uint32_t)ADC1_IRQHandler,                                 
    (uint32_t)CMP0_IRQHandler,                                 
    (uint32_t)Reserved58_IRQHandler,                           
    (uint32_t)Reserved59_IRQHandler,                           
    (uint32_t)ERM_single_fault_IRQHandler,                     
    (uint32_t)ERM_double_fault_IRQHandler,                     
    (uint32_t)RTC_IRQHandler,                                  
    (uint32_t)RTC_Seconds_IRQHandler,                          
    (uint32_t)LPIT0_Ch0_IRQHandler,                            
    (uint32_t)LPIT0_Ch1_IRQHandler,                            
    (uint32_t)LPIT0_Ch2_IRQHandler,                            
    (uint32_t)LPIT0_Ch3_IRQHandler,                            
    (uint32_t)PDB0_IRQHandler,                                 
    (uint32_t)Reserved69_IRQHandler,                           
    (uint32_t)Reserved70_IRQHandler,                           
    (uint32_t)Reserved71_IRQHandler,                           
    (uint32_t)Reserved72_IRQHandler,                           
    (uint32_t)SCG_IRQHandler,                                  
    (uint32_t)LPTMR0_IRQHandler,                               
    (uint32_t)PORTA_IRQHandler,                                
    (uint32_t)PORTB_IRQHandler,                                
    (uint32_t)PORTC_IRQHandler,                                
    (uint32_t)PORTD_IRQHandler,                                
    (uint32_t)PORTE_IRQHandler,                                
    (uint32_t)SWI_IRQHandler,                                  
    (uint32_t)Reserved81_IRQHandler,                           
    (uint32_t)Reserved82_IRQHandler,                           
    (uint32_t)Reserved83_IRQHandler,                           
    (uint32_t)PDB1_IRQHandler,                                 
    (uint32_t)FLEXIO_IRQHandler,                               
    (uint32_t)Reserved86_IRQHandler,                           
    (uint32_t)Reserved87_IRQHandler,                           
    (uint32_t)Reserved88_IRQHandler,                           
    (uint32_t)Reserved89_IRQHandler,                           
    (uint32_t)Reserved90_IRQHandler,                           
    (uint32_t)Reserved91_IRQHandler,                           
    (uint32_t)Reserved92_IRQHandler,                           
    (uint32_t)Reserved93_IRQHandler,                           
    (uint32_t)CAN0_ORed_IRQHandler,                            
    (uint32_t)CAN0_Error_IRQHandler,                           
    (uint32_t)CAN0_Wake_Up_IRQHandler,                         
    (uint32_t)CAN0_ORed_0_15_MB_IRQHandler,                   
    (uint32_t)CAN0_ORed_16_31_MB_IRQHandler,                  
    (uint32_t)Reserved99_IRQHandler,                          
    (uint32_t)Reserved100_IRQHandler,                         
    (uint32_t)CAN1_ORed_IRQHandler,                            
    (uint32_t)CAN1_Error_IRQHandler,                           
    (uint32_t)Reserved103_IRQHandler,                         
    (uint32_t)CAN1_ORed_0_15_MB_IRQHandler,                    
    (uint32_t)Reserved105_IRQHandler,                          
    (uint32_t)Reserved106_IRQHandler,                          
    (uint32_t)Reserved107_IRQHandler,                          
    (uint32_t)Reserved108_IRQHandler,                          
    (uint32_t)Reserved109_IRQHandler,                          
    (uint32_t)Reserved110_IRQHandler,                          
    (uint32_t)Reserved111_IRQHandler,                          
    (uint32_t)Reserved112_IRQHandler,                          
    (uint32_t)Reserved113_IRQHandler,                          
    (uint32_t)Reserved114_IRQHandler,                          
    (uint32_t)FTM0_Ch0_Ch1_IRQHandler,                         
    (uint32_t)FTM0_Ch2_Ch3_IRQHandler,                         
    (uint32_t)FTM0_Ch4_Ch5_IRQHandler,                         
    (uint32_t)FTM0_Ch6_Ch7_IRQHandler,                         
    (uint32_t)FTM0_Fault_IRQHandler,                           
    (uint32_t)FTM0_Ovf_Reload_IRQHandler,                      
    (uint32_t)FTM1_Ch0_Ch1_IRQHandler,                         
    (uint32_t)FTM1_Ch2_Ch3_IRQHandler,                         
    (uint32_t)FTM1_Ch4_Ch5_IRQHandler,                         
    (uint32_t)FTM1_Ch6_Ch7_IRQHandler,                         
    (uint32_t)FTM1_Fault_IRQHandler,                           
    (uint32_t)FTM1_Ovf_Reload_IRQHandler,                      
    (uint32_t)FTM2_Ch0_Ch1_IRQHandler,                         
    (uint32_t)FTM2_Ch2_Ch3_IRQHandler,                         
    (uint32_t)FTM2_Ch4_Ch5_IRQHandler,                         
    (uint32_t)FTM2_Ch6_Ch7_IRQHandler,                         
    (uint32_t)FTM2_Fault_IRQHandler,                           
    (uint32_t)FTM2_Ovf_Reload_IRQHandler,                      
    (uint32_t)FTM3_Ch0_Ch1_IRQHandler,                         
    (uint32_t)FTM3_Ch2_Ch3_IRQHandler,                         
    (uint32_t)FTM3_Ch4_Ch5_IRQHandler,                         
    (uint32_t)FTM3_Ch6_Ch7_IRQHandler,                         
    (uint32_t)FTM3_Fault_IRQHandler,                           
    (uint32_t)FTM3_Ovf_Reload_IRQHandler                    
};

const uint32_t FlashConfig[] __attribute__ ((section (".FlashConfig"))) = {
    (uint32_t)0xFFFFFFFF,    /* 8 bytes backdoor comparison key           */
    (uint32_t)0xFFFFFFFF,    /*                                           */
    (uint32_t)0xFFFFFFFF,    /* 4 bytes program flash protection bytes    */
    (uint32_t)0xFFFF7FFE     /* FDPROT:FEPROT:FOPT:FSEC(0xFE = unsecured) */
};

void Reset_Handler(void){

    uint32_t _data_size = &_edata - &_sdata;
    uint32_t* Src = (uint32_t*)&_flash_sdata;
    uint32_t* Dst = (uint32_t*)&_sdata;
    
    uint32_t _bss_size = &_ebss - &_sbss;
    uint32_t* Bss_Dest = (uint32_t*)&_sbss;

    // Copy data from PROGRAM_FLASH to SRAM_U
    for(uint32_t i = 0; i < _data_size; i += 4){
        *Dst++ = *Src++;
    }
    
    // Initialize .bss section with zero (0)
    if(_bss_size != 0){
        for(uint32_t i = 0; i < _bss_size; i += 4){
            *Bss_Dest++ = 0;
        }
    }
    
    // Call main()
    main();
}


void Default_Handler(void) {
    while(1);
}