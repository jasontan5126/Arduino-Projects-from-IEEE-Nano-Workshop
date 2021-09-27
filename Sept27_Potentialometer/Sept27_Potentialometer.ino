#define RECEIVER 14
#define LED 7

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);    //To receive the output at 14
  pinMode(RECEIVER, INPUT);   //To read the input at 7
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogRead(RECEIVER);
  digitalWrite(LED, HIGH);
  delay(analogRead(RECEIVER));
  digitalWrite(LED, LOW);
  delay(analogRead(RECEIVER));
}
