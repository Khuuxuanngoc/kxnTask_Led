#include "test_lib_1.h"
test_lib_1 test1;

void setup() {
  Serial.begin(9600);
  test1.setup(LED_BUILTIN);
  // test1.start();
  // test1.write(5000);
}
String str = "";
unsigned long lastMillis, currentMillis;
int interval;
void loop() {
  // currentMillis = millis();
  if (Serial.available()) {
    str = Serial.readStringUntil('\n');
    // lastMillis = millis();
    // interval = str.toInt();
    Serial.println("input_time " + str);

    // if (currentMillis - lastMillis >= interval)
    // {
    Serial.println(millis());
    // }
  }
  test1.write(str.toInt());
  kxnTaskManager.run(millis());
}
