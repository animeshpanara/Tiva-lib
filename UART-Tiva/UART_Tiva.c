#include "UART_Tiva.h"
void UART_Init(int x,uint32_t baud)
{
	switch(x)
	{
	case 0:
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	GPIOPinConfigure(GPIO_PA0_U0RX);
	GPIOPinConfigure(GPIO_PA1_U0TX);
	GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
	UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(),baud,(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
	break;

	case 1:
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	GPIOPinConfigure(GPIO_PB0_U1RX);
	GPIOPinConfigure(GPIO_PB1_U1TX);
	GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1);
	UARTConfigSetExpClk(UART1_BASE, SysCtlClockGet(),baud,(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
	break;
	case 2:
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART2);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	GPIOPinConfigure(GPIO_PD6_U2RX);
	GPIOPinConfigure(GPIO_PD7_U2TX);
	GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7);
	UARTConfigSetExpClk(UART2_BASE, SysCtlClockGet(),baud,(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

	break;
	case 3:
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART3);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
	GPIOPinConfigure(GPIO_PC6_U3RX);
	GPIOPinConfigure(GPIO_PC7_U3TX);
	GPIOPinTypeUART(GPIO_PORTC_BASE, GPIO_PIN_6 | GPIO_PIN_7);
	UARTConfigSetExpClk(UART3_BASE, SysCtlClockGet(),baud,(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
	break;
	case 4:
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART4);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
	GPIOPinConfigure(GPIO_PC4_U4RX);
	GPIOPinConfigure(GPIO_PC5_U4TX);
	GPIOPinTypeUART(GPIO_PORTC_BASE, GPIO_PIN_4 | GPIO_PIN_5);
	UARTConfigSetExpClk(UART4_BASE, SysCtlClockGet(),baud,(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
	break;
	case 5:
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART5);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	GPIOPinConfigure(GPIO_PE4_U5RX);
	GPIOPinConfigure(GPIO_PE5_U5TX);
	GPIOPinTypeUART(GPIO_PORTE_BASE, GPIO_PIN_4 | GPIO_PIN_5);
	UARTConfigSetExpClk(UART5_BASE, SysCtlClockGet(),baud,(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
	break;
	case 6:
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART6);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	GPIOPinConfigure(GPIO_PD4_U6RX);
	GPIOPinConfigure(GPIO_PD5_U6TX);
	GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_4 | GPIO_PIN_5);
	UARTConfigSetExpClk(UART6_BASE, SysCtlClockGet(),baud,(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
	break;
	case 7:
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART7);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	GPIOPinConfigure(GPIO_PE0_U7RX);
	GPIOPinConfigure(GPIO_PE1_U7TX);
	GPIOPinTypeUART(GPIO_PORTE_BASE, GPIO_PIN_0 | GPIO_PIN_1);
	UARTConfigSetExpClk(UART7_BASE, SysCtlClockGet(),baud,(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
	break;

	}
}
void UART_TransmitString(char *str,int i) {
	while(*str>0)	 {
		switch(i)	{
		case 0:
		UARTCharPut(UART0_BASE,(*str));
		break;
		case 1:
			UARTCharPut(UART1_BASE,(*str));
			break;
		case 2:
			UARTCharPut(UART2_BASE,(*str));
			break;
		case 3:
			UARTCharPut(UART3_BASE,(*str));
			break;
		case 4:
			UARTCharPut(UART4_BASE,(*str));
			break;
		case 5:
			UARTCharPut(UART5_BASE,(*str));
			break;
		case 6:
			UARTCharPut(UART6_BASE,(*str));
			break;
		case 7:
			UARTCharPut(UART7_BASE,(*str));
			break;
		}
		str++;
	}
}
void UART_OutUDec(unsigned long n,int i) {
	if(n >= 10){
		UART_OutUDec(n/10,i);
		n = n%10;
	}
	switch(i)
	{
	case 0:
		UARTCharPut(UART0_BASE,(n+'0'));
		break;
	case 1:
		UARTCharPut(UART1_BASE,(n+'0'));
		break;
	case 2:
		UARTCharPut(UART2_BASE,(n+'0'));
		break;
	case 3:
		UARTCharPut(UART3_BASE,(n+'0'));
		break;
	case 4:
		UARTCharPut(UART4_BASE,(n+'0'));
		break;
	case 5:
		UARTCharPut(UART5_BASE,(n+'0'));
		break;
	case 6:
		UARTCharPut(UART6_BASE,(n+'0'));
		break;
	case 7:
		UARTCharPut(UART7_BASE,(n+'0'));
	    break;
	}
}

void UART_OutDec(int x, int i) {

	if(x < 0) {
		switch(i)
		{
		case 0:
			UARTCharPut(UART0_BASE,'-');
			break;
		case 1:
			UARTCharPut(UART1_BASE,'-');
			break;
		case 2:
			UARTCharPut(UART2_BASE,'-');
			break;
		case 3:
			UARTCharPut(UART3_BASE,'-');
			break;
		case 4:
			UARTCharPut(UART4_BASE,'-');
			break;
		case 5:
			UARTCharPut(UART5_BASE,'-');
			break;
		case 6:
			UARTCharPut(UART6_BASE,'-');
			break;
		case 7:
			UARTCharPut(UART7_BASE,'-');
			break;
		}
		x *= -1;
	}
	UART_OutUDec(x, i);
}
void UART_Transmitchar(char ch, int i) {


		switch(i)
		{
		case 0:
			UARTCharPut(UART0_BASE,ch);
			break;
		case 1:
			UARTCharPut(UART1_BASE,ch);
			break;
		case 2:
			UARTCharPut(UART2_BASE,ch);
			break;
		case 3:
			UARTCharPut(UART3_BASE,ch);
			break;
		case 4:
			UARTCharPut(UART4_BASE,ch);
			break;
		case 5:
			UARTCharPut(UART5_BASE,ch);
			break;
		case 6:
			UARTCharPut(UART6_BASE,ch);
			break;
		case 7:
			UARTCharPut(UART7_BASE,ch);
			break;
		}


}
char UART_Recievechar( int i) {


		switch(i)
		{
		case 0:
			return UARTCharGet(UART0_BASE);
			break;
		case 1:
			return UARTCharGet(UART1_BASE);
			break;
		case 2:
			return UARTCharGet(UART2_BASE);
			break;
		case 3:
			return UARTCharGet(UART3_BASE);
			break;
		case 4:
			return UARTCharGet(UART4_BASE);
			break;
		case 5:
			return UARTCharGet(UART5_BASE);
			break;
		case 6:
			return UARTCharGet(UART6_BASE);
			break;
		case 7:
			return UARTCharGet(UART7_BASE);
			break;
		}


}
