# SENSOR.INO
is an Arduino workshop for electronic music producers, musicians but also for media artists, makers and enthusiasts who want to explore the possibilities of environmental sensors in their creative workflow.

This respository is organized in folders according to the workshop you attended. Each folder contains the sketches for the sensors which were provided with the kit.

## Some useful instructions...
In order to upload the sketches to the device the easiest way is to download the [Arduino IDE](https://www.arduino.cc/en/software/) and the serial drivers of your board.

The boards provided with the workshop are usually based on the USB-serial chips:

- CH320G which can be downloaded from [here](https://learn.sparkfun.com/tutorials/how-to-install-ch340-drivers/all)
- FT232R which can be downloaded from [here](https://ftdichip.com/drivers/vcp-drivers/)

If you don't know which driver your board is using, you can try the first one or download both. After you install them your computer should be able to see the board from the Arduino IDE.

The Arduino sketches also requires to install additional libraries such as:
- Arduino MIDI Library from [FortySevenEffects](https://github.com/FortySevenEffects/arduino_midi_library) **(this one is mandatory!)**
- some specific sensor library (as for example the digital temperature and humidty ones, which might differ from each kit, more info in the comments inside the sketch) 

All the used libraries can be installed from the Arduino IDE library management window or from the links provided inside the sketches.

Please let me know if I forgot to mention something and thank you once again for attending the workshop 🙏 


