#ifndef UART_H_
#define UART_H_


#define BIT_IS_SET(reg, bit)        (((reg) & (1 << bit)) != 0)

void config_uart();
void send_char(const char c);
void send_str(const char* str, int size);

#endif /* UART_H_ */