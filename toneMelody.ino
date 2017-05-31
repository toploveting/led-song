/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone

 */
#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_A6, NOTE_C7, NOTE_C7, NOTE_E7, NOTE_E7,  NOTE_E7, NOTE_E7, NOTE_E7, NOTE_C7, 
  NOTE_C7, NOTE_G7, NOTE_G7, NOTE_F7, NOTE_E7,  NOTE_D7, 
  NOTE_A6, NOTE_B6, NOTE_C7, NOTE_E7, NOTE_E7,  NOTE_E7, NOTE_E7, NOTE_E7, NOTE_C7,
  NOTE_C7, NOTE_G7, NOTE_G7, NOTE_F7, NOTE_E7,  NOTE_D7, 
  NOTE_D7, NOTE_D7, NOTE_E7, NOTE_F7, NOTE_E7,  NOTE_C7, NOTE_F7, NOTE_E7,
  NOTE_C7, NOTE_F7, NOTE_E7, NOTE_C7, NOTE_F7,  NOTE_E7,
  NOTE_C7, NOTE_G7, NOTE_G7, NOTE_F7, NOTE_E7,  NOTE_D7
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 2, 4, 8, 4, 4, 4, 2,
  4, 4, 2, 4, 4, 2, 
  4, 4, 2, 4, 8, 4, 4, 4, 2,
  4, 4, 2, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2, 2, 
  4, 4, 4, 4, 2, 2, 
  4, 4, 2, 4, 4, 2
};
int greenPin = 6;
int redPin = 9;
int bluePin = 5;
int counter = 0;
void setup() {
  pinMode(greenPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 50; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    counter = (thisNote%10);
 if(counter == 1){//紅
    analogWrite(greenPin,0);
    analogWrite(redPin,255);
    analogWrite(bluePin,0);
  }
  else if(counter == 2){//橙
    analogWrite(greenPin,50);
    analogWrite(redPin,255);
    analogWrite(bluePin,0);
  }
  else if(counter == 3){//黃
   analogWrite(greenPin,255);
    analogWrite(redPin,255);
    analogWrite(bluePin,0);
  }
  else if(counter == 4){//綠
   analogWrite(greenPin,255);
    analogWrite(redPin,0);
    analogWrite(bluePin,0);
  }
  else if(counter == 5){//藍
    analogWrite(greenPin,0);
    analogWrite(redPin,0);
    analogWrite(bluePin,255);
  }
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  
  }

  // no need to repeat the melody.




