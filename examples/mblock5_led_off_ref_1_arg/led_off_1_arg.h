#pragma once

#include "kxnTask.h"

void setPin(int tempPin);
void start();
void stop();

DEFINE_TASK_STATE(led_off_1_arg){
    led_off_1_arg_OFF,
};
CREATE_TASK(led_off_1_arg)

/*Add your variable here*/



uint8_t pin;

void setup()
{
    /*Add your code setup here*/
    pinMode(pin, OUTPUT);
    stop();
}

void loop()
{
    switch (getState())
    {
    case led_off_1_arg_OFF:
        /*code*/
        digitalWrite(pin, 0);
        kDelay(0);
        break;

    default:
        break;
    }
}

void setPin(int tempPin){
  this->pin = tempPin;
}

void start()
{
    kxnTaskManager.add(this);
    setState(led_off_1_arg_OFF);
}

void stop()
{
    kDelay(0);
    setStateIdle();
}

END