#ifndef UART_Tiva
#define UART_Tiva
#include <stdint.h>
#include <stdbool.h>
#include "C:/Users/hp/Desktop/TivaWare_C_Series-2.1.2.111/inc/tm4c123gh6pm.h"
#include "C:/Users/hp/Desktop/TivaWare_C_Series-2.1.2.111/inc/hw_memmap.h"
#include "C:/Users/hp/Desktop/TivaWare_C_Series-2.1.2.111/inc/hw_types.h"
#include "C:/Users/hp/Desktop/TivaWare_C_Series-2.1.2.111/driverlib/sysctl.h"
#include "C:/Users/hp/Desktop/TivaWare_C_Series-2.1.2.111/driverlib/interrupt.h"
#include "C:/Users/hp/Desktop/TivaWare_C_Series-2.1.2.111/driverlib/gpio.h"
#include "C:/Users/hp/Desktop/TivaWare_C_Series-2.1.2.111/driverlib/timer.h"
#include "C:/Users/hp/Desktop/TivaWare_C_Series-2.1.2.111/inc/hw_uart.h"
#include "C:/Users/hp/Desktop/TivaWare_C_Series-2.1.2.111/driverlib/uart.h"
#include "C:/Users/hp/Desktop/TivaWare_C_Series-2.1.2.111/driverlib/pin_map.h"
void UART_Init(int x,uint32_t baud);
void UART_TransmitString(char *str,int i);
void UART_OutUDec(unsigned long n,int i);
void UART_OutDec(int x, int i);
void UART_Transmitchar(char ch,int i);
char UART_Recievechar( int i);
#endif // UART_TIVA_H_INCLUDED
