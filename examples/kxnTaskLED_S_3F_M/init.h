byte pin = 0;
bool level = 1;
unsigned long timeON = 0,
              timeOFF = 0,
              countS = 0,
              count = 0;


void setup(byte pin) {
  Serial.begin(9600);
  this->pin = pin;
  pinMode(this->pin, OUTPUT);
  this->resetAllPa();
  stop();
}

void setup(byte pin, bool level) {
  Serial.begin(9600);
  this->pin = pin;
  this->level = level;
  pinMode(this->pin, OUTPUT);
  this->resetAllPa();
  stop();
}