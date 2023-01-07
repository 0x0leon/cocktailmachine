#include <Arduino.h>
#include "motorcontroller.h"

/**********************************************************
 * step
 * multiple_steps
 **********************************************************/

void step()
{
}

void multiple_steps(int steps)
{
}

void parallelRun(int motors[12][4], int speed)
{
    /*
    motors-array:
        {
            ---- {pin, on/off, steps, processedSteps}
            {1,0,ml, x}, {2,0,ml}, {3,0,ml},
            {4,0,ml}, {5,0,ml}, {6,0,ml},
            {7,0,ml}, {8,0,ml},{9,0,ml},
            {10,0,ml}, {11,0,ml}
        }


        1. sort entries by steps (8600, 5002, 22001) descending
        2. take longest as count and check if processed steps matching
    */

    // find max steps in array
    int maxSteps = 0;
    for (size_t i = 0; i < 12; i++)
    {
        if (motors[i][2] > maxSteps)
        {
            maxSteps = motors[i][2];
        }
    }

    // loop outer motornumber
    for (size_t i = 0; i < maxSteps; i++)
    {
        for (size_t j = 0; j < 12; j++)
        {
            if (motors[j][1] == 1 && i <= motors[j][2])
            {
                Serial.print("motor: ");
                Serial.print(j);
                Serial.println(" on");
                // digitalWrite(motors[i][0], HIGH);

                motors[j][2] *= 1;
            }
        }

        delayMicroseconds(speed);

        for (size_t j = 0; j < 12; j++)
        {
            Serial.print("motor: ");
            Serial.print(j);
            Serial.println(" off");
        }
    }
}