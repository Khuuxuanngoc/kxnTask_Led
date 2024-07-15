#include "kxnTaskLED_minhkhanh.h"

kxnTaskLED kxnTaskLED1;
kxnTaskLED kxnTaskLED2;

void setup();
void loop();

void setup()
{
  Serial.begin(9600);
  kxnTaskLED1.setup(10);
  kxnTaskLED2.setup(11);
  // kxnTaskLED1.write(50, 50, 10);
}

void loop()
{
  // Serial.println(kxnTaskLED1.isRunning());

  if (!kxnTaskLED1.isRunning())
    kxnTaskLED2.write(3000);
  // else
  //   kxnTaskLED2.write(1000, 5000, 1);

  kxnTaskLED1.write(1000, 1000, 5);

  kxnTaskManager.run(millis());
}