#include <SoftwareSerial.h>
SoftwareSerial WIFISerial(8, 9); // RX, TX    //模拟一个软串口
void setup()  {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  int i = 0;

  WIFISerial.begin(115200);
  delay(1000);
  WIFISerial.println("AT");
  delay(1000);
  WIFISerial.println("AT+RST");          //重启
  delay(2000);
  WIFISerial.println("AT+CWMODE=1");     //设置为station模式
  delay(1000);
  WIFISerial.println("AT+RST");          //重启
  delay(2000);
  WIFISerial.println("AT+CWLAP");          //寻找网络
  delay(2000);
  WIFISerial.println("AT+CWJAP=\"cyclone\",\"63766760\""); //连接到想要连接的网络
  delay(2000);
  WIFISerial.println("AT+CIFSR");        //返回模块的IP地址
  delay(1000);
  WIFISerial.println("AT+CIPMUX=1");     //打开多连接
  delay(1000);
  //WIFISerial.println("AT+CIPMODE=1");    //透传模式
  //delay(1000);
  WIFISerial.println("AT+CIPSTART=0,\"TCP\",\"192.168.1.2\",8080");
  // 接收数据的计算机地址，连接到 TCP 服务器
  delay(3000);
  /*WIFISerial.println("AT+CIPSEND=0,11");
    delay(500);
    WIFISerial.println("14205200109");*/

  for (i = 1; i < 100; i++) {
    WIFISerial.println("AT+CIPSEND=0,14");
    WIFISerial.println("WLQ XK GCP LK");
  }
}

void loop() {
  int i = 0;
//  Serial.println("serial output");
  if (WIFISerial.available()) {
    Serial.write(WIFISerial.read());
//    Serial.println("ifwifi serial output");
  }
//  Serial.println("only serial output");
  if (Serial.available()) {
    WIFISerial.write(Serial.read());
//     Serial.println("if serial output");
  }
//  for (i = 1; i < 100; i++) {
//    WIFISerial.println(i);
//
//    digitalWrite(9, HIGH);    // turn the LED on (HIGH is the voltage level)
//    delay(1000);               // wait for a second
//    digitalWrite(9, LOW);     // turn the LED off by making the voltage LOW
//    delay(1000);               // wait for a second
//  }
}
