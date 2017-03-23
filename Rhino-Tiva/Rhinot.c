
#include "Rhinot.h"

	void Rhino_Init(int x,uint32_t baud)
	{
		UART_Init(x,baud);
		StopRhino(x);
		Rhino_Reset(x);
		SetMSpeed(255,x);
		UART_Transmitchar('P',x);
		UART_Transmitchar('0',x);
		UART_Transmitchar('\r',x);
	}
	void SetPos(int pos,int x)
	{
		UART_Transmitchar('P',x);
		UART_OutDec(pos*5,x);
		UART_Transmitchar('\r',x);
	}
	void Rhino_Reset(int x)
	{

		UART_Transmitchar('Y',x);
		UART_Transmitchar('\r',x);

	}
	void AutoCalibrate(int x)
	{
		UART_Transmitchar('X',x);
		UART_Transmitchar('\r',x);
		}
	void SetMSpeed(int speed1,int x)
	{
		if(speed1>255)
		speed1=255;
		else if(speed1<0)
		speed1=0;
		UART_Transmitchar('M',x);
		UART_OutDec(speed1,x);
		UART_Transmitchar('\r',x);
		}
	void RotateWithSpeed(int speed1,int x)
	{
		if(speed1>255)
		speed1=255;
		else if(speed1<-255)
		speed1=-255;
		UART_Transmitchar('S',x);
		UART_OutDec(speed1,x);
		UART_Transmitchar('\r',x);
		}
	void StopRhino(int x)
	{
		UART_Transmitchar('S',x);
		UART_Transmitchar('0',x);
		UART_Transmitchar('\r',x);
	}
	void GoToAngle(float angle1,int x)
	{
		angle1 *= 5;
		int angle2 = (int)angle1;
		UART_Transmitchar('G',x);
		UART_OutDec(angle2,x);
		UART_Transmitchar('\r',x);
	}
	void GoToRAngle(float pos1,int x)
	{
        pos1 = pos1*5;
		int pos2 = (int)pos1;
		UART_Transmitchar('R',x);
		UART_OutDec(pos2,x);
		UART_Transmitchar('\r',x);
	}
	int readRPos(int pos,int outuart)
	{
		UART_Transmitchar('P',outuart);
		UART_Transmitchar('\r',outuart);
		pos=pos*5;
		int y;
		y=0;
		char z=UART_Recievechar(outuart);
		while(z!='\r')
		{
			y*=10;
			y+=z-'0';
			z=UART_Recievechar(outuart);
		}
		return y;
	}
