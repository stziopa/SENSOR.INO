/*
2025-06-28 SENSOR.INO WORKSHOP VKB

Piezo vibration 2 MIDI
Connect piezo to pin A1
(don't forget to put a 1M resistor in between A1 and GND)
*/

#include <MIDI.h>

//Pin definitions
int piezoPin = A1;
int piezoValue;
int piezoThreshold = 5; //change piezo sensitivity

//MIDI stuff
MIDI_CREATE_DEFAULT_INSTANCE();
//define piezo MIDI note
byte note = 36;
byte velocity = 100;

// TIMING STUFF
//note Duration in milliseconds
int noteDuration = 50;

void setup() {
  MIDI.begin(MIDI_CHANNEL_OFF);

  //Turn OFF any hanging notes
  MIDI.sendControlChange(123, 0, 1);
}

void loop() {

  piezoValue = analogRead(piezoPin);

  if(piezoValue > piezoThreshold) {
    MIDI.sendNoteOn(note, velocity, 1);
    delay(noteDuration);
    MIDI.sendNoteOff(note, 0, 1);
  }

  //wait before repeating the cycle again
  //delay(LDRValue);
}
