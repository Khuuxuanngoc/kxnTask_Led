#include "kxnTaskLED.h"
#include "kxnTaskLEDdemo1.h"



#define PIN_LED_RED 10     // connect led with 220 or 330 ohm resistor into pin 10 of Arduino board.
#define PIN_LED_GREEN 11   // connect led with 220 or 330 ohm resistor into pin 11 of Arduino board.
#define PIN_LED_YELLOW 12  // connect led with 220 or 330 ohm resistor into pin 12 of Arduino board.

kxnTaskLEDdemo1 kxnTaskLEDdemo; // initialize object to use it's function.

void setup(void) {
  kxnTaskLEDdemo.setup();
}
void loop(void) {
  kxnTaskManager.run(millis());
}
