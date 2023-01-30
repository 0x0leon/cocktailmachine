#include <Arduino.h>
#include "MotorTest.h"
#include "MotorController.h"
#include "SerialController.h"

int ml100 = 8600;
int ml200 = ml100 * 2;

int dir = 23;
int dir2 = 25;
int dir3 = 27;
int dir4 = 29;

int step = 22;	
int step2 = 24;
int step3 = 26;
int step4 = 28;

int enable = 2;

// int speed = 200;
// int preRun = 1500;

/********************************************************************
 *
 *******************************************************************/
MotorController motorController = MotorController();

void setup()
{
	Serial.begin(9600);
	pinMode(dir, OUTPUT);
	pinMode(dir2, OUTPUT);
	pinMode(dir3, OUTPUT);
	pinMode(dir4, OUTPUT);


	pinMode(step, OUTPUT);
	pinMode(step2, OUTPUT);
	pinMode(step3, OUTPUT);
	pinMode(step4, OUTPUT);

	pinMode(enable, OUTPUT);
	pinMode(13, OUTPUT);

	digitalWrite(dir, LOW);
	digitalWrite(dir2, LOW);
	digitalWrite(dir3, LOW);
	digitalWrite(dir4, LOW);
}


MotorController motorController;
SerialController serialController;
int commands[24];

void loop()
{
	digitalWrite(dir, LOW);
	digitalWrite(dir2, LOW);
	digitalWrite(dir3, LOW);
	digitalWrite(dir4, LOW);

	ParallelTest();
	delay(2000);
	// preLoop();
	digitalWrite(dir, HIGH);
	digitalWrite(dir2, HIGH);
	digitalWrite(dir3, HIGH);
	digitalWrite(dir4, HIGH);

	// while (true)
	// {

	// 	digitalWrite(enable, LOW);

	// 	accelerate();
	// 	makeSteps(ml200);

	// 	digitalWrite(enable, HIGH);
	// 	delay(3000);
		
	// }

	/********************************************************************
 	*
	 *******************************************************************/	

	
	
	for (auto i = 0; i < 24; i++)
	{
		commands[i] = serialController.ProcessedInput[i];
	}
	

	
	
	
	// process command 
	
	/*
	split command into half
	loop over first half and split by space 

	
	*/



}
