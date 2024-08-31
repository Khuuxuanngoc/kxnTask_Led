#pragma once

#include "kxnTask.h"

DEFINE_TASK_STATE(FOREVER){
    FOREVER_ON,
    FOREVER_OFF,
    FOREVER_IDLE,
};

CREATE_TASK(FOREVER)
byte pin = 0;
unsigned long timeON = 0, timeOFF = 0;
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
    case FOREVER_ON:
        this->LED_ON();
        kDelay(this->timeON);
        setState(FOREVER_OFF);
        break;

    case FOREVER_OFF:
        this->LED_OFF();
        kDelay(this->timeOFF);
        setState(FOREVER_ON);
        break;

    case FOREVER_IDLE:
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
    setState(FOREVER_ON);
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

void write(unsigned long timeON, unsigned long timeOFF)
{
    if (this->isRunning())
    {
        if (this->timeON != timeON || this->timeOFF != timeOFF)
        {
            this->timeON = timeON;
            this->timeOFF = timeOFF;
            this->start();
        }
    }
    else
    {
        this->resetAllPa();
        this->timeON = timeON;
        this->timeOFF = timeOFF;
        this->start();
    }
}
void resetAllPa()
{
    this->level = 1;
    this->timeON = 0;
    this->timeOFF = 0;
}
bool isRunning()
{
    if (getState() == FOREVER_ON || getState() == FOREVER_OFF)

        return true;
    else
        return false;
}
END