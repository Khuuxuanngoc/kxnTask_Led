#pragma once

#include "kxnTask.h"

DEFINE_TASK_STATE(ONETIMES){
    ONETIMES_ON,
    ONETIMES_OFF,
    ONETIMES_IDLE,
};

CREATE_TASK(ONETIMES)
byte pin = 0;
unsigned long timeON = 0;
bool level = 1;

void setup(byte pin)
{
    this->pin = pin;
    pinMode(this->pin, OUTPUT);
    this->resetAllPa();
    stop();
}

void setup(byte pin, bool level)
{
    this->pin = pin;
    this->level = level;
    pinMode(this->pin, OUTPUT);
    this->resetAllPa();
    stop();
}
void loop()
{
    switch (getState())
    {
    case ONETIMES_ON:
        this->LED_ON();
        kDelay(this->timeON);
        setState(ONETIMES_OFF);
        break;

    case ONETIMES_OFF:
        this->LED_OFF();
        kDelay(0);
        setState(ONETIMES_IDLE);
        break;

    case ONETIMES_IDLE:
        this->resetAllPa();
        this->stop();
        break;
    default:
        break;
    }
}

void start()
{
    kxnTaskManager.add(this);
    setState(ONETIMES_ON);
}

void stop()
{
    kDelay(0);
    setStateIdle();
}
void LED_ON()
{
    if (this->level)

        digitalWrite(this->pin, this->level);
    else
        digitalWrite(this->pin, !this->level);
}

void LED_OFF()
{
    if (!this->level)

        digitalWrite(this->pin, this->level);
    else
        digitalWrite(this->pin, !this->level);
}

void write(unsigned long timeON)
{
    if (this->isRunning())
    {
        if (this->timeON != timeON)
        {
            this->timeON = timeON;
            this->start();
        }
    }
    else
    {
        this->timeON = timeON;
        this->start();
    }
}
void resetAllPa()
{
    this->level = 1;
    this->timeON = 0;
}
bool isRunning()
{
    if (getState() == ONETIMES_ON || getState() == ONETIMES_OFF)

        return true;
    else
        return false;
}
END