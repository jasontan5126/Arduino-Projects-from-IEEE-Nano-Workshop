//Created by XiangFeng

#define LEDGreen 11
#define LEDRed 12
int randNumber;
void setup() {
  // put your setup code here, to run once:
  pinMode(LEDGreen, OUTPUT);
  pinMode(LEDRed, OUTPUT);
  randomSeed(analogRead(0));
  Serial.begin(9600);
  randNumber = random(2);
}


void loop(){
  //char byteRead = Serial.read();
  // waiting for a button press
  if(randNumber == 0){
    digitalWrite(LEDRed, HIGH);
    digitalWrite(LEDGreen, LOW);
  } else if(randNumber == 1){
    digitalWrite(LEDGreen, HIGH);
    digitalWrite(LEDRed, LOW);
  }
  
  if (Serial.available()>0) {
    char byteRead = Serial.read();
   
    //generating random color
    /* read the first byte from the receive buffer */
    Serial.println(byteRead);
    /* ECHO the value that was read, back to the serial port. */
    // check if button press is correct
    if(randNumber == 0 && byteRead == 'r'){
       Serial.write('F');
    } else if (randNumber == 0 && byteRead == 'g'){
       Serial.write('C');

    } else if (randNumber == 1 && byteRead == 'r'){
      Serial.write('C');
      
       //Serial.println("\nthe third r was read");
    } else if (randNumber == 1 && byteRead ==  'g'){
      Serial.write('F');
    }
    digitalWrite(LEDGreen, LOW);
    digitalWrite(LEDRed, LOW);

    randNumber = random(2);
    
  }
  else{
  }
  
}
