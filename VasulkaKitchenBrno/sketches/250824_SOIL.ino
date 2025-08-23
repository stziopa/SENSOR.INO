/*
2025-08-24 SENSOR.INO WORKSHOP VKB

Soil moisture sensor 2 MIDI
Connect piezo to pin A2
*/

#include <MIDI.h>

//Pin definitions
int soilPin = A2;
int soilValue;

//MIDI stuff
MIDI_CREATE_DEFAULT_INSTANCE();
//define piezo MIDI note
//byte note = 60;
//byte velocity = 100;
int pitchBend = 8192; //initialize pitchbend to center

// TIMING STUFF
//note Duration in milliseconds
//int noteDuration = 1000;


void setup() {
  MIDI.begin(MIDI_CHANNEL_OFF);

  //Turn OFF any hanging notes
  MIDI.sendControlChange(123, 0, 1);
}

void loop() {
  
  soilValue = analogRead(soilPin);
  pitchBend = map(soilValue, 0, 1023, 0, 16384); //scale to MIDI pitchbend range
  MIDI.sendPitchBend(pitchBend, 1);
  
  delay(10);
}
