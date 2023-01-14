#include <Arduino.h>
#include "Motor.h"
#include "MotorController.h"

MotorController::MotorController()
{
    int st, di = 22;
    for (int i = 0; i < maxMotors; i++)
    {
        di = st + 1;
        motoren[i] = Motor(st, di);
        st += 2;
    }

    this->count = 0;
}

MotorController::~MotorController()
{
}

void MotorController::parallelRun()
{
    int maxSteps = 0;
    for (int i = 0; i < maxMotors; i++)
    {
        int s = motoren[i].getSteps();
        if (s > maxSteps)
        {
            maxSteps = s;
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
            int s = motoren[i].getSpeed();
            int d = motoren[i].getSteps();

            if (count % s == 0 && i < d)
            {
                digitalWrite(this->motoren[i].getStep(), HIGH);
            }
        }

        delayMicroseconds(1);
        ++count;

        for (int i = 0; i < maxMotors; i++)
        {
            int s = motoren[i].getSpeed();
            int d = motoren[i].getSteps();

            if (count % s == 0 && i < d)
            {
                digitalWrite(this->motoren[i].getStep(), LOW);
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



/*
#include "Motor.h"
#include <Arduino.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}





void parallelRun(Motor motoren[12])
{
  int maxMotors = 12;
  int maxSteps = 0;
  for (int i = 0; i < maxMotors; i++)
  {
    int s = motoren[i].getSteps();
    if (s > maxSteps)
    {
      maxSteps = s;
    }
  }

  
    motor   speed
    m1      -----   (120)
    m2      ------  (140)
    m3      --      (50)
    m4      ------- (150)
    .
    .



  bool stat = true;
  int count = 0;
  int lock[12] = {
      0,0,0,0,0,0,0,0,0,0,0,0
  };
  for (int i = 0; i < maxSteps; i++)
  {
    Serial.println(count);
    for (int j = 0; j < maxMotors; j++)
    {
      if (lock[j] == 0) {
        int s = motoren[j].getSpeed();
        int d = motoren[j].getSteps();

        if (count % s == 0 && i < d)
        {
          //digitalWrite(motoren[i].getStep(), HIGH);
          Serial.print("motor an: ");
          Serial.println(j);
          lock[j] = 1;

        }
      }
    }

    delayMicroseconds(10);


    for (int j = 0; j < maxMotors; j++)
    {
      if (lock[j] == 1) {


        int s = motoren[j].getSpeed() - 1;
        int d = motoren[j].getSteps();

        if (count % s == 0 && i < d)
        {
          //digitalWrite(motoren[i].getStep(), LOW);
          Serial.print("motor auus: ");
          Serial.println(j);
          lock[j] = 0;
        }
      }
    }

  }

  // loop motoren
  // digitalWrite(i, HIGH);

  // delayMicroseconds

  // loop motoren
  // digitalWrite(i, LOW);
}
Motor motoren[12] = {
  Motor(2000, 150),
  Motor(2000, 10),
  Motor(2000, 120),
  Motor(2000, 110),
  Motor(2000, 170),
  Motor(2000, 20),
  Motor(2000, 350),
  Motor(2000, 450),
  Motor(2000, 150),
  Motor(2000, 150),
  Motor(2000, 150),
  Motor(2000, 150)
};
void loop() {
  // put your main code here, to run repeatedly:


  parallelRun(motoren);

  delay(5000);
}

*/