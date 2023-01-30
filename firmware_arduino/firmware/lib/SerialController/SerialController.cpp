#include "SerialController.h"

#include <Arduino.h>
#include <string.h>


SerialController::SerialController(/* args */)
{
}

SerialController::~SerialController()
{
}

void SerialController::processSerialInput()
{

    while (Serial.available() == 0){}

    String command;
    if (Serial.available())
    {
        // end string with newline character
        delay(2);
        command = Serial.readStringUntil('\n');
    }

    //____________________________________________
    int size = 1;
    for (auto i = 0; i < command.length(); i++)
    {
        if (command.charAt(i) == ' ')
        {
            size++;
        }
    }
    //____________________________________________

    char *token;
    char *delimiter = " ";

    int Arr[size];
    int index = 0;

    char *com = new char[ command.length() ];
    strcpy(com, command.c_str());

    token = strtok(com, delimiter);
    while (token != NULL)
    {
        Serial.println(token);
        Arr[index] = atoi(token);
        token = strtok(NULL, delimiter);
        ++index;
    }
    Serial.println();

    

    //_____________________________________________________
    Serial.println("Motor Step Array from command: ");
    Serial.print("\t");
    Serial.print("MotorID: ");
    Serial.print("\t\t");
    Serial.println("Steps: ");

    for (byte i = 0; i < size / 2; i++)
    {
        Serial.print("\t");
        Serial.print(Arr[i]);
        Serial.print("\t\t\t");
        Serial.print(Arr[i + (size / 2)]);
        Serial.println();

    }
    //_____________________________________________________

    
}