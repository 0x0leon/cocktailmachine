#include <Arduino.h>

int ml100 = 8600;
int ml200 = ml100 * 2;

int dir = 23;
int step = 22;
int enable = 2;

int speed = 200;
int preRun = 1500;

void setup()
{
	Serial.begin(9600);
	pinMode(dir, OUTPUT);
	pinMode(step, OUTPUT);
	pinMode(enable, OUTPUT);
	Serial.println("lauft");
}
void accelerate()
{

	for (int i = preRun; i >= speed; i--)
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
	

	accelerate();

	for (int i = 0; i < ml; i++)
	{
		makeSteps(ml100);
	}
}

void pull_ml(int ml)
{
	digitalWrite(dir, HIGH);

	accelerate();

	for (int i = 0; i < ml; i++)
	{
		makeSteps(ml100);
	}
}

void test()
{
	// 122
	// makeSteps(10000);
	// 100 - 8600


	delay(2000);

	// change direction
	digitalWrite(dir, LOW);

	accelerate();

	makeSteps(ml200);
	delay(2000);

	// change direction
	digitalWrite(dir, HIGH);

	accelerate();

	makeSteps(ml100);
	delay(2000);
}

void processSerial()
{
	if (Serial.available() > 0)
	{
		String command = Serial.readString();
		Serial.println(command);
		if (command.equals("on"))
		{
			accelerate();
			makeSteps(8600);
			Serial.write("ended\n");
		}
		else if (command.equals("off"))
		{
			digitalWrite(step, LOW);
		}
	}
}

void preLoop()
{
	// enable board
	digitalWrite(enable, LOW);
}


void loop()
{
	preLoop();

	while (true)
	{

		digitalWrite(enable, LOW);

		accelerate();
		makeSteps(ml200);

		digitalWrite(enable, HIGH);
		delay(3000);
		
	}
	
}
