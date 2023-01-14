#ifndef MOTOR_H_
#define MOTOR_H_


class Motor
{
private:
    int step, dir, speed, steps;
public:
    Motor(int step, int dir);
    ~Motor();

    void setSpeed(int speed);
    int getSpeed();

    void setSteps(int steps);
    int getSteps();

    int getStep();
    int getDir();
};

#endif
