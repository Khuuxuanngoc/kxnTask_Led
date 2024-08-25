#include "test_lib_1.h"
test_lib_1 test1;

void setup()
{
    test1.setup(LED_BUILTIN);
    test1.start();
}
void loop()
{
    kxnTaskManager.run(millis());
}
