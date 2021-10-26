
#define INPUTPIN1 4
#define INPUTPIN2 5
#define OUTPUTPIN 19

int pointCounter = 0;
//Initialize the global variable to store the read byte

//Send the data to receiver to tell which LED to light up
//Pushed button 1 to send that character
char byteSendData = 'r';

//Pushed button 2 to send that character
char byteSendData1 = 'g';
char readTransmitterData;



void setup() {
  // put your setup code here, to run once:
  pinMode(INPUTPIN1, INPUT);   //read one input pin for button pressed
  pinMode(INPUTPIN2, INPUT);   //read another input pin for button pressed
  pinMode(OUTPUTPIN, OUTPUT);  //Output to that pin which would light up white LED if press wrong pushbutton or if right pushbutton is pressed
  while(!Serial){
    ;//null, waiting for serial port to connect (needed for native usb ports only)
  }
  //Start the serial communication
  Serial.begin(9600);
}

//Infinite serial communication between two arduinos
void loop() {
  transmitter();
  receiver();
}


//Transmit the specific character data to the other LED to tell that LED to light up
void transmitter(){
  //To check whether one input pin is pressed
  if(analogRead(INPUTPIN1) == 1){
    Serial.write(byteSendData);
  }
  else if(analogRead(INPUTPIN2) == 1){
    Serial.write(byteSendData1);
  }
  //Add a 1 second delay
  delay(1000);
}


//Receives communication from the transmitter
void receiver(){
  if(Serial.available() > 0){
    readTransmitterData = Serial.read();

    //Means that you didn't pressed the wrong pushbutton that corresponds to the LED being light up at the receiver
    if(readTransmitterData == 'C'){   
      pointCounter += 100;   
      digitalWrite(OUTPUTPIN, HIGH);
      delay(300);  //0.3 seconds
      digitalWrite(OUTPUTPIN, LOW);
      delay(300);  //0.3 seconds
    }

    //Means that you pressed the wrong pushbutton that corresponds to the LED being light up at the receiver
    else if(readTransmitterData == 'F'){
      pointCounter = 0;
      digitalWrite(OUTPUTPIN, HIGH);
      delay(5000);   //Wait 5 seconds
       digitalWrite(OUTPUTPIN, LOW);
      delay(5000);  //Wait 5 seconds
    }
  }
  else{
    Serial.println("no data available to read");
  }  
}
  

  
  
/*
  if(byteRead == 1){
    digitalWrite()
  }
  else if(byteRead == 2){
    digitalWrite()
  }
  else if (byteRead == 3){
    digitalWrite(OUTPUTPIN, HIGH);
    delay(5000);
  }
*/
  /*
   Echo the value that was read back to the serial port
   */
//   Serial.write(byteRead);
  // put your main code here, to run repeatedly:



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
