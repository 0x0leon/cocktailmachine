#ifndef MOTORCONTROLLER_H_
#define MOTORCONTROLLER_H_

#define maxMotors 12

class MotorController
{
private:
    int motoren[maxMotors];
    int count;
public:
    MotorController(/* args */);
    ~MotorController();

    void parallelRun();
};



#endif