/*
2025-08-24 SENSOR.INO WORKSHOP VKB

Light sensor (LDR) 2 MIDI
Connect LDR to pin A0 
(don't forget to use a 100K pulldown resistor)
*/

#include <MIDI.h>

//Pin definitions
int LDRPin = A0;
int LDRValue;

//MIDI stuff
MIDI_CREATE_DEFAULT_INSTANCE();
//default Note and Velocity if no sensor connected
byte note = 60;
byte velocity = 100;

// TIMING STUFF
//note Duration in milliseconds
int noteDuration = 50;
//Time in between each cycle (it must be > noteDuration)
int delayValue = 1000;

void setup() {
  MIDI.begin(MIDI_CHANNEL_OFF);

  //Turn OFF any hanging notes
  MIDI.sendControlChange(123, 0, 1);
}

void loop() {

  LDRValue = analogRead(LDRPin);
  //invert the reading: more light
  LDRValue = (1024-LDRValue);

  //digitalWrite(LED, HIGH);
  MIDI.sendNoteOn(note, velocity, 1);
  delay(noteDuration);
  MIDI.sendNoteOff(note, 0, 1);

  //wait before repeating the cycle again
  delay(LDRValue);
}
