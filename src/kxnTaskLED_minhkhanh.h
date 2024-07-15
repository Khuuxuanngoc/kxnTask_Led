#pragma once

#include "kxnTask.h"

DEFINE_TASK_STATE(kxnTaskLED){
    kxnTaskLED_ON,
    kxnTaskLED_OFF,
    kxnTaskLED_ON_1TIMES,
    kxnTaskLED_OFF_1TIMES,
    kxnTaskLED_ON_COUNT,
    kxnTaskLED_OFF_COUNT,

    kxnTaskLED_MODE_ON,
    kxnTaskLED_MODE_ON_1TIMES,
    kxnTaskLED_MODE_ON_COUNT,
    // kxnTaskLED_check_status,
};

CREATE_TASK(kxnTaskLED)
/*Add your variable here*/
uint8_t pin;
uint8_t countON = 1;
uint8_t countOFF;
uint8_t state;
uint8_t ON = 1;
uint8_t OFF = 0;
unsigned long timeDelayON;
unsigned long timeDelayOFF;
uint8_t LED_mode;

void setup(uint8_t pin_PA)
{

    // Serial.begin(9600);
    // Serial.println("DANG TRONG HAM SETUP");

    this->pin = pin_PA;
    pinMode(this->pin, OUTPUT);
    digitalWrite(this->pin, 0);
    this->state = this->OFF;
    stop();
}

void loop()
{

    // Serial.println("DANG TRONG HAM LOOP");

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

        // Serial.begin(9600);
        // Serial.println("DANG TRONG HAM kxnTaskLED_OFF_COUNT");
        if (this->countON < this->countOFF)
        {
            digitalWrite(this->pin, 0);
            this->state = this->OFF;
            kDelay(timeDelayOFF);
            this->countON++;
            setState(kxnTaskLED_ON_COUNT);
        }
        else
        {
            digitalWrite(this->pin, 0);
            setStateStop();
        }
        break;

    // case kxnTaskLED_check_status:
    //     if (this->state == this->ON)
    //         return true;
    //     else
    //         return false;
    //     break;
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
    this->state = this->OFF;
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
        this->state = this->ON;
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
    this->state = this->ON;
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
    this->state = this->ON;
    setState(kxnTaskLED_ON_1TIMES);
    this->timeDelayON = delayON;
    }
}

bool isRunning()
{
    if (this->state == this->ON)
        return true;
    else
        return false;

    // this->start();
    // setState(kxnTaskLED_check_status);
    // while (this->state==this->ON)
    // {
    //     return true;
    //     break;
    // }
    // while (this->state==this->OFF)
    // {
    //     return false;
    //     break;
    // }
}

END
