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
    motoren[i] = new Motor(i+1, dirPin, stepPin);

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
    int maxStepsTodo = 0;
    for (auto i = 0; i < maxMotors; i++)
    {
        int temp = motoren[i].getStepsToDo();
        if(temp > maxStepsTodo){
            maxStepsTodo = temp; 
        }
    }
    
    
    /*
    motor   speed
    m1      -----   (120)
    m2      ------  (140)
    m3      --      (50)
    m4      ------- (150)
    .
    .

    */

    bool stat = true;
    int count = 0;
    for (int i = 0; i < maxSteps; i++)
    {
        for (int i = 0; i < maxMotors; i++)
        {
            int s = motoren[i];
            int d = motoren[i];

            if (count % s == 0 && i < d)
            {
                digitalWrite(this->motoren[i], HIGH);
            }
        }

        delayMicroseconds(1);
        ++count;

        for (int i = 0; i < maxMotors; i++)
        {
            int s = motoren[i];
            int d = motoren[i];

            if (count % s == 0 && i < d)
            {
                digitalWrite(this->motoren[i], LOW);
            }
        }

        ++count;

        delayMicroseconds(1);
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
void MotorController::printMotors(){


    Serial.println("<--- Motoren --->");
    for (auto i = 0; i < maxMotors; i++)
    {
        Serial.print("Motor ID: ");
        Serial.print(this->motoren[i].getID(););

        Serial.print(" Direction Pin: ");
        Serial.print(this->motoren[i].getDirPin());

        Serial.print(" Step Pin: ");
        Serial.print(this->motoren[i].getStepPin());

        Serial.print(" Break between steps: ");
        Serial.println(this->motoren[i].getStepBreak());
    }
    Serial.println("<--------------->");
    
}