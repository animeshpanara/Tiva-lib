#ifndef Rhinot
#define Rhinot
#include "UART_Tiva.h"
	void Rhino_Init(int x,uint32_t baud);
    void Rhino_Reset(int x);
    void AutoCalibrate(int x);
    void SetMSpeed(int speed1,int x);
    void SetPos(int pos,int x);
    int readRPos(int pos,int outuart);
    void RotateWithSpeed(int speed1,int x);
    void StopRhino(int x);
    void GoToAngle(float angle1,int x);
    void GoToRAngle(float pos1,int x);
#endif // Rhinot
