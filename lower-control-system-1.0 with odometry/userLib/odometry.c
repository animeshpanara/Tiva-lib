#include <math.h>
#include "odometry.h"

//long int count[2]={0},prev[2]={0};
//float Dc=0;
enum {A, B};
enum {X,Y,Phi};

float distance[2]={0.0,0.0};
float position[3]={0.0,0.0,0.0};
float getX(float DC)
{
	position[X]=position[X]+DC*cos((position[Phi]));
	return position[X];
}
float getY(float DC)
{
	position[Y]=position[Y]+DC*sin((position[Phi]));
	return position[Y];
}
float getPhi()
{
	position[Phi]=position[Phi]+(distance[A]-distance[B])/(DistanceBetweenWheels);
	return position[Phi];
}
float getDc()
{
	distance[A]=(2*pi*RADIUSA*GetTicks(A))/NumberOfTicksPerRevolution;
	distance[B]=(2*pi*RADIUSB*GetTicks(B))/NumberOfTicksPerRevolution;
	return 	(distance[A]+distance[B])/2.0;
}

//setup timer and set its timer handler as this
/*void Timer0IntHandler(void) {
		TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
	    Dc=getDc();
	    position[X]=getX(Dc);
	    position[Y]=getY(Dc);
	    position[Phi]=getPhi();
	   	UARTCharPut(UART0_BASE,' ');
	    UART_OutDec(position[X],0);
	    UARTCharPut(UART0_BASE,' ');
	    UART_OutDec(position[Y],0);
	    UARTCharPut(UART0_BASE,' ');
	    UART_OutDec(180*position[Phi]/pi,0);
	 	UARTCharPut(UART0_BASE,0x0d);
		 Clear the timer interrupt//UART_TransmitString("hello",0);
}
*/
