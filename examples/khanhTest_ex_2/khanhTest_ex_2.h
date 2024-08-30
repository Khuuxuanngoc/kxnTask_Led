#ifndef khanhTest_ex_2__H
#define khanhTest_ex_2__H

#define KDEBUGLN(name) Serial.println(name)
#define KDEBUG(name) Serial.print(name)

#include "kxnTask.h"

DEFINE_TASK_STATE(khanhTest_ex_2){
  khanhTest_ex_2_ON,
  khanhTest_ex_2_OFF,
  khanhTest_ex_2_BLINK_ON,
  khanhTest_ex_2_BLINK_OFF,
};

CREATE_TASK(khanhTest_ex_2)

/* Thêm các biến cần thiết */
int LED_PIN = 0;
int blinkCount = 0;
int blinkTimes = 0;
unsigned long onTime = 0;
unsigned long offTime = 0;
bool isBlinking = false;
// unsigned long previousMillis = 0;

void setup(int pin) {
  /*Cài đặt ban đầu*/
  Serial.begin(9600);
  this->LED_PIN = pin;
  pinMode(this->LED_PIN, OUTPUT);
  digitalWrite(this->LED_PIN, LOW);  // Tắt LED lúc khởi tạo
  stop();
  KDEBUGLN("Khởi tạo thành công");
  KDEBUG("pinMode: ");
  KDEBUG(this->LED_PIN);
  KDEBUG(" OUTPUT");
  KDEBUG('\n');
}

void loop() {
  // unsigned long currentMillis = millis();

  switch (getState()) {
    case khanhTest_ex_2_ON:
      digitalWrite(this->LED_PIN, HIGH);  // Bật LED
      kDelay(this->onTime);               //
      // digitalWrite(this->LED_PIN, LOW);   // Tắt LED
      // stop();     
      setState(khanhTest_ex_2_OFF);                       // Dừng task sau khi hoàn thành
      break;

    case khanhTest_ex_2_OFF:
      stop();
      break;

    case khanhTest_ex_2_BLINK_ON:
      // if (currentMillis - previousMillis >= onTime) {
      digitalWrite(this->LED_PIN, LOW);  // Tắt LED
      // previousMillis = currentMillis;
      setState(khanhTest_ex_2_BLINK_OFF);
      if (blinkTimes > 0 && ++blinkCount >= blinkTimes) {
        stop();  // Dừng task sau khi nhấp nháy đủ số lần
      }
      // }
      break;

    case khanhTest_ex_2_BLINK_OFF:
      // if (currentMillis - previousMillis >= offTime) {
      digitalWrite(this->LED_PIN, HIGH);  // Bật LED
      // previousMillis = currentMillis;
      setState(khanhTest_ex_2_BLINK_ON);
      // }
      break;

    default:
      break;
  }
}

void start() {
  kxnTaskManager.add(this);
  setState(khanhTest_ex_2_ON);
}

void stop() {
  digitalWrite(this->LED_PIN, LOW);  // Đảm bảo LED tắt khi dừng
  kDelay(0);
  setStateIdle();
}

void runFast() {
}

// Hàm bật LED một lần rồi tắt
void write(unsigned long onTime) {
  KDEBUG("LED ON 1 TIMES, TIME ON: ");
  this->onTime = onTime;
  KDEBUGLN(this->onTime);
  // KDEBUG('\n');
  start();  // Bắt đầu task và LED sẽ sáng một lần rồi tắt
}

// Hàm nhấp nháy LED với thời gian sáng và tắt cụ thể
void write(unsigned long onDuration, unsigned long offDuration) {
    this->onTime = onDuration;
    this->offTime = offDuration;
    this->blinkTimes = -1;  // Nhấp nháy vô hạn
    this->blinkCount = 0;
    // this->previousMillis = millis();
    this->isBlinking = true;
    start();
    setState(khanhTest_ex_2_BLINK_ON);  // Bắt đầu nhấp nháy
}

// Hàm nhấp nháy LED một số lần rồi tắt
void ledBlinkTimes(unsigned long onDuration, unsigned long offDuration, int times) {
    this->onTime = onDuration;
    this->offTime = offDuration;
    this->blinkTimes = -1;  // Nhấp nháy vô hạn
    this->blinkCount = 0;
    // this->previousMillis = millis();
    this->isBlinking = true;
    start();
    setState(khanhTest_ex_2_BLINK_ON);  // Bắt đầu nhấp nháy
}

// Hàm kiểm tra LED có đang hoạt động hay không
bool isLedActive() {
    return isBlinking || getState() == khanhTest_ex_2_ON;
}

END

#endif
