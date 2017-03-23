#ifndef common
#define common

#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "inc/hw_ints.h"
#include "inc/hw_uart.h"
#include "inc/tm4c123gh6pm.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"
#include "driverlib/pwm.h"
#include "driverlib/qei.h"

enum {A, B};
enum {X,Y,Phi};
extern int32_t maxPWM, minPWM;
#define DistanceBetweenWheels 96.0
#define RADIUSA 5.0
#define RADIUSB 5.0
#define NumberOfTicksPerRevolution 4005.0
#define PIDfrequency 200
#define PWMfrequency 2500
#define QEIfrequency 40
#define motorDirectionRegister GPIO_PORTF_BASE
#define A1 GPIO_PIN_1
#define A2 GPIO_PIN_0
#define B1 GPIO_PIN_3
#define B2 GPIO_PIN_2


void setPWM(int pwm,int i);
int calculateRPM(int i);
unsigned absolute(int x);
void UART_TransmitString(char* string,int i);
void UART_OutDec(int x, int i);
void GraphPlot0(int data1, int data2, int data3, int data4);
void GraphPlot1(int data1, int data2, int data3, int data4);

#endif
