#include <ArduinoSTL.h>
#include "Motor.h"

class MotorController
{
private:
    /* data */
    std::vector<Motor> motoren;
public:
    MotorController(/* args */);
    ~MotorController();
};

MotorController::MotorController(/* args */)
{
}

MotorController::~MotorController()
{
}
