#include "kxnTaskLED_S_3F.h"
// kxnTaskLED LED1;
String Str = "", timeON = "", timeOFF = "";
// void setup() {
//   Serial.begin(9600);
// }

void test_Serial()
{
    if (Serial.available())
    {
        Str = Serial.readStringUntil('\n');

        int firstSpace = Str.indexOf(' ');
        timeON = Str.substring(0, firstSpace);
        timeOFF = Str.substring(firstSpace + 1);

        Serial.println("the ON times of the led is " + timeON);
        Serial.println("the OFF times of the led is " + timeOFF);
    }
}
void setup()
{
    Serial.begin(9600);
    LED1.setup(10);
    // LED1.write(1000,1000,5);
    // LED1.write(1000,0,0);
    LED1.write(1000,1000,-1);

}
void loop()
{
    test_Serial();
    Serial.println(isRunning());
    // LED1.write(timeON.toInt(), timeOFF.toInt(), 2);
    // LED1.write(1000,0,0);
    kxnTaskManager.run(millis());
}