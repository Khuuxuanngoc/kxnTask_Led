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
typedef unsigned long ul_32t;
class LED_Manager
{
private:
    uint8_t pin;
    // uint8_t LED_current_state;
    uint8_t LED_last_state;
    bool LED_ON;
    bool LED_OFF;

public:
    uint8_t LED_current_state;
    //     uint8_t timeON, timeOFF, lastTimeON, lastTimeOFF;
    //     LED_ON_Manager(ul_32t timeCurrent, ul_32t timeLast);
    //     LED_OFF_Manager(ul_32t timeCurrent, ul_32t timeLast);
    //     // ~LED_Manager();
};

// LED_Manager::LED_ON_Manager(ul_32t timeCurrent, ul_32t timeLast)
// {
//     timeON=timeCurrent;

// }

// LED_Manager::~LED_Manager()
// {
// }

DEFINE_TASK_STATE(test_lib_1){
    test_lib_1_ON,
    test_lib_1_OFF,
};

CREATE_TASK(test_lib_1)
uint8_t pin;

void setup(uint8_t pin_PA)
{
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
        this->LED_ON();
        kDelay(this->current_delayON);
        setState(test_lib_1_OFF);
        break;

    case test_lib_1_OFF:
        this->LED_OFF();
        kDelay(this->current_delayOFF);

        if (ptr->LED_current_state == this->LED_ON_LOOP_FOREVER ||
            ptr->LED_current_state == this->LED_ON_LOOP_FORTIMES)
        {
            setState(test_lib_1_ON);
        }
        else
        {
            this->stop();
        }

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

// Nhấp nháy
void write(unsigned long delayON, unsigned long delayOFF)
{
    ptr->LED_current_state = this->LED_ON_LOOP_FOREVER;

    this->last_delayON = this->current_delayON;
    this->last_delayOFF = this->current_delayOFF;
    this->current_delayON = delayON;
    this->current_delayOFF = delayOFF;

    if (this->current_delayON != this->last_delayON && this->current_delayOFF != this->last_delayOFF )
    {
        this->stop();
        this->start();
    }
}

// Nhấp nháy theo số lần rồi tắt
// void write(unsigned long delayON, unsigned long delayOFF, uint8_t countOFF)
// {
//     ptr->LED_current_state = this->LED_ON_LOOP_FORTIMES;

//     this->last_delayON = this->current_delayON;

//     this->current_delayON = delayON;

//     if (this->current_delayON != this->last_delayON)
//     {
//         this->stop();
//         this->start();
//     }
// }

typedef enum
{
    LED_ON_1_TIMES = 100,
    LED_ON_LOOP_FOREVER,
    LED_ON_LOOP_FORTIMES,
} LED_state;

LED_Manager led_manager;
LED_Manager *ptr = &led_manager;

unsigned long current_delayON, last_delayON, current_delayOFF, last_delayOFF;

// Bật một lần xong rồi tắt
void write(unsigned long delayON)
{

    ptr->LED_current_state = this->LED_ON_1_TIMES;

    this->last_delayON = this->current_delayON;
    this->last_delayOFF = this->current_delayOFF;
    this->current_delayON = delayON;
    this->current_delayOFF = 0;

    if (this->current_delayON != this->last_delayON)
    {
        this->stop();
        this->start();
    }
}
void LED_ON()
{
    digitalWrite(this->pin, HIGH);
}

void LED_OFF()
{
    digitalWrite(this->pin, LOW);
}

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