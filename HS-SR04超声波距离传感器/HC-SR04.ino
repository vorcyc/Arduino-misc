// Trig?Arduino??Digital 5???????Echo?Digital 4?????????

int inputPin = 31; // ???????????
int outputPin = 30; // ???????????
int ledpin = 13;
void setup()
{
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
}
void loop()

{
  digitalWrite(outputPin, LOW); // ???????????????2?s
  delayMicroseconds(2);
  digitalWrite(outputPin, HIGH); // ???????????????10?s??????10?s
  delayMicroseconds(10);
  digitalWrite(outputPin, LOW); // ??????????????
  double distance = pulseIn(inputPin, HIGH); // ??????
  distance = distance / 58.0; // ?????????????????
  Serial.println(distance); //?????
  delay(50);
  if (distance >= 50)
  { //??????50??????
    digitalWrite(ledpin, HIGH);
  }//??????50??????
  else
    digitalWrite(ledpin, LOW);
}
