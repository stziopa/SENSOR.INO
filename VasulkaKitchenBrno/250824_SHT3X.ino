/*
2025-08-24 SENSOR.INO WORKSHOP VKB

SHT3X Temperature and Humidity sensor 2 MIDI
Connect sensor to I2C pins of arduino nano as follows:
SDA (Data Line): Pin A4
SCL (Clock Line): Pin A5

library from: https://github.com/ArtronShop/ArtronShop_SHT3x

*/

#include <MIDI.h>
#include <Wire.h>
#include <ArtronShop_SHT3x.h>

ArtronShop_SHT3x sht3x(0x44, &Wire); // ADDR: 0 => 0x44, ADDR: 1 => 0x45

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

  //Start i2c communication
  Wire.begin();
}

void loop() {

  if (sht3x.measure()) {
    note = (sht3x.temperature()+40); //map -40°C to 125°C to 0-127
    velocity = (sht3x.humidity()+27); //map 0-100% rH to 0-127
  }  
  /*
    else {
    note = 60;
    velocity = 100;
  }*/

  //digitalWrite(LED, HIGH);
  MIDI.sendNoteOn(note, velocity, 1);
  delay(noteDuration);
  MIDI.sendNoteOff(note, 0, 1);

  //wait before repeating the cycle again
  delay((delayValue-noteDuration));
}
