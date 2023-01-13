#ifndef MOTOR_H_
#define MOTOR_H_


class Motor
{
private:
    int step, dir, speed;
public:
    Motor(int step, int dir);
    ~Motor();

    void setSpeed(int speed);
    int getSpeed();
};

#endif
