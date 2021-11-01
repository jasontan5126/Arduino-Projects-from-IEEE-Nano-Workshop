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
  if(digitalRead(INPUTPIN1) == LOW){
    Serial.write(byteSendData);
  }
 
  else if(digitalRead(INPUTPIN2) == LOW){
    Serial.write(byteSendData1);
  }

 delay(150);      //Add a 0.15 second delay to resolve debouncing issue on pushbutton
}


//Receives communication from the transmitter
void receiver(){
  if(Serial.available() > 0){
    readTransmitterData = Serial.read();            //Read the data from the receiver of another Arduino

    //Means that you didn't pressed the wrong pushbutton that corresponds to the LED being light up at the receiver which will blink white LED
    if(readTransmitterData == 'C'){   
      pointCounter += 100;   
      digitalWrite(OUTPUTPIN, HIGH);
      delay(100);  //0.1 seconds
      digitalWrite(OUTPUTPIN, LOW);
      delay(100);  //0.1 seconds
    }

    //Means that you pressed the wrong pushbutton that corresponds to the LED being light up at the receiver, the white LED will stay on for 5 seconds
    else if(readTransmitterData == 'F'){
      pointCounter = 0;
      digitalWrite(OUTPUTPIN, HIGH);
      delay(5000);   //Wait 5 seconds
       digitalWrite(OUTPUTPIN, LOW);
      delay(100);  //Wait 0.1 seconds
    }
  }
  else{
  }  
}
