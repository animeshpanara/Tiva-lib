#include <math.h>
#include "odometry.h"
float distance[2]={0.0,0.0};
float position[3]={0.0,0.0,0.0};
long int count[2]={0},prev[2]={0};
float Dc=0;

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
long int GetTicks(int i)
{
	int x;
	if(i==A)
	{
		count[A]= QEIPositionGet(QEI0_BASE);//configure qei0 first with max ticks as 0xffffffff;
		x= count[A]-prev[A];
		prev[A]=count[A];
		return x;
	}
	if(i==B)
	{
		count[B]=QEIPositionGet(QEI1_BASE);//configure qei1 first with max ticks as 0xffffffff;
		x=(count[B]-prev[B]);
		prev[B]=count[B];
		return x; //-x  if ur taking ticks of qei1 reverse or negative of direction of qei0 else x
	}

}
//setup timer and set its timer handler as this
void Timer0IntHandler(void) {
		TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
	    Dc=getDc();
	    position[X]=getX(Dc);
	    position[Y]=getY(Dc);
	    position[Phi]=getPhi();
	   /*	UARTCharPut(UART0_BASE,' ');
	    UART_OutDec(position[X],0);
	    UARTCharPut(UART0_BASE,' ');
	    UART_OutDec(position[Y],0);
	    UARTCharPut(UART0_BASE,' ');
	    UART_OutDec(180*position[Phi]/pi,0);
	 	UARTCharPut(UART0_BASE,0x0d);
		*/// Clear the timer interrupt//UART_TransmitString("hello",0);
}
