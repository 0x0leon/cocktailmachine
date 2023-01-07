#ifndef MOTORCONTROLLER_H_
#define MOTORCONTROLLER_H_


void setup();
void step();
void multiple_steps(int steps);
void parallelRun(int motors[12][3], int speed);
#endif 