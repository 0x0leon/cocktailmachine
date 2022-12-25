#include <Arduino.h>

void handle_serial()
{

    if (Serial.available() > 0)
    {
        String commandstring = Serial.readString();

        String c1 = get_command(commandstring, 1);
        Serial.print(commandstring);
        int c = c1.toInt();

        switch (c)
        {
        case 1:
            // motor an
            break;
        case 2:
            // motor aus
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            break;
        }
    }
}

String get_command(String s, int index)
{

    return "test";
}