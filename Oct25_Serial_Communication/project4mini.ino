/* OPS project 4 (mini project): getting MCUs talking to eachother 
 *  @author: Ryuichi Lin
 *  
 *  circuit 1 (the receiver arduino):
 *  - RX connected to other arduino TX
 *  - TX connected to other arduino RX
 *  - GND connected to other ardino GND
 *  - pin 12 (D12) connected to led in series with 330Ohm resistor
 *  
 *  circuit 2 (the transmitter arduino):
 *  - RX connected to other arduino TX
 *  - TX connected to other arduino RX
 *  - GND connected to other ardino GND
 *  
 *  
 *  IMPORTANT NOTE: Serial.println() / Serial.print()
 *  -> if you add print statements into the transmitter arduino, be careful:  
 *    Serial.println() and Serial.print() will transmit all the chars to the
 *    receiver...
 *  
*/
/*
#define LEDPIN 12

char byteRead;

void setup() {
  pinMode(LEDPIN, OUTPUT); //needed for the receiver arduino
  Serial.begin(9600);
  while(!Serial){
    ;//null, waiting for serial port to connect (needed for native usb ports only)
  }
}
*/

/*
//code for the receiver arduino:
void loop() {
  if(Serial.available() > 0){
    byteRead = Serial.read();
    if(byteRead == 'A'){
      Serial.println("A has been read!");
      digitalWrite(LEDPIN, HIGH);
    }
    else if(byteRead == 'B'){
      Serial.println("B has been read!");
      digitalWrite(LEDPIN, LOW);
    }
  }
  else{
    Serial.println("no data available to read");
  }
}
*/

/*
//code for the transmitter:
void loop(){
  Serial.write('A');
  delay(500);
  Serial.write('B');
  delay(500);
}
*/
