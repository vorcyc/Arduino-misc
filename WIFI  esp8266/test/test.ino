#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 9); // RX, TX
void setup()
{
  Serial.begin(115200);
  while (!Serial) {
    ;
  }
  Serial.println("hardware serial!");
  mySerial.begin(115200);
  mySerial.println("software seria");
}

void loop()
{
  if (mySerial.available())
  {
    Serial.println(mySerial.readString());
  }
  if (Serial.available())
  {
    mySerial.println(Serial.readString());
  }

}

