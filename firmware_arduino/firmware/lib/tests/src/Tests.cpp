#include <Arduino.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}


void parallelRun(int motors[12][4], int speed)
{
  /*
          ---- {pin, on/off, steps, processedSteps}
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

  Serial.println(maxSteps);
  // loop outer motornumber
  for (size_t i = 0; i < maxSteps; i++)
  {
    for (size_t j = 0; j < 12; j++)
    {
      if (motors[j][1] == 1) {
        if (i < motors[j][2])
        {
          // digitalWrite(motors[i][0], HIGH);
          motors[j][3] += 1;
          /*
            Serial.print("Motor: ");
            Serial.print(j);
            Serial.print(" mode: ");
            Serial.print(motors[j][1]);
            Serial.print(" steps: ");
            Serial.print(motors[j][2]);
            Serial.print(" stepsDone: ");
            Serial.println(motors[j][3]);
          */
        } else {
          motors[j][1] = 0;

        }
      }
    }

    delayMicroseconds(speed);

    for (size_t j = 0; j < 12; j++)
    {
      // digitalWrite(motors[i][0], LOW);
    }


  }
}


void notParallel(int motors[12][4], int speed) {
  for (size_t i = 0; i < 12; i++) {
    for (size_t j = 0; j < motors[i][2]; j++) {
      motors[j][3] += 1;
      // make step
      delayMicroseconds(speed);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("test");


  int motors1[12][4] = {
    {0, 1, 10, 0},
    {1, 1, 10, 0},
    {2, 1, 10, 0},
    {3, 1, 12, 0},
    {4, 1, 3, 0},
    {5, 1, 2, 0},
    {6, 1, 13, 0},
    {7, 1, 10, 0},
    {8, 1, 9, 0},
    {9, 1, 3, 0},
    {10, 1, 1, 0},
    {11, 1, 2, 0}
  };

  int motors2[12][4] = {
    {0, 1, 10, 0},
    {1, 1, 10, 0},
    {2, 1, 10, 0},
    {3, 1, 12, 0},
    {4, 1, 3, 0},
    {5, 1, 2, 0},
    {6, 1, 13, 0},
    {7, 1, 10, 0},
    {8, 1, 9, 0},
    {9, 1, 3, 0},
    {10, 1, 1, 0},
    {11, 1, 2, 0}
  };

  long start1 = micros();
  parallelRun(motors1, 220);
  long end1 = micros();
  long dif1 = end1 - start1;

  long start2 = micros();
  notParallel(motors2, 220);
  long end2 = micros();
  long dif2 = end2 - start2;

  Serial.print("time elapsed parallel: ");
  Serial.println(dif1);
  Serial.print("time elapsed non parallel: ");
  Serial.println(dif2);

  float fact = (dif2 / dif1);

  Serial.print(fact);
  Serial.println(" mal schneller");
  delay(2000);

}
