/* ---------------------------------------------------------------------------------------*/
/*  @author:              Houssame ELBIADE                                                */
/*  @file:                S32K142.ld                                                      */
/*  @Processor:           S32K142 with 32 KB SRAM                                         */
/*  @purpose:             GNU Compiler Collection Linker Script                           */
/*  @version:             1.0                                                             */
/*  @date:                2024-12-19                                                      */
/* ---------------------------------------------------------------------------------------*/

ENTRY(Reset_Handler)

_estack = ORIGIN(SRAM_U) + LENGTH(SRAM_U);

_Min_Heap_Size = 0x00000400;
_Min_Stack_Size = 0x00000400;

MEMORY 
{
    FLASH_INTERRUPTS (rx) : ORIGIN = 0x00000000, LENGTH = 1K
    FLASH_CONFIG (rx) : ORIGIN = 0x00000400, LENGTH = 16
    PROGRAM_FLASH (rx) : ORIGIN = 0x00000410, LENGTH = 0x0003FBF0 /* 40000(256KB) - 400(1KB) - 16 */

    SRAM_L (rwx) : ORIGIN = 0x1FFFC000, LENGTH = 16K /* extends downwards (0x1FFFFFFF SRAM_L Start Address) */
    SRAM_U (rwx) : ORIGIN = 0x20000000, LENGTH = 12K /* extends upwards (0x20000000 SRAM_U Start Address) */
}

SECTIONS
{
    .isr_vector : 
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector))
        . = ALIGN(4);
    } > FLASH_INTERRUPTS
    
    .flash_config :
    {
        . = ALIGN(4);
        KEEP(*(.FlashConfig))
        . = ALIGN(4);
    } > FLASH_CONFIG

    .text : 
    {
        . = ALIGN(4);

        *(.text)
        *(.text*)

        . = ALIGN(4);

        _etext = .;
    } > PROGRAM_FLASH

    .rodata : 
    {
        . = ALIGN(4);

        *(.rodata)
        *(.rodata*)

        . = ALIGN(4);

    } > PROGRAM_FLASH
    
    _flash_sdata = LOADADDR(.data);

    .data : 
    {
        . = ALIGN(4);
        _sdata = .;

        *(.data)
        *(.data*) 

        . = ALIGN(4);
        _edata = .;

    } > SRAM_U AT> PROGRAM_FLASH

    .bss : 
    {
        . = ALIGN(4);
        _sbss = .;

        *(.bss)
        *(.bss*)
        *(.COMMON)

        . = ALIGN(4);
        _ebss = .;
    } > SRAM_U

    .heap : 
    {
        . = ALIGN(8);
        _sheap = .;

        PROVIDE ( end = . );
        PROVIDE ( _end = . );
        . = . + _Min_Heap_Size;

        . = ALIGN(8);
        _eheap = .;
    } > SRAM_U

    _stack_top = ORIGIN(SRAM_U) + LENGTH(SRAM_U);

    .stack :
    {
        . = ALIGN(8);
        _sstack = .;

        PROVIDE ( end = . );
        PROVIDE ( _end = . );
        . = . + _Min_Stack_Size;

        . = ALIGN(8);
        _estcak = .;
    } > SRAM_U
}