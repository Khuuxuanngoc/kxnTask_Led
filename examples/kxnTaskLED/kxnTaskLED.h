#pragma once

#include "kxnTask.h"
#define KDEBUGLN(NAME) Serial.println(NAME)
#define KDEBUG(NAME) Serial.print(NAME)

DEFINE_TASK_STATE(kxnTaskLED){
  kxnTaskLED_ON,
  kxnTaskLED_OFF,
  kxnTaskLED_IDLE,
};

CREATE_TASK(kxnTaskLED)

byte pin = 0;
bool level = 1;
unsigned long timeON = 0,
              timeOFF = 0,
              countS = 0,
              count = 0;

void resetAllPa() {
  level = 1;
  timeON = 0;
  timeOFF = 0;
  count = 0;
}
void setup(byte pin) {
  this->pin = pin;
  pinMode(this->pin, OUTPUT);
  this->resetAllPa();
  stop();
}

void setup(byte pin, bool level) {
  this->pin = pin;
  this->level = level;
  pinMode(this->pin, OUTPUT);
  this->resetAllPa();
  stop();
}

void loop() {
  switch (getState()) {
    case kxnTaskLED_ON:
      KDEBUGLN("in kxnTaskLED_ON");
      // KDEBUGLN(getState());
      KDEBUGLN("ON-------------------------------------------");
      this->LED_ON();
      kDelay(this->timeON);
      setState(kxnTaskLED_OFF);
      KDEBUGLN("ENDON");
      KDEBUGLN('\n');
      break;

    case kxnTaskLED_OFF:
      KDEBUGLN("in kxnTaskLED_OFF");
      KDEBUGLN("OFF------------------------------------------");
      // KDEBUGLN(getState());
      this->LED_OFF();
      kDelay(this->timeOFF);
      if (this->count >= 0 && ++this->countS >= this->count) {
        KDEBUGLN("if(true) get in state: kxnTaskLED_IDLE");
        setState(kxnTaskLED_IDLE);
        this->start();
      } else
        KDEBUGLN("if(true) get in state: kxnTaskLED_IDLE");
      setState(kxnTaskLED_ON);
      KDEBUGLN("ENDOF");
      KDEBUGLN('\n');

      break;

    case kxnTaskLED_IDLE:
      KDEBUG("kxnTaskLED_IDLE: ");
      KDEBUGLN(getState());
      this->LED_OFF();
      this->resetAllPa();
      // setStateIdle();
      KDEBUGLN("END 1 func.");
      KDEBUGLN('\n');
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
  kDelay(0);
  setStateIdle();
  KDEBUGLN("F: stop()");
}
void LED_ON() {
  if (this->level)
    digitalWrite(this->pin, this->level);
  else
    digitalWrite(this->pin, !this->level);
}
void LED_OFF() {
  if (this->level)
    digitalWrite(this->pin, !this->level);
  else
    digitalWrite(this->pin, this->level);
}
void write(unsigned long timeON, unsigned long timeOFF, int8_t count) {
  if (this->isRunning()) {
    if (this->timeON != timeON || this->timeOFF != timeOFF || this->count != count) {
      KDEBUGLN("write() if isRunning");
      this->timeON = timeON;
      this->timeOFF = timeOFF;
      this->count = count;
      this->start();
      setState(kxnTaskLED_ON);
    }
  } else {
    // resetAllPa();
    KDEBUGLN("write() if isn'tRunning");
    this->timeON = timeON;
    this->timeOFF = timeOFF;
    this->count = count;
    this->start();
    setState(kxnTaskLED_ON);
  }
}
void write(unsigned long timeON) {
  this->write(timeON, 0, 0);
}
void write(unsigned long timeON, unsigned long timeOFF) {
  this->write(timeON, timeOFF, -1);
}
bool isRunning() {
  if (getState() == kxnTaskLED_ON || getState() == kxnTaskLED_OFF)
    return true;
  else
    return false;
}
END