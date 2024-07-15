#include "kxnTaskLED_minhkhanh.h"

kxnTaskLED kxnTaskLED1;
kxnTaskLED kxnTaskLED2;

void setup();
void loop();

void setup() {

  Serial.begin(9600);

  kxnTaskLED1.setup(10);
  kxnTaskLED2.setup(11);

  // kxnTaskLED2.write(100, 500, 5);

  // if (kxnTaskLED1.isRunning())
  // {
  //   Serial.println("LED DANG SANG");
  //   kxnTaskLED1.stop();
  // }



  // Serial.println();
}

void loop() {

  // kxnTaskLED1.write(500, 1000);

  // kxnTaskLED1.write(2000);

  // kxnTaskLED1.write(500, 500, 5);

  kxnTaskManager.run(millis());
}