#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 9); // RX, TX

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  mySerial.begin(115200);
  mySerial.println("AT");
  delay(1000);
//  mySerial.println("AT+RST");
//  delay(1000);
  mySerial.println("AT+CIPSTART=\"TCP\",\"192.168.1.2\",8080");
  delay(1000);
  mySerial.println("AT+CIPSEND=5");
  delay(1000);
  mySerial.println("123abc");
}

void loop() {
  if (mySerial.available())
  {
    Serial.println(mySerial.readString());
//    mySerial.println("AT+SEND=5");
//    mySerial.println("123abc");
  }
  if (Serial.available())
  {
    mySerial.println(Serial.readString());
  }

}
