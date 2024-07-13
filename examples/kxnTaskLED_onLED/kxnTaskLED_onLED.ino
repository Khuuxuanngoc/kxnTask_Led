#include "kxnTaskLED_kxn.h"

kxnTaskLED kxnTaskLED1;

void setup();
void loop();


void setup() {
  kxnTaskLED1.setup(11);
  // kxnTaskLED1.write(200,1000);
  // kxnTaskLED1.write(2000);
  kxnTaskLED1.write(500, 500, 5);
}

void loop() {
  kxnTaskManager.run(millis());
}