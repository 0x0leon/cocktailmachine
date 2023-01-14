#ifndef MOTORCONTROLLER_H_
#define MOTORCONTROLLER_H_

#include "Motor.h"

#define maxMotors 12

class MotorController
{
private:
    Motor motoren[maxMotors];
    int count;
public:
    MotorController(/* args */);
    ~MotorController();

    void parallelRun();
};



#endif