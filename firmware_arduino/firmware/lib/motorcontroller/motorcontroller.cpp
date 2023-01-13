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

void parallelAccelerate(int motors[][4], int pre, int speed)
{

	for (int i = pre; i >= speed; i--)
	{
        parallelRun(motors, speed);
	}
}

void parallelRun(int motors[][4], int speed)
{

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
                digitalWrite(motors[i][0], HIGH);

                motors[j][2] += 1;
            }
        }

        delayMicroseconds(speed);

        for (size_t j = 0; j < 12; j++)
        {
            if (motors[j][1] == 1)
            {
                digitalWrite(motors[i][0], LOW);
            }
        }

        delayMicroseconds(speed);
    }
}