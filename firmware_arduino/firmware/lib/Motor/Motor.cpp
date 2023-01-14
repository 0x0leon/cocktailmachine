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

void Motor::setSteps(int steps){
    this->steps = steps;
}

int Motor::getSpeed(){
    return this->steps;
}

int Motor::getStep(){
    return this->step;
}

int Motor::getDir(){
    return this->dir;
}