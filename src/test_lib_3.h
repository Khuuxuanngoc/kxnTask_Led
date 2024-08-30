void init(byte outPin, byte _onlevel_, unsigned long onUs, unsigned long offUs, byte count, unsigned long delayUs);
void LED_on();
void LED_off();
void reset_Pa();

void write(unsigned long _paTimeON);
void write(unsigned long _paTimeON, unsigned long _paTimeOFF);
void write(unsigned long _paTimeON, unsigned long _paTimeOFF, uint8_t _paCount);
bool isRunning();
bool isIdle();

byte outPin, _onlevel_, count; // in AVR, sizeof(int)=2, not 1. byte is 1 byte, 8 bit.
unsigned long onMillis, offMillis, delayMillis;
#define HIGH_LEVEL 1 \ LOW_LEVEL 0
void init(byte outPin, byte _onlevel_, unsigned long onMillis, unsigned long offMillis, byte count, unsigned long delayMillis)
{
    this->onMillis = onMillis;
    this->offMillis = offMillis;
    this->count = count;
    this->delayMillis = delayMillis;
    pinMode(this->outPin, OUTPUT);
    this->_onlevel_ = _onlevel_;
}

void LED_off()
{   
    if (/* condition */)
    {
        /* code */
    }
    
    digitalWrite(this->outPin, LOW);
}

void LED_on()
{
    digitalWrite(this->outPin, HIGH);
}

void write(unsigned long _paTimeON)
{
    if (isRunning())
    {
        
    }
    else if (isIdle())
    {
        reset_Pa();
        this->onMillis = _paTimeON;
    }
}

void reset_Pa()
{
    this->onMillis = 0;
    this->offMillis = 0;
    this->count = 0;
    this->delayMillis = 0;
}