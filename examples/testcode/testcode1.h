/**
 * code viet thu nghiem ngay 04 thang 07 nam 2024
 * test ham bat tat led co repeat
 */
DEFINE_TASK_STATE(kxnTaskLED){
    kxnTaskLED_ON_repeat,
    kxnTaskLED_OFF_repeat,
};
unsigned      repeatTimes;
unsigned int  count;

void write(unsigned long delayON, unsigned long delayOFF, unsigned int repeatTimes){
    this->start_has_repeat();
    this->timeDelayON=delayON;
    this->timeDelayOFF=delayOFF;
    this->repeatTimes=repeatTimes;
    if(this->count==repeatTimes) {
        this->stop();
        this->count=0; 
    }
}


switch (getState())
{
    case kxnTaskLED_ON_repeat:
        digitalWrite(this->pin, 1);
        kDelay(timeDelayON);
        setState(kxnTaskLED_OFF_repeat);
        this->count++;
        break;

    case kxnTaskLED_OFF_repeat:
        digitalWrite(this->pin, 0);
        kDelay(timeDelayOFF);
        setState(kxnTaskLED_ON_repeat);
        this->count++;
        break;
default:
    break;
}

void start_has_repeat()
{
    kxnTaskManager.add(this);
    setState(kxnTaskLED_ON_repeat);
}
