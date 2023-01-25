#ifndef MOTOR_H_
#define MOTOR_H_



class Motor
{
private:
    int id, dirPin, stepPin, stepsToDo, stepsProcessed, stepBreak;

public:
    Motor(int id, int dirPin, int stepPin);
    ~Motor();

    void setID(int id);
    int getID();

    void setDirPin(int dirPin);
    int getDirPin();

    void setStepPin(int stepPin);
    int getStepPin();

    void setStepsToDo(int steps);
    int getStepsToDo();

    void setStepsProcessed(int steps);
    int getStepsProcessed();

    void setStepBreak(int micosecs);
    int getStepBreak();

    void addStep();
    
};

#endif
