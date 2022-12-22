

#include <Arduino.h>

int dir = 23;
int step = 22;
int speed = 170;

void setup()
{

	pinMode(dir, OUTPUT);
	pinMode(step, OUTPUT);
}

void accelerate()
{

	int x = speed;
	for (int i = 1000; i >= speed; i--)
	{
		digitalWrite(step, HIGH);
		delayMicroseconds(i);
		digitalWrite(step, LOW);
		delayMicroseconds(i);
	}
}

void oneStep(){
	digitalWrite(step, HIGH);
	delayMicroseconds(speed);
	digitalWrite(step, HIGH);
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