#pragma once

#include "kxnTask.h"

DEFINE_TASK_STATE(kxnTaskLED){
    kxnTaskLED_ON,
    kxnTaskLED_OFF,
};

CREATE_TASK(kxnTaskLED)
/*Add your variable here*/
uint8_t pin;
unsigned long timeDelayON;
unsigned long timeDelayOFF;

void setup(uint8_t pin_PA)
{
    /*Add your code setup here*/
    this->pin=pin_PA;
    pinMode(this->pin, OUTPUT);
    stop();
}

void loop()
{
    switch (getState())
    {
    case kxnTaskLED_ON:
        /*code*/
        digitalWrite(this->pin, 1);
        kDelay(timeDelayON);
        setState(kxnTaskLED_OFF);
        break;

    case kxnTaskLED_OFF:
        /*code*/
        digitalWrite(this->pin, 0);
        kDelay(timeDelayOFF);
        setState(kxnTaskLED_ON);
        break;

    default:
        break;
    }
}

void start()
{
    kxnTaskManager.add(this);
    setState(kxnTaskLED_ON);
}

void stop()
{
    kDelay(0);
    setStateIdle();
}
void write(unsigned long delayON, unsigned long delayOFF){
    this->start();
    this->timeDelayON=delayON;
    this->timeDelayOFF=delayOFF;
}
END