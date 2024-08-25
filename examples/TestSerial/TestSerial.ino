#include "kxnTaskLED.h"

#define LED_PIN 10  // connect led with 220 or 330 ohm resistor into pin 10 of Arduino board.

kxnTaskLED kxnTaskLED1;  // initialize object to use it's function.

void setup(void) {
  Serial.begin(9600);
  kxnTaskLED1.setup(LED_PIN);
  // Serial.print(sizeof(int));

  // set the LED on pin 10 ON in 500 milisecond, OFF 200 ms then repeat forver.


  // set the LED on pin 10 ON in 500 milisecond, OFF 200 ms then repeat 5 times.
  // kxnTaskLED1.write(500, 200, 5);

  // set the LED on pin 10 ON in 5000 milisecond then OFF.
  // kxnTaskLED1.write(5000);
}

void loop(void) {
  if (Serial.available()) {
    String Str = Serial.readStringUntil('\n');
    int firstSpace = Str.indexOf(' ');
    String timeON = Str.substring(0, firstSpace);
    String timeOFF = Str.substring(firstSpace + 1);

    Serial.println("the ON times of the led is " + timeON);
    Serial.println("the OFF times of the led is " + timeOFF);

    //     Serial.println("the ON times of the led is " + timeON.toInt());
    // Serial.println("the OFF times of the led is " + timeOFF.toInt());
    kxnTaskLED1.write(timeON.toInt(),timeOFF.toInt());
  }

  kxnTaskManager.run(millis());
}