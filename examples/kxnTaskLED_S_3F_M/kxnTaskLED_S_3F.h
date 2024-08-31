#pragma once

#include "kxnTask.h"
#include "init.h"
#include "turningLED.h"
#include "write.h"

DEFINE_TASK_STATE(kxnTaskLED){
  kxnTaskLED_ON,
  kxnTaskLED_OFF,
  kxnTaskLED_IDLE,
};

CREATE_TASK(kxnTaskLED)

void loop() {
  switch (getState()) {
    case kxnTaskLED_ON:
      Serial.println(this->isRunning());
      this->LED_ON();
      kDelay(this->timeON);
      setState(kxnTaskLED_OFF);
      break;

    case kxnTaskLED_OFF:
      Serial.println(this->isRunning());
      this->LED_OFF();
      kDelay(this->timeOFF);
      if (this->count >= 0 && ++this->countS >= this->count) {
        this->resetAllPa();
        this->stop();
      }
      break;

    default:
      break;
  }
}
// Bắt đầu thực hiện nhiệm vụ.
void start() {
  kxnTaskManager.add(this);
  setState(kxnTaskLED_ON);
}
// Vào chế độ nghỉ.
void stop() {
  // resetAllPa();
  Serial.println(this->isRunning());
  kDelay(0);
  setStateIdle();
}

extern kxnTaskLED LED1;
END