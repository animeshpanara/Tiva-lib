#define HW_TEST 0

#if HW_TEST == 1
#include "HWtest.h"
#endif

#include "userLib/common.h"
#include "userLib/init.h"
#include "userLib/pidController.h"
#include "userLib/movingArray.h"

#define KP_motorA 0.05
#define KI_motorA 0.0
#define KD_motorA 0.3
#define KP_motorB 0.05
#define KI_motorB 0.0
#define KD_motorB 0.3
#define pi 3.14159265

volatile float desiredRPM[2] = {0.0,0.0}, currentRPM[2] = {0.0,0.0}, out[2] = {0.0,0.0},bufferDesiredRPM[2] = {0.0,0.0};
float distance[2]={0.0,0.0};
float position[3]={0.0,0.0,0.0};

int uartReceiveCount = 0;
long int count[2]={0},prev[2]={0};
int32_t maxPWM = 10;
int32_t minPWM = 0;
float Dc=0;

float getX(float DC)
{
	return position[X]+DC*cos((position[Phi]));//(pi*position[Phi])/180.0);
}
float getY(float DC)
{
	return position[Y]+DC*sin((position[Phi]));
}
float getPhi()
{
	return position[Phi]+(distance[A]-distance[B])/(DistanceBetweenWheels);
}
float getDc()
{
	distance[A]=(2*pi*RADIUSA*GetTicks(A))/NumberOfTicksPerRevolution;
	distance[B]=(2*pi*RADIUSB*GetTicks(B))/NumberOfTicksPerRevolution;
	return 	(distance[A]+distance[B])/2.0;
}
long int GetTicks(int i)
{
	int x,y;
	if(i==A)
	{
		count[A]= QEIPositionGet(QEI0_BASE);
		x= count[A]-prev[A];
		prev[A]=count[A];
		return x;
	}
	if(i==B)
	{
		count[B]=QEIPositionGet(QEI1_BASE);
		x=(count[B]-prev[B]);
		prev[B]=count[B];
		return -x;
	}

}
int main() {
	SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
	uart0Init();

    maxPWM = SysCtlClockGet()/(PWMfrequency*64);
#if HW_TEST == 0
	initPIDController(A,KP_motorA,KI_motorA,KD_motorA);
	initPIDController(B,KP_motorB,KI_motorB,KD_motorB);
	motorDirInit();
	uart5Init();
	pwmInit();
	timerInit();
	maxPWM = SysCtlClockGet()/(PWMfrequency*64);
	qeiInit();
	IntMasterEnable();
#elif HW_TEST == 1
	Type hardware test codes here*/
	testMotor(A,maxPWM/2);
	testMotor(B,maxPWM/2);
	testBothEncoder();
#endif

	while(1) {
	//	GraphPlot0(currentRPM[A],desiredRPM[A],currentRPM[B],desiredRPM[B]);
	}
}

void Timer0IntHandler(void) {
		TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
	    Dc=getDc();
	    position[X]=getX(Dc);
	    position[Y]=getY(Dc);
	    position[Phi]=getPhi();
	   	UARTCharPut(UART0_BASE,' ');
	    UART_OutDec(10*position[X],0);
	    UARTCharPut(UART0_BASE,' ');
	    UART_OutDec(10*position[Y],0);
	    UARTCharPut(UART0_BASE,' ');
	    UART_OutDec(180*position[Phi]/pi,0);


	 	UARTCharPut(UART0_BASE,0x0d);
		// Clear the timer interrupt//UART_TransmitString("hello",0);
}

void UARTIntHandler(void) {
	uint32_t ui32Status;
	ui32Status = UARTIntStatus(UART5_BASE, true); //get interrupt status
	UARTIntClear(UART5_BASE, ui32Status); //clear the asserted interrupts
	char data = HWREG(UART5_BASE + UART_O_DR);
	if(data == 0x0A) {
		uartReceiveCount = 0;
	} else {
		switch(uartReceiveCount) {
			case 0:
				bufferDesiredRPM[A] = ((data * ((data & 0x01) ? -1 : 1)));
				break;
			case 1:
				bufferDesiredRPM[B] = ((data * ((data & 0x01) ? -1 : 1)));
				desiredRPM[A] = bufferDesiredRPM[A];
				desiredRPM[B] = bufferDesiredRPM[B];
				break;
		}
		uartReceiveCount++;
	}
}

void QEI0IntHandler(void) {
	QEIIntClear(QEI0_BASE, QEI_INTTIMER);
	currentRPM[A] = movingArrayOut(A,calculateRPM(A));
	if(desiredRPM[A]!=0) {
		out[A] += PID(A,desiredRPM[A] - currentRPM[A]);
	} else {
		out[A] = 0;
	}
	setPWM(out[A],A);
}

void QEI1IntHandler(void) {
	QEIIntClear(QEI1_BASE, QEI_INTTIMER);
	currentRPM[B] = movingArrayOut(B,calculateRPM(B));
	if(desiredRPM[B]!=0) {
		out[B] += PID(B,desiredRPM[B] - currentRPM[B]);
	} else {
		out[B] = 0;
	}
	setPWM(out[B],B);
}
