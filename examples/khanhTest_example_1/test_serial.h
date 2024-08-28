class test_serial {
public:
  String Str = "", timeON, timeOFF;
  void setup() {
    Serial.begin(9600);
  }

  void test_Serial() {
    if (Serial.available()) {
      Str = Serial.readStringUntil('\n');

      int firstSpace = Str.indexOf(' ');
      timeON = Str.substring(0, firstSpace);
      timeOFF = Str.substring(firstSpace + 1);


      Serial.println("the ON times of the led is " + timeON);
      Serial.println("the OFF times of the led is " + timeOFF);
    }
  }
  void loop() {
    //
  }
};