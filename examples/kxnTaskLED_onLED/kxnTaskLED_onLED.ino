#include "kxnTaskLED_minhkhanh.h"

kxnTaskLED kxnTaskLED1;
kxnTaskLED kxnTaskLED2;

void khanhDelay(unsigned long paraTimes);
void setup();
void loop();

void setup() {

  Serial.begin(9600);

  kxnTaskLED1.setup(10);
  kxnTaskLED2.setup(11);

  kxnTaskLED1.write(50, 50, 10);

  // kxnTaskLED1.write(1000, 1000, 5);
  // if(!kxnTaskLED1.isRunning())
  // {
  //   kxnTaskLED2.write(100,100);
  // }

  // kxnTaskLED1.write(1000, 1000, 5);
  // khanhDelay(11);

  // kxnTaskLED2.write(100, 500, 5);

  // if (kxnTaskLED1.isRunning())
  // {
  //   Serial.println("LED DANG SANG");
  //   kxnTaskLED1.stop();
  // }

  // Serial.println();
}

void khanhDelay(unsigned long paraTimes) {
  unsigned long endTimes = millis() + paraTimes * 1000;
  while (millis() <= endTimes) {
    kxnTaskManager.run(millis());
  }
}

void loop() {
  Serial.println(kxnTaskLED1.isRunning());

  if (kxnTaskLED1.isRunning()) 
  {
    kxnTaskLED2.write(100,100,3);
  }
  else 
  {
  kxnTaskLED2.write(1000,5000,1);
  }

  // kxnTaskLED1.write(1000, 1000, 5);
  // if (!kxnTaskLED1.isRunning()) 
  // {
  //   kxnTaskLED2.write(100,100);
  // }
  // else 
  // {
  // kxnTaskLED2.write(1000);
  // }
  // kxnTaskLED1.write(50, 50, 5);

  // kxnTaskLED1.write(500, 1000);

  // kxnTaskLED1.write(2000);

  // kxnTaskLED1.write(500, 500, 5);

  kxnTaskManager.run(millis());
}