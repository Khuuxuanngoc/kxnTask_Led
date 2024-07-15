#pragma once

#include "kxnTask.h"

DEFINE_TASK_STATE(kxnTaskLED){

    kxnTaskLED_ON,
    kxnTaskLED_OFF,
    kxnTaskLED_ON_1TIMES,
    kxnTaskLED_OFF_1TIMES,
    kxnTaskLED_ON_COUNT,
    kxnTaskLED_OFF_COUNT,
    kxnTaskLED_STOP,

    kxnTaskLED_MODE_ON,
    kxnTaskLED_MODE_ON_1TIMES,
    kxnTaskLED_MODE_ON_COUNT,
    kxnTaskLED_MODE_STOP,
    
};

CREATE_TASK(kxnTaskLED)

uint8_t pin;
uint8_t countON = 1;
uint8_t countOFF;
unsigned long timeDelayON;
unsigned long timeDelayOFF;
uint8_t LED_mode;

void setup(uint8_t pin_PA)
{

    this->pin = pin_PA;
    pinMode(this->pin, OUTPUT);
    digitalWrite(this->pin, 0);
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
        this->stop();
        break;

    case kxnTaskLED_ON_COUNT:
        digitalWrite(this->pin, 1);
        kDelay(timeDelayON);
        setState(kxnTaskLED_OFF_COUNT);
        break;

    case kxnTaskLED_OFF_COUNT:

        if (this->countON < this->countOFF)
        {
            digitalWrite(this->pin, 0);
            kDelay(timeDelayOFF);
            this->countON++;
            setState(kxnTaskLED_ON_COUNT);
        }
        else
        {
            digitalWrite(this->pin, 0);
            kDelay(timeDelayOFF);
            this->countON = 1;
            setState(kxnTaskLED_STOP);
        }
        break;

    case kxnTaskLED_STOP:

        this->stop();

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
    this->LED_mode = kxnTaskLED_MODE_STOP;
    kDelay(0);
    setStateIdle();
}

void write(unsigned long delayON, unsigned long delayOFF)
{
    if (this->LED_mode != kxnTaskLED_MODE_ON)
    {
        this->start();
        this->LED_mode = kxnTaskLED_MODE_ON;
        setState(kxnTaskLED_ON);
        this->timeDelayON = delayON;
        this->timeDelayOFF = delayOFF;
    }
}

void write(unsigned long delayON, unsigned long delayOFF, uint8_t countOFF)
{
    if (this->LED_mode != kxnTaskLED_MODE_ON_COUNT)
    {
        this->LED_mode = kxnTaskLED_MODE_ON_COUNT;
        this->countOFF = countOFF;
        this->start();
        setState(kxnTaskLED_ON_COUNT);
        this->timeDelayON = delayON;
        this->timeDelayOFF = delayOFF;
    }
}

void write(unsigned long delayON)
{
    if (this->LED_mode != kxnTaskLED_MODE_ON_1TIMES)
    {
        this->LED_mode = kxnTaskLED_MODE_ON_1TIMES;
        this->start();
        setState(kxnTaskLED_ON_1TIMES);
        this->timeDelayON = delayON;
    }
}

bool isRunning()
{
    if 
    (
        this->LED_mode == kxnTaskLED_MODE_ON ||
        this->LED_mode == kxnTaskLED_MODE_ON_1TIMES ||
        this->LED_mode == kxnTaskLED_MODE_ON_COUNT
    )
        return true;
    else
        return false;
}

END
