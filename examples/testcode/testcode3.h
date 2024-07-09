#pragma once
#include "kxnTask.h"
DEFINE_TASK_STATE(kxnTaskLED){
    kxnTaskLED_ON_1TIME,
    kxnTaskLED_OFF_1TIME,
};

void setup(void){
    switch (getState())
    {
        case kxnTaskLED_ON_1TIME:
        digitalWrite(this->pin, 1);
        kDelay(timeDelayON);
        setState(kxnTaskLED_OFF_1TIME);
        break;

        case kxnTaskLED_OFF_1TIME:
        digitalWrite(this->pin, 0);
        stop();
        break;  
    
    default:
        break;
    }

}

void write(unsigned long delayON){
    this->start1();
    this->timeDelayON=delayON;
    setState(kxnTaskLED_ON_1TIME);
}