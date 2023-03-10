#include "Motor.h"


/********************************************************************
*
********************************************************************/
Motor::Motor(){}

/********************************************************************
*
********************************************************************/
Motor::Motor(int id, int dirPin, int stepPin)
{
    this->id = id;
    this->dirPin=dirPin;
    this->stepPin=stepPin;

    this->stepsProcessed = 0;
}

/********************************************************************
*
********************************************************************/
Motor::~Motor()
{
}

/********************************************************************
*
********************************************************************/
void Motor::setID(int id){
    this->id = id;
}

/********************************************************************
*
********************************************************************/
int Motor::getID(){
    return this->id;
}

/********************************************************************
*
********************************************************************/
void Motor::setDirPin(int dirPin){
    this->dirPin = dirPin;
}

/********************************************************************
*
********************************************************************/
int Motor::getDirPin(){
    return this->dirPin;
}

/********************************************************************
*
********************************************************************/
void Motor::setStepPin(int stepPin){
    this->stepPin = stepPin;
}

/********************************************************************
*
********************************************************************/
int Motor::getStepPin(){
    return this->stepPin;
}

/********************************************************************
*
********************************************************************/
void Motor::setStepsToDo(int stepsToDo){
    this->stepsToDo = stepsToDo;
}

/********************************************************************
*
********************************************************************/
int Motor::getStepsToDo(){
    return this->stepsToDo;
}

/********************************************************************
*
********************************************************************/
void Motor::setStepsProcessed(int steps){
    this->stepsProcessed = steps;
}

/********************************************************************
*
********************************************************************/
int Motor::getStepsProcessed(){
    return this->stepsProcessed;
}

/********************************************************************
*
********************************************************************/
void Motor::setStepBreak(int micsec){
    this->stepBreak = micsec;
}

/********************************************************************
*
********************************************************************/
int Motor::getStepBreak(){
    return this->stepBreak;
}

/********************************************************************
*
********************************************************************/
void Motor::addStep(){
    this->stepsProcessed += 1;
}