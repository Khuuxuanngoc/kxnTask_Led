#ifndef kxnTaskLEDdemo1_h
#define kxnTaskLEDdemo1_h
#include "kxnTaskLED.h"
#include "kxnTask.h"

DEFINE_TASK_STATE(kxnTaskLEDdemo1){
    kxnTaskLEDdemo1_DEMO_1,
    kxnTaskLEDdemo1_DEMO_2,
    kxnTaskLEDdemo1_DEMO_3,

};

CREATE_TASK(kxnTaskLEDdemo1)
#define PIN_LED_RED 10    // connect led with 220 or 330 ohm resistor into pin 10 of Arduino board.
#define PIN_LED_GREEN 11  // connect led with 220 or 330 ohm resistor into pin 11 of Arduino board.
#define PIN_LED_YELLOW 12 // connect led with 220 or 330 ohm resistor into pin 12 of Arduino board.

kxnTaskLED kxnTaskLED1;
kxnTaskLED kxnTaskLED2;
kxnTaskLED kxnTaskLED3;

void setup(void)
{
    kxnTaskLED1.setup(PIN_LED_RED);
    kxnTaskLED2.setup(PIN_LED_GREEN);
    kxnTaskLED3.setup(PIN_LED_YELLOW);
    setState(kxnTaskLEDdemo1_DEMO_1);
    kxnTaskManager.add(this);
}
void loop(void)
{
    switch (getState())
    {
    case kxnTaskLEDdemo1_DEMO_1:
        kxnTaskLED1.write(10000);
        kDelay(10000);
        setState(kxnTaskLEDdemo1_DEMO_2);
        break;

    case kxnTaskLEDdemo1_DEMO_2:
        kxnTaskLED2.write(8000);
        kDelay(8000);
        setState(kxnTaskLEDdemo1_DEMO_3);
        break;

    case kxnTaskLEDdemo1_DEMO_3:
        kxnTaskLED3.write(2000);
        kDelay(2000);
        setState(kxnTaskLEDdemo1_DEMO_1);
        break;

    default:
        break;
    }
}

END
#endif