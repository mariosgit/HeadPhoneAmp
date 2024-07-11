# HeadPhoneAmp

New plan... Make my own HP Amp.

##### Requirements:

* EQ - I dont have many HP's which I don't want to EQ, they all need a little something.
* Lipo Powered !
* Line In

##### Goodies

* More Inputs (in that order)
   * USB (Teensy4 can also control DSP, Bluetooth, 16bit is ok for playback), SPDIF
* Second output ? With it's own EQ and Volume ?
* NuTube or Simulation of a little distortion. Maybe other effects ?
* MP3 player - there is one for the teensy. Would need SDCard or so, How to copy files ? Just swap the card ? The Cardhold would obscure the VUSB hack !
* ~~Radio streaming.. WLAN hasl...~~

# Status

* Theory is somewhat more defined in my head.
* Started to build some blocks
    * TPA6120 module - Made my own, running with only single 5V - to be tested.
    * DSP - I have a freeDSP-SMD-B to experiment with
    * NuTube ? I have a NuTube HP Amp which is'nt great but could be recycled into something usefull - not so available !

# Next up ?

#### HPAmp design ?

* TPA6120A2 in the works with 5V conveter no Elkos it's big (there is a QFN version)
* TPA6130A2 ??? 5V only, I2C Vol Ctl, no Elkos !?
* TPA6133A2 ??? same, no vol ctl

#### Teensy + DSP

* Can the teensy be slave i2s ??? Otherwise it would need an extra SRC.
    There is a slave i2s out... Will it work with usb, does it need to be 44100kHz ?
    ```
    AudioInputUSB            usb1;
    AudioOutputI2Sslave      i2sslave1;
    AudioConnection          patchCord1(usb1, 0, i2sslave1, 0);
    AudioConnection          patchCord2(usb1, 1, i2sslave1, 1);
    ```
    ```File > Examples > Audio > HardwareTesting > WM8731MikroSine```
    *Notes: Slave mode I2S should not used in the same project as ADC, DAC and PWM signals. Differences in timing between the I2S device and Teensy's clock can cause occasional audio glitches when I2S slave mode is used together with other input or output objects based on Teensy's timing. ...Only one I2S input and one I2S output object may be used. Master and slave modes may not be mixed (both must be of the same type).*
    Mhm wanted to use the internal DAC for NuTube bias...
* Test I2S slave (with DSP)
* Test internal DAC for NuTube

#### Power Block Design

* Use Adafruit PowerThing ?
    * Use a TPS61093 ? Higher output voltage ? For NuTube ?
* How to get the teensy integrated, would need to patch into VUSB -> PowerBlock -> 5V back to the Teensy ?
    * Cut trace in the back, solder some wire to VUSB ? Or use pogopins ? Not nice.
* Noise ???

#### BT Audio

* Ahh just another SRC needed ??? Or switch them between Teensy and BT ? And SPDif ?
* Make a SPDIF/BT/USB I2S Switch + SRC  block design. it's all there.

##### Advanced 

* Loop back Nutube ? With an extra ADC or CODEC ? Ad

# Refs

Used some Symbols... https://github.com/wykys/klib 

