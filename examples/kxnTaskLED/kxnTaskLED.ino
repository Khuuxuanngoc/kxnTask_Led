#include "kxnTaskLED.h"
#define KDEBUGLN(NAME) Serial.println(NAME)
#define KDEBUG(NAME) Serial.print(NAME)
kxnTaskLED LED1;
String Str = "", timeON = "", timeOFF = "";
// void setup() {
//   Serial.begin(9600);
// }

// void test_Serial()
// {
//   if (Serial.available())
//   {
//     Str = Serial.readStringUntil('\n');

//     int firstSpace = Str.indexOf(' ');
//     timeON = Str.substring(0, firstSpace);
//     timeOFF = Str.substring(firstSpace + 1);

//     Serial.println("the ON times of the led is " + timeON);
//     Serial.println("the OFF times of the led is " + timeOFF);
//   }
// }
void setup() {
  Serial.begin(9600);
  LED1.setup(10);
  LED1.write(2000);
}
void loop() {

  // LED1.write(2000);
  // KDEBUGLN(LED1.isRunning());
  LED1.write(1000,1000,2);
  kxnTaskManager.run(millis());
  // khanhDelay(10000);

  // LED1.write(timeON.toInt(),timeOFF.toInt(),2);
}

void khanhDelay(unsigned long Time) {
  if (millis() <= millis() + Time) {
    // test_Serial();
    kxnTaskManager.run(millis());
  }
}