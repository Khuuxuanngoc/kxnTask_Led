#pragma once

#include "kxnTask.h"

DEFINE_TASK_STATE(blinkforever){
    kxnTaskLED_ON,
    kxnTaskLED_OFF,
};

CREATE_TASK(blinkforever)
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

void write(unsigned long delayON, unsigned long delayOFF)
{
    this->start();
    this->timeDelayON = delayON;
    this->timeDelayOFF = delayOFF;
}

END
    /**
     * modified at 2024/07/08
     * delete test led on 1 times
     * create testcode3.h
     */
    DEFINE_TASK_STATE(blinkHasRepeat){
        kxnTaskLED_ON,
        kxnTaskLED_OFF,
        kxnTaskLED_COUNT,
    };

CREATE_TASK(blinkHasRepeat)
/*Add your variable here*/
uint8_t pin;
unsigned long timeDelayON;
unsigned long timeDelayOFF;
unit8_t count = 0;

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
        setState(kxnTaskLED_COUNT);
        break;

    case kxnTaskLED_OFF:
        digitalWrite(this->pin, 0);
        kDelay(timeDelayOFF);
        setState(kxnTaskLED_ON);
        break;

    case kxnTaskLED_COUNT:
    this->count++;
        setState(kxnTaskLED_OFF);
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

void write(unsigned long delayON, unsigned long delayOFF, uint8_t limit)
{
    this->timeDelayON = delayON;
    this->timeDelayOFF = delayOFF;
    if (this->count < limit) this->start();
    else this->stop
}
    END