#pragma once

#include "kxnTask.h"

DEFINE_TASK_STATE(kxnTaskLED){
    kxnTaskLED_ON, kxnTaskLED_ON_repeat,
    kxnTaskLED_OFF,kxnTaskLED_OFF_repeat,
};

CREATE_TASK(kxnTaskLED)
/*Add your variable here*/
uint8_t pin;
unsigned long timeDelayON;
unsigned long timeDelayOFF;
unsigned      repeatTimes;
unsigned int  count;
void setup(uint8_t pin_PA)
{
    this->pin=pin_PA;
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

    case kxnTaskLED_ON_repeat:
        digitalWrite(this->pin, 1);
        kDelay(timeDelayON);
        setState(kxnTaskLED_OFF);
        break;

    case kxnTaskLED_OFF_repeat:
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

void write(unsigned long delayON, unsigned long delayOFF, int repeatTimes){
    this->start();
    this->timeDelayON=delayON;
    this->timeDelayOFF=delayOFF;
    this->repeatTimes=repeatTimes;
    if(this->count==repeatTimes) this->stop();
}
END