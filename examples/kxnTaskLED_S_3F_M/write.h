void write(unsigned long timeON, unsigned long timeOFF, int8_t count)
{
    // if (this->isRunning())
    // {
    //     if (this->timeON != timeON ||
    //         this->timeOFF != timeOFF ||
    //         this->count != count)
    //     {
    //         this->timeON = timeON;
    //         this->timeOFF = timeOFF;
    //         this->count = count;
    //         this->start();
    //         setState(kxnTaskLED_ON);
    //     }
    // }
    // else
    // {
        resetAllPa();
        this->timeON = timeON;
        this->timeOFF = timeOFF;
        this->count = count;
        this->start();
        setState(kxnTaskLED_ON);
    }
}