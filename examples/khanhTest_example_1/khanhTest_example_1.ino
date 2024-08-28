#include "test_lib_1_KXN.h"
#include "test_serial.h"
// #include "test_lib_2.h"
test_lib_1 test1;
test_serial testSerial;
test_serial *ptr=&testSerial;
// test_lib_2 test2;

void setup() {
  testSerial.setup();
  test1.setup(LED_BUILTIN);
  // test2.setup(LED_BUILTIN);
  // test1.start();
  // test1.write(5000);
  test1.write(2000);
}

// unsigned long lastMillis, currentMillis;
// int interval;

void loop() {
  // testSerial.test_Serial();
  // currentMillis = millis();
  // if (Serial.available()) {
  //   Str = Serial.readStringUntil('\n');
  //   // lastMillis = millis();
  //   // interval = str.toInt();

  //   int firstSpace = Str.indexOf(' ');
  //   String timeON = Str.substring(0, firstSpace);
  //   String timeOFF = Str.substring(firstSpace + 1);


  //   Serial.println("the ON times of the led is " + timeON);
  //   Serial.println("the OFF times of the led is " + timeOFF);

  // test1.write(ptr->timeON.toInt(), ptr->timeOFF.toInt());

  //   // Serial.println("input_time " + Str);

  //   // if (currentMillis - lastMillis >= interval)
  //   // {
  //   Serial.println(millis());
  //   // }
  // }
  test1.write(ptr->Str.toInt());
  _delay(5000);
  // test2.write(Str.toInt());
  // test1.write(timeON.toInt(), timeOFF.toInt());
  // test1.write(1000, 1000);
  kxnTaskManager.run(millis());
}


void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() <= endTime) {
      // _loop();
      kxnTaskManager.run(millis());
      testSerial.test_Serial();
  }
}
