#include "kxnTaskLED_kxn.h"

kxnTaskLED kxnTaskLED1;

void setup();
void loop();

void setup() {
  Serial.begin(9600);
  kxnTaskLED1.setup(11);
  // kxnTaskLED1.write(200,1000);
  // kxnTaskLED1.write(2000);
  kxnTaskLED1.write(2000,1000,5);
}

void loop() {
  kxnTaskManager.run(millis());
}
/**
 * modify on monday, 2024/07/08.
 * delete for(delay).
 */