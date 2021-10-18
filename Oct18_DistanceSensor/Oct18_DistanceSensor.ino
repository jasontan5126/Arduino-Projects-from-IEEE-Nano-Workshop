#define INPUTPIN 19 
#define OUTPUTPIN 5
long zero;

void setup() {
  // put your setup code here, to run once:

  //To read the input pin A5
  pinMode(INPUTPIN, INPUT);
  zero = 0;
  for (int i = 0; i < 100; i++){
    zero += analogRead(INPUTPIN);
  }
  zero /= 100;

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(INPUTPIN);
  int val2 = 0;
  
  val = map(val, zero, 1023, 0, 255);
  val2 = constrain(val, 0, 255);
  analogWrite(OUTPUTPIN, val);
  
  

}
