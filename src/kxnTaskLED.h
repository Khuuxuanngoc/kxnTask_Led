#pragma once

#include "kxnTask.h"

DEFINE_TASK_STATE(kxnTaskLED){
    kxnTaskLED_ON,
    kxnTaskLED_OFF,
    kxnTaskLED_ON_1TIMES,
    kxnTaskLED_OFF_1TIMES,
};

CREATE_TASK(kxnTaskLED)
/*Add your variable here*/
uint8_t pin;
unsigned long timeDelayON;
unsigned long timeDelayOFF;
enum state
{
    blynkforever,
    blynkthenstop,
    on1times
};

void setup(uint8_t pin_PA)
{
    this->pin = pin_PA;
    pinMode(this->pin, OUTPUT);
    stop();
}

void loop()
{
    switch (this->state)
    {
    case blynkforever:

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

        break;
    case on1times:

        switch (getState())
        {
        case kxnTaskLED_ON_1TIMES:
            digitalWrite(this->pin, 1);
            kDelay(timeDelayON);
            setState(kxnTaskLED_OFF_1TIMES);
            break;

        case kxnTaskLED_OFF_1TIMES:
            digitalWrite(this->pin, 0);
            stop();
            break;

        default:
            break;
        }

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

void writeOnForever(unsigned long delayON, unsigned long delayOFF)
{
    setState(kxnTaskLED_ON);
    this->start();
    this->timeDelayON = delayON;
    this->timeDelayOFF = delayOFF;
}

void writeOn1times(unsigned long delayON, unsigned long delayOFF)
{
    setState(kxnTaskLED_ON_1TIMES);
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
