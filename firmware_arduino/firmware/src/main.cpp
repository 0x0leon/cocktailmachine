#include <Arduino.h>

int dir = 23;
int step = 22;
int speed = 150;

void setup()
{
	Serial.begin(9600);
	pinMode(dir, OUTPUT);
	pinMode(step, OUTPUT);
	Serial.println("lauft");
}

void accelerate()
{

	int x = 0;
	for (int i = 550; i >= speed; i--)
	{
		digitalWrite(step, HIGH);
		delayMicroseconds(i);
		digitalWrite(step, LOW);
		delayMicroseconds(i);
	}

	Serial.println(x);
}

void oneStep(){
	digitalWrite(step, HIGH);
	delayMicroseconds(speed);
	digitalWrite(step, LOW);
	delayMicroseconds(speed);
}


void loop()
{
	// put your main code here, to run repeatedly:
	digitalWrite(dir, LOW);

	accelerate();
	while (true)
	{
		oneStep();
	}
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