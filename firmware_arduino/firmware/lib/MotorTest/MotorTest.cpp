#include <Arduino.h>
#include "MotorTest.h"
#include "motorcontroller.h"

// {pin, on/off, steps, processedSteps}
void ParallelTest()
{

    int preSpeed = 2000;
    int speed = 170;

    int testSet[][4] = {
        {22, 1, 2000, 0},
        {24, 1, 2000, 0},
        {26, 1, 2000, 0},
        {28, 1, 2000, 0}};

    // parallelAccelerate(testSet, preSpeed, speed);
    for (int i = preSpeed; i >= speed; i--)
    {
        digitalWrite(testSet[0][0], HIGH);
        digitalWrite(testSet[1][0], HIGH);
        digitalWrite(testSet[2][0], HIGH);
        digitalWrite(testSet[3][0], HIGH);

        delayMicroseconds(i);
        // parallelRun(testSet, speed);
        digitalWrite(testSet[0][0], LOW);
        digitalWrite(testSet[1][0], LOW);
        digitalWrite(testSet[2][0], LOW);
        digitalWrite(testSet[3][0], LOW);
        // delay(3000);
        delayMicroseconds(i);
    }

    while (true)
    {

        digitalWrite(testSet[0][0], HIGH);
        digitalWrite(testSet[1][0], HIGH);
        digitalWrite(testSet[2][0], HIGH);
        digitalWrite(testSet[3][0], HIGH);
        delayMicroseconds(speed);
        // parallelRun(testSet, speed);
        digitalWrite(testSet[0][0], LOW);
        digitalWrite(testSet[1][0], LOW);
        digitalWrite(testSet[2][0], LOW);
        digitalWrite(testSet[3][0], LOW);
        // delay(3000);
        delayMicroseconds(speed);
    }
}