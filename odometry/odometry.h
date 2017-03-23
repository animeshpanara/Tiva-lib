#ifndef ODOMETRY
#define ODOMETRY

enum {A, B};
enum {X,Y,Phi};
#define DistanceBetweenWheels 96.0
#define RADIUSA 5.0
#define RADIUSB 5.0
#define NumberOfTicksPerRevolution 4005.0

float getX(float DC);
float getY(float DC);
float getPhi();
float getDc();
long int GetTicks(int i);



#endif
