#include "basicpitches.h"
#include "Despacito.h"

#include "pitches.h"
#define SPEAKER 3 


int NOTE_DURATION = 137;
#define INPUTREAD A6
#define OUTPUTIT 3

void setup() {
  // put your setup code here, to run once:
  pinMode(INPUTREAD, INPUT);
  analogRead(INPUTREAD);
  pinMode(OUTPUTIT, OUTPUT);
  Serial.begin(9600);
}

//void play (int note, int dur) {
//  tone(SPEAKER, note);
//  delay(dur * NOTE_DURATION);
//  noTone(SPEAKER);
//  delay(dur * NOTE_DURATION / 3);
//}

void song1(){
  
  play(NOTE_C4, NOTE_DURATION);  //implemented using multiple calls to play()
  play(NOTE_CS4, NOTE_DURATION);
  play(NOTE_D4, NOTE_DURATION);
  play(NOTE_DS4, NOTE_DURATION);
  play(NOTE_E4, NOTE_DURATION);
  play(NOTE_F4, NOTE_DURATION);
  play(NOTE_FS4, NOTE_DURATION);
  play(NOTE_G4, NOTE_DURATION);
  play(NOTE_GS4, NOTE_DURATION);
  play(NOTE_A4, NOTE_DURATION);
  play(NOTE_AS4, NOTE_DURATION);
  play(NOTE_B4, NOTE_DURATION);
  play(NOTE_C5, NOTE_DURATION);
}

void song2();  //implemented below
void song3();  //implemented below

void loop() {
  if(analogRead(INPUTREAD) < 70){
    song1();
    
  }
  else{
    Despacito();
  }
}
