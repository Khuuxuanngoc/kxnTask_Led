#pragma once

#include "kxnTask.h"

DEFINE_TASK_STATE(test_lib_4){
    test_lib_4_ON,
    test_lib_4_OFF,
};

CREATE_TASK(test_lib_4)
/*Add your variable here*/
uint8_t pin;
void setup(uint8_t _pin)
{
    this->pin = _pin;
    pinMode(this->pin, OUTPUT);

    /*Add your code setup here*/
    stop();
}

void loop()
{
    switch (getState())
    {
    case test_lib_4_ON:
        /*code*/
        digitalWrite(this->pin, 1);
        kDelay(1000);
        setState(test_lib_4_OFF);
        break;

    case test_lib_4_OFF:
        digitalWrite(this->pin, 0);
        kDelay(500);
        setState(test_lib_4_ON);
        break;

    default:
        break;
    }
}

void start()
{
    kxnTaskManager.add(this);
    setState(test_lib_4_ON);
}

void stop()
{
    kDelay(0);
    setStateIdle();
}

END

