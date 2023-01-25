#include <Arduino.h>
#include "Motor.h"
#include "MotorController.h"

/********************************************************************
 *
 ********************************************************************/
MotorController::MotorController()
{

    int dirPin = 23;
    int stepPin = 22;

    for (auto i = 0; i < maxMotors; i++)
    {
        motoren[i] = Motor(i + 1, dirPin, stepPin);

        dirPin += 2;
        stepPin += 2;
    }
}

/********************************************************************
 *
 ********************************************************************/
MotorController::~MotorController()
{
}

/********************************************************************
*
********************************************************************/
void MotorController::parallelRun()
{
    /*
    
    */
    int maxStepsTodo = 0;
    for (auto i = 0; i < maxMotors; i++)
    {
        int temp = motoren[i].getStepsToDo();
        if (temp > maxStepsTodo)
        {
            maxStepsTodo = temp;
        }
    }

    int timer = 0;
    int x_mode = 1;
    bool run = true;

    while (run)
    {
        /*
            little state mashine for changing motor step high low 

            start ---> motor1 HIGH && mode = 2 ---> motor 1 LOW && mode = 2
        
        */
        switch (x_mode)
        {
        case 1:
            for (auto i = 0; i < maxMotors; i++)
            {
                if (motoren[i].getStepsProcessed() == maxStepsTodo)
                {
                    !run;
                }
                
                else if (timer % motoren[i].getStepBreak() == 0 && motoren[i].getStepsProcessed() <= motoren[i].getStepsProcessed())
                {
                    digitalWrite(motoren[i].getStepPin(), HIGH);
                }
            }
            x_mode = 2;
            break;
        case 2:
            for (auto i = 0; i < maxMotors; i++)
            {
                if (timer % motoren[i].getStepBreak() == 0 && motoren[i].getStepsProcessed() <= motoren[i].getStepsProcessed())
                {
                    digitalWrite(motoren[i].getStepPin(), LOW);

                    motoren[i].addStep();
                }
            }
            x_mode = 1;
            break;
        }

        delayMicroseconds(1);
        timer++;

        // digital write low
    }

    // loop motoren
    // digitalWrite(i, HIGH);

    // delayMicroseconds

    // loop motoren
    // digitalWrite(i, LOW);
}

/********************************************************************
 *
 ********************************************************************/
void MotorController::printMotors()
{

    Serial.println("<--- Motoren --->");
    for (auto i = 0; i < maxMotors; i++)
    {
        Serial.print("Motor ID: ");
        Serial.print(this->motoren[i].getID());

        Serial.print(" Direction Pin: ");
        Serial.print(this->motoren[i].getDirPin());

        Serial.print(" Step Pin: ");
        Serial.print(this->motoren[i].getStepPin());

        Serial.print(" Break between steps: ");
        Serial.println(this->motoren[i].getStepBreak());
    }
    Serial.println("<--------------->");
}