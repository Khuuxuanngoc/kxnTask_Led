#pragma once

#include "kxnTask.h"

DEFINE_TASK_STATE(test_lib_2){
    test_lib_2_ON,
    test_lib_2_OFF,
};

CREATE_TASK(test_lib_2)
/*Add your variable here*/
typedef unsigned long ul32_t;
uint8_t LED_pin, count_repeat;
ul32_t time_on, time_off, last_time_on, last_time_off;

void setup(uint8_t _pin)
{
    /*Add your code setup here*/
    pinMode(this->LED_pin, OUTPUT);
    this->led_off();
    stop();
}

void loop()
{
    switch (getState())
    {
    case test_lib_2_ON:
        /*code*/
        this->led_on();
        kDelay(this->time_on);
        setState(test_lib_2_OFF);
        break;

    case test_lib_2_OFF:
        /*code*/
        this->led_off();
        kDelay(this->time_off);
        // setState(test_lib_2_ON);
        if (isLED_on_1_times())
        {
            setStateIdle();
        }

        break;

    default:
        break;
    }
}

void start()
{
    kxnTaskManager.add(this);
    setState(test_lib_2_ON);
}

void stop()
{
    kDelay(0);
    setStateIdle();
}

void led_on()
{
    digitalWrite(this->LED_pin, 1);
}

void led_off()
{
    digitalWrite(this->LED_pin, 0);
}

bool isRunning()
{
    if (getState() == test_lib_2_ON || getState() == test_lib_2_OFF)
        return true;
    else
        return false;
}

void write(ul32_t _time_on)
{
    // this->last_time_on=this->time_on;
    // this->time_on=_time_on;
    if (!this->isRunning())
    {
        this->time_on = _time_on;
        this->start();
    }
    else if (this->time_on != _time_on)
    {
        this->time_on = _time_on;
        this->start();
    }
}

bool isLED_on_1_times()
{
    return true;
}
END