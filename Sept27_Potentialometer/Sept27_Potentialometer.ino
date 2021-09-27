//Potentiometer to 

#define RECEIVER 14
#define LED 7

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);    //To receive the output at A0
  pinMode(RECEIVER, INPUT);   //To read the input at PD7
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogRead(RECEIVER);    //Reads the value from the specified analog pin
  digitalWrite(LED, HIGH); //Set the LED output to high
  delay(analogRead(RECEIVER));  //delay by small time
  digitalWrite(LED, LOW); //set the LED output to low
  delay(analogRead(RECEIVER));
}
