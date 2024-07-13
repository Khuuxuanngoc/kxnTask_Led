#include "kxnTaskLED_kxn.h"

kxnTaskLED kxnTaskLED1;
kxnTaskLED kxnTaskLED2;

void setup();
void loop();

void setup() {

  Serial.begin(9600);


  kxnTaskLED1.setup(10);
  kxnTaskLED2.setup(11);
  // checkPC();

  //   kxnTaskLED1.write(200, 100);
  // kxnTaskLED2.write(100, 500, 5);

  // if (kxnTaskLED1.isRunning()) {
  //   Serial.println("LED DANG SANG");
  //   kxnTaskLED1.stop();
  // }
  // kxnTaskLED1.write(2000);

  // kxnTaskLED1.write(500, 500, 5);



  // Serial.println();
}
void checkPC() {
  if (Serial.available()) {
    char ch = Serial.read();
    switch (ch) {
      case '1':
        kxnTaskLED1.write(200, 100);
        kxnTaskLED2.write(100, 500, 5);
        break;
      case '0':
        kxnTaskLED1.stop();
        kxnTaskLED2.stop();
        break;
    }}
}
void loop() {
checkPC();
  kxnTaskManager.run(millis());
}