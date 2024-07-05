#include "kxnTaskLED.h"

kxnTaskLED kxnTaskLED1;

void setup();
void loop();

void setup() {
  Serial.begin(9600);
  kxnTaskLED1.setup(11);
  kxnTaskLED1.write(5000);
}

void loop() {
  kxnTaskManager.run(millis());
    for(int i=0;i<=5;i++){
    Serial.println(i);
    delay(1000);
      }
}
