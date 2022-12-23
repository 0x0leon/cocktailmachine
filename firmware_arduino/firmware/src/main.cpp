#include <Arduino.h>

int dir = 23;
int step = 22;
int speed = 200;

void setup()
{
	Serial.begin(9600);
	pinMode(dir, OUTPUT);
	pinMode(step, OUTPUT);
	Serial.println("lauft");
}
void accelerate()
{

	for (int i = 1000; i >= speed; i--)
	{
		digitalWrite(step, HIGH);
		delayMicroseconds(i);
		digitalWrite(step, LOW);
		delayMicroseconds(i);
	}
}
void oneStep()
{
	digitalWrite(step, HIGH);
	delayMicroseconds(speed);
	digitalWrite(step, LOW);
	delayMicroseconds(speed);
}

void makeSteps(int steps)
{
	for (int i = 0; i < steps; i++)
	{
		oneStep();
	}
}

void fill_ml(int ml)
{
	digitalWrite(dir, LOW);
	int ml100 = 8600;

	accelerate();

	for (int i = 0; i < ml; i++)
	{
		for (int x = 0; x < ml100; x++)
		{
			oneStep();
		}
		
	}
}

void pull_ml(int ml)
{
	digitalWrite(dir, HIGH);
	int ml100 = 8600;

	accelerate();

	for (int i = 0; i < ml; i++)
	{
		for (int x = 0; x < ml100; x++)
		{
			oneStep();
		}
		
	}
}

void test()
{
	int s = 8800;
	delay(2000);
	// put your main code here, to run repeatedly:
	digitalWrite(dir, LOW);
	accelerate();
	// 122
	// makeSteps(10000);

	makeSteps(s);
	delay(2000);

	// put your main code here, to run repeatedly:
	digitalWrite(dir, HIGH);
	accelerate();
	// 122
	// makeSteps(10000);
	// 100 - 8600
	makeSteps(s);
	delay(2000);
}

void loop()
{

	//test();

}

/*
#include <Arduino.h>
#include <AccelStepper.h>



AccelStepper stepper = AccelStepper(AccelStepper::DRIVER, 22, 23 );

void setup(){

}


void loop(){

}
*/