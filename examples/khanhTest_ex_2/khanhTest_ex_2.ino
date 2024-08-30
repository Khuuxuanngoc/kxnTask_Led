#include "khanhTest_ex_2.h"

khanhTest_ex_2 test;

void setup()
{
    Serial.begin(9600);
    test.setup(10);
    // test.write(100);

}
void loop()
{
    test.write(100);
    kxnTaskManager.run(millis());
}