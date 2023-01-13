#ifndef MOTORCONTROLLER_H_
#define MOTORCONTROLLER_H_


void setup();
void step();
void multiple_steps(int steps);
void parallelAccelerate(int motors[][4], int pre, int speed);
void parallelRun(int motors[][4], int speed);
#endif 