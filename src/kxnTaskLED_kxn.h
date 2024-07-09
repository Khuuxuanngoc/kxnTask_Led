#pragma once

#include "kxnTask.h"

DEFINE_TASK_STATE(kxnTaskLED){
    kxnTaskLED_ON,
    kxnTaskLED_OFF,
    kxnTaskLED_ON_1TIME,
    kxnTaskLED_OFF_1TIME,
};

CREATE_TASK(kxnTaskLED)
/*Add your variable here*/
uint8_t pin;
unsigned long timeDelayON;
unsigned long timeDelayOFF;

void setup(uint8_t pin_PA)
{
    this->pin = pin_PA;
    pinMode(this->pin, OUTPUT);
    stop();
}

void loop()
{
    switch (getState())
    {
    case kxnTaskLED_ON:
        digitalWrite(this->pin, 1);
        kDelay(timeDelayON);
        setState(kxnTaskLED_OFF);
        break;

    case kxnTaskLED_OFF:
        digitalWrite(this->pin, 0);
        kDelay(timeDelayOFF);
        setState(kxnTaskLED_ON);
        break;

    case kxnTaskLED_ON_1TIME:
        digitalWrite(this->pin, 1);
        kDelay(timeDelayON);
        setState(kxnTaskLED_OFF_1TIME);
        break;

    case kxnTaskLED_OFF_1TIME:
        digitalWrite(this->pin, 0);
        setStateStop();
        break;

    default:
        break;
    }
}

void start()
{
    kxnTaskManager.add(this);
}

void stop()
{
    kDelay(0);
    setStateIdle();
}

void write(unsigned long delayON, unsigned long delayOFF)
{
    this->start();
    setState(kxnTaskLED_ON);
    this->timeDelayON = delayON;
    this->timeDelayOFF = delayOFF;
}

void write(unsigned long delayON)
{
    this->start();
    setState(kxnTaskLED_ON_1TIME);
    this->timeDelayON = delayON;
}

END
    /**
     * modified at 2024/07/08
     * delete test led on 1 times
     * create testcode3.h
     */
