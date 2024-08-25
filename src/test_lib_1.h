// Tiền xử lý
/**
 * Bảo vệ Bao gồm Truyền Thống
 *
 * #ifndef EXAMPLE_H: Đây là viết tắt của “if not defined”.
 * Nó kiểm tra xem EXAMPLE_H đã được định nghĩa trước đó hay chưa.
 *
 * #define EXAMPLE_H: Nếu EXAMPLE_H chưa được định nghĩa, dòng này sẽ định nghĩa nó.
 * Điều này đảm bảo rằng lần sau khi tệp tiêu đề này được bao gồm,
 * EXAMPLE_H đã được định nghĩa và đoạn mã giữa #ifndef và #endif sẽ bị bỏ qua.
 *
 * Kết thúc Bảo vệ Bao gồm
 * #endif // EXAMPLE_H
 * #endif: Kết thúc khối điều kiện bắt đầu bằng #ifndef.
 * Nếu EXAMPLE_H chưa được định nghĩa, đoạn mã giữa #ifndef và #endif sẽ được biên dịch.
 * Nếu không, đoạn mã này sẽ bị bỏ qua.
 *
 * #pragma once là một chỉ thị tiền xử lý trong C và C++ được sử dụng để đảm bảo rằng một tệp tiêu đề chỉ được bao gồm một lần trong quá trình biên dịch.
 * Điều này giúp tránh các lỗi do bao gồm lặp lại tệp tiêu đề, chẳng hạn như định nghĩa lại các biến hoặc hàm.
 *
 */

/**
 * Yêu cầu: gọi LED sáng theo các theo các trường hợp và kiểm tra được trạng thái của con led.
 * Ý tưởng: quản lý tối đa con led.
 */

#ifndef test_lib_1__H
#define test_lib_1__H

#include "kxnTask.h"
// #include "Arduino.h"

class LED_Manager
{
private:
    uint8_t pin;
    uint8_t LED_current_state;
    uint8_t LED_last_state;
    bool LED_ON;
    bool LED_OFF;

public:
    LED_Manager(/* args */);
    ~LED_Manager();
};

LED_Manager::LED_Manager(/* args */)
{
}

LED_Manager::~LED_Manager()
{
}

DEFINE_TASK_STATE(test_lib_1){
    test_lib_1_ON,
    test_lib_1_OFF,
};

CREATE_TASK(test_lib_1)
/*Add your variable here*/
// unsigned long 
uint8_t pin;

void setup(uint8_t pin_PA)
{
    /*Add your code setup here*/
    this->pin = pin_PA;
    pinMode(this->pin, OUTPUT);
    digitalWrite(this->pin, 0);
    stop();
}


void loop()
{
    switch (getState())
    {
    case test_lib_1_ON:
        /*code*/
        // if ()
        digitalWrite(this->pin, HIGH);
        kDelay(1000);
        setState(test_lib_1_OFF);
        break;

    case test_lib_1_OFF:
        /*code*/
        digitalWrite(this->pin, LOW);
        kDelay(1000);
        setState(test_lib_1_ON);
        break;

    default:
        break;
    }
}

void start()
{
    kxnTaskManager.add(this);
    setState(test_lib_1_ON);
}

void stop()
{
    kDelay(0);
    setStateIdle();
}

void runFast()
{
}

// void write(unsigned long delayON, unsigned long delayOFF)
// {
//     if (this->LED_mode != kxnTaskLED_MODE_ON)
//     {
//         this->start();
//         this->LED_mode = kxnTaskLED_MODE_ON;
//         setState(kxnTaskLED_ON);
//         this->timeDelayON = delayON;
//         this->timeDelayOFF = delayOFF;
//     }
// }

// void write(unsigned long delayON, unsigned long delayOFF, uint8_t countOFF)
// {
//     if (this->LED_mode != kxnTaskLED_MODE_ON_COUNT)
//     {
//         this->LED_mode = kxnTaskLED_MODE_ON_COUNT;
//         this->countOFF = countOFF;
//         this->start();
//         setState(kxnTaskLED_ON_COUNT);
//         this->timeDelayON = delayON;
//         this->timeDelayOFF = delayOFF;
//     }
// }

// void write(unsigned long delayON)
// {
//     if (this->LED_mode != kxnTaskLED_MODE_ON_1TIMES)
//     {
//         this->LED_mode = kxnTaskLED_MODE_ON_1TIMES;
//         this->start();
//         setState(kxnTaskLED_ON_1TIMES);
//         this->timeDelayON = delayON;
//     }
// }

// bool isRunning()
// {
//     if (
//         this->LED_mode == kxnTaskLED_MODE_ON ||
//         this->LED_mode == kxnTaskLED_MODE_ON_1TIMES ||
//         this->LED_mode == kxnTaskLED_MODE_ON_COUNT)
//         return true;
//     else
//         return false;
// }
END
#endif