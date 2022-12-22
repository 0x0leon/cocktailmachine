#include <Arduino.h>
#include <AccelStepper.h>

int dir = 23;
int step = 22;
int speed = 250;

void setup()
{

	pinMode(dir, OUTPUT);
	pinMode(step, OUTPUT);
}

void accelerate()
{
	for (int i = 1200; i > speed; i--)
	{
		digitalWrite(step, HIGH);
		delayMicroseconds(i);
		digitalWrite(step, LOW);
		delayMicroseconds(i);
	}
}


void loop()
{
	// put your main code here, to run repeatedly:
	digitalWrite(dir, LOW);

	accelerate();
	while (true)
	{
		digitalWrite(step, HIGH);
		delayMicroseconds(speed);
		digitalWrite(step, LOW);
		delayMicroseconds(speed);
	}
}
