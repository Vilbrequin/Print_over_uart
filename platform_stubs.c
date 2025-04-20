/* platform_stubs.c */
void _ExitProcess(int status) {
    while(1); // Infinite loop for bare-metal systems
}

/* For Cortex-M, set initial stack pointer in vector table instead */
extern unsigned long _stack_top;
unsigned long *__SP_INIT = &_stack_top;