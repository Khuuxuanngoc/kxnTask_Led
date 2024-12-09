#pragma once

#include "kxnTask.h"

DEFINE_TASK_STATE(FORTIMES){
    FORTIMES_ON,
    FORTIMES_OFF,
    FORTIMES_IDLE,
};

CREATE_TASK(FORTIMES)
byte pin = 0;
unsigned long timeON = 0, timeOFF = 0;
int8_t count = 0, counts = 0;
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
    case FORTIMES_ON:
        this->LED_ON();
        kDelay(this->timeON);
        setState(FORTIMES_OFF);
        break;

    case FORTIMES_OFF:
        this->LED_OFF();
        kDelay(this->timeOFF);
        if (this->count >= 0 && ++this->counts >= this->count)
            setState(FORTIMES_IDLE);
        else
            setState(FORTIMES_ON);
        break;

    case FORTIMES_IDLE:
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
    setState(FORTIMES_ON);
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

void write(unsigned long timeON, unsigned long timeOFF, int8_t count)
{
    if (this->isRunning())
    {
        if (this->timeON != timeON || this->timeOFF != timeOFF || this->count != count)
        {
            this->resetAllPa();
            this->timeON = timeON;
            this->timeOFF = timeOFF;
            this->count = count;
            this->start();
        }
    }
    else
    {
        this->resetAllPa();
        this->timeON = timeON;
        this->timeOFF = timeOFF;
        this->count = count;
        this->start();
    }
}

void write(unsigned long timeON, unsigned long timeOFF)
{
    write(timeON, timeOFF, -1);
}

void write(unsigned long timeON)
{
    write(timeON, 0, 0);
}

void resetAllPa()
{
    this->timeON = 0;
    this->timeOFF = 0;
    this->count = 0;
    this->counts = 0;
}
bool isRunning()
{
    if (getState() == FORTIMES_ON || getState() == FORTIMES_OFF)

        return true;
    else
        return false;
}
END

    /**
     * y240901
     * 00:00
     * Complete testing in void loop().
     * 00:19
     * Complete testing in void loop() with Serial.
     *
     *
     */