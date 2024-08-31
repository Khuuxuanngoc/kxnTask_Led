// #include "kxnTaskLED1.h"
// #include "kxnTaskLED2.h"
#include "kxnTaskLED3.h"
// ONETIMES LED;
// FOREVER LED;
FORTIMES LED;
unsigned long currentMillis = 0, lastMillis = 0, interval = 1000;
unsigned long thatTimeMillis = 0;
long value1, value2, value3;

void setup()
{
    Serial.begin(9600);
    LED.setup(LED_BUILTIN,0);
    // LED.write(5000);
    // thatTimeMillis = 0;
}
void loop()
{
    testSerial();
    LED.write(value1, value2, value3);
    khanhDelay(10000);
    // kxnTaskManager.run(millis());
}

void khanhDelay(unsigned long Time)
{
    while (millis() <= millis() + Time)
    {
        Serial.print("in delay: ");
        Serial.println(Time);
        kxnTaskManager.run(millis());
        currentMillis = millis();
        if (currentMillis - lastMillis >= interval)
        {
            lastMillis = millis();
            Time -= 1000;
            if (Time < 0)
            {
                Time = 0;
            }
        }
    }
}

void testSerial()
{
    if (Serial.available())
    {
        String inputText = Serial.readStringUntil('\n');
        sscanf(inputText.c_str(), "%ld %ld %ld", &value1, &value2, &value3);
    }
}