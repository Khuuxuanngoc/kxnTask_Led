#include "test_lib_1.h"
test_lib_1 test1;

void setup() {
  Serial.begin(9600);
  test1.setup(LED_BUILTIN);
  // test1.start();
  // test1.write(5000);
}
String Str = "";
// unsigned long lastMillis, currentMillis;
// int interval;

void loop() {
  // currentMillis = millis();
  if (Serial.available()) {
    Str = Serial.readStringUntil('\n');
    // lastMillis = millis();
    // interval = str.toInt();

    int firstSpace = Str.indexOf(' ');
    String timeON = Str.substring(0, firstSpace);
    String timeOFF = Str.substring(firstSpace + 1);


    Serial.println("the ON times of the led is " + timeON);
    Serial.println("the OFF times of the led is " + timeOFF);

    test1.write(timeON.toInt(), timeOFF.toInt());

    // Serial.println("input_time " + Str);

    // if (currentMillis - lastMillis >= interval)
    // {
    Serial.println(millis());
    // }
  }
  // test1.write(Str.toInt());
  // test1.write(timeON.toInt(), timeOFF.toInt());
  // test1.write(1000, 1000);
  kxnTaskManager.run(millis());
}
