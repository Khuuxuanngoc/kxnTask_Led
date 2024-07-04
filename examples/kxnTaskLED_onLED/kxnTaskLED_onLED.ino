#include "kxnTaskLED.h"

kxnTaskLED kxnTaskLED1;

void setup();
void loop();



void setup() {
  kxnTaskLED1.setup(11);
  kxnTaskLED1.write(1000,500);
  
}
void loop() {
  kxnTaskManager.run(millis());
}
