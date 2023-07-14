/*MIDI CLOCK TO TAP TEMPO w/3 TAPS-Charlie Hobbs 2015 (based off of Littlescale's 'Midi Sync'  */
#include <elapsedMillis.h>

elapsedMillis timeElapsed;
unsigned long prevInterval;
unsigned long interval;
byte midi_start = 0xfa;
byte midi_stop = 0xfc;
byte midi_clock = 0xf8;
byte midi_continue = 0xfb;

byte data;
byte counter;
int tapCount = 0;
byte clickCounter;


int tapPin = 2;
int LED = 13;
int note = 24; // tap on: whole note = 96;  half note = 48; quarter note = 24



void setup() {
pinMode (tapPin, OUTPUT);
pinMode (LED, OUTPUT);
Serial.begin(31250);
}

void loop() {
if(Serial.available() > 0) {
   data = Serial.read();
  if(data == midi_clock) {
     count();
     Sync();
    // delay (10);
    }
  }
}




void Sync() {
 if(counter == note) {
      counter = 0;
   }
 if((counter == 0) && (tapCount<= 3)){
     digitalWrite(tapPin, HIGH);
     digitalWrite(LED, HIGH);
     tapCount++;
   }
 if(counter == 6){ // this will set the duration of the tap
      digitalWrite(tapPin, LOW); 
      digitalWrite(LED, LOW);
   }
 if (interval != prevInterval){
      tapCount = 0;
   } 
 counter++;
 prevInterval= interval;
 } 


void count(){
   if(clickCounter >= 71){  //72(#clicks counted= 3 quarter notes)
      interval = timeElapsed/72;
      timeElapsed = 0;
      clickCounter = 0;
   }
   clickCounter++;
 
}  
 

