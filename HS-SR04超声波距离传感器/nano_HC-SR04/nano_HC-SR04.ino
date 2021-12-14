int echoPin = 6;
int trigPin = 5;
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop() {
  double duration;
  float cm, inch, mm;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = duration / 58;
  inch = duration / 148;
  mm = duration / 5.8;
  Serial.print(cm);
  Serial.print(" cm   ");
  Serial.print(inch);
  Serial.print(" inch   ");
  Serial.print(mm);
  Serial.println(" mm   ");
  delay(300);
}
