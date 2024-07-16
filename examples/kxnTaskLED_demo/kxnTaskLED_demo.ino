#include "kxnTaskLED.h"

#define LED_PIN 10 // connect led with 220 or 330 ohm resistor into pin 10 of Arduino board.

kxnTaskLED kxnTaskLED1; // initialize object to use it's function.

void setup(void)
{
    kxnTaskLED1.setup(LED_PIN);

    // set the LED on pin 10 ON in 500 milisecond, OFF 200 ms then repeat forver.
        kxnTaskLED1.write(500, 200);

    // set the LED on pin 10 ON in 500 milisecond, OFF 200 ms then repeat 5 times.
        // kxnTaskLED1.write(500, 200, 5);

    // set the LED on pin 10 ON in 5000 milisecond then OFF.
        // kxnTaskLED1.write(5000);

}

void loop(void)
{
    kxnTaskManager.run(millis());
}