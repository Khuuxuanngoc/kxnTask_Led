#include "led_off_1_arg.h"

led_off_1_arg khanhled;

void setup() {
  khanhled.setPin(11);
  khanhled.setup();
  khanhled.start();
}

void loop() {
  kxnTaskManager.run(millis());
}
