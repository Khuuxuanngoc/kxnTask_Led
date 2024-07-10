#pragma once

#include "kxnTask.h"

DEFINE_TASK_STATE(kxnTaskLED){
    kxnTaskLED_ON,
    kxnTaskLED_OFF,
    kxnTaskLED_ON_1TIMES,
    kxnTaskLED_OFF_1TIMES,
    kxnTaskLED_ON_COUNT,
    kxnTaskLED_OFF_COUNT,
};

CREATE_TASK(kxnTaskLED)
/*Add your variable here*/
uint8_t pin;
uint8_t countON = 0;
uint8_t countOFF;
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

    case kxnTaskLED_ON_1TIMES:
        digitalWrite(this->pin, 1);
        kDelay(timeDelayON);
        setState(kxnTaskLED_OFF_1TIMES);
        break;

    case kxnTaskLED_OFF_1TIMES:
        digitalWrite(this->pin, 0);
        setStateStop();
        break;

    case kxnTaskLED_ON_COUNT:
        digitalWrite(this->pin, 1);
        kDelay(timeDelayON);
        setState(kxnTaskLED_OFF_COUNT);
        break;

    case kxnTaskLED_OFF_COUNT:

        if (this->countON <= this->countOFF)
        {
            digitalWrite(this->pin, 0);
            kDelay(timeDelayOFF);
            this->countON++;
            setState(kxnTaskLED_ON_COUNT);
        }
        else
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

void write(unsigned long delayON, unsigned long delayOFF, uint8_t countOFF)
{
    this->countOFF == countOFF;
    this->start();
    setState(kxnTaskLED_ON);
    this->timeDelayON = delayON;
    this->timeDelayOFF = delayOFF;
}

void write(unsigned long delayON)
{
    this->start();
    setState(kxnTaskLED_ON_1TIMES);
    this->timeDelayON = delayON;
}

END
