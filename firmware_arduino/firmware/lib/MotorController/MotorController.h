#ifndef MOTORCONTROLLER_H_
#define MOTORCONTROLLER_H_

#include "Motor.h"
#define maxMotors 12

class MotorController
{
private:
    Motor motoren[maxMotors];
public:
    MotorController(/* args */);
    ~MotorController();

    
    void parallelRun();
    void printMotors();
    String processInput();
};



#endif