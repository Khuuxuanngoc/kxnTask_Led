#include "kxnTaskLED.h"

kxnTaskLED kxnTaskLED1;

void setup();
void loop();

void setup() {
  Serial.begin(9600);
  kxnTaskLED1.setup(11);
  kxnTaskLED1.writeOn1times(1000,1000);
}

void loop() {
  kxnTaskManager.run(millis());
}
/**
 * modify on monday, 2024/07/08.
 * delete for(delay).
 */