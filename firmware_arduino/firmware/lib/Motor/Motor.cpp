#include "Motor.h"

Motor::Motor(int step, int dir)
{
    this->step=step;
    this->dir=dir;
}

Motor::~Motor()
{
}

void Motor::setSpeed(int speed){
    this->speed = speed;
}

int Motor::getSpeed(){
    return this->speed;
}