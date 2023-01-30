#include <Arduino.h>

#ifndef SERIAL_H // include guard
#define SERIAL_H

class SerialController
{
private:
    
    
public:
    
    SerialController();
    ~SerialController();

    int ProcessedInput[24];
    void processSerialInput();
    
};


#endif