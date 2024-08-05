# HeadPhoneAmp

New plan... Make my own HP Amp.

##### Requirements:

* EQ - I dont have many HP's which I don't want to EQ, they all need a little something.
* Lipo Powered !
* Line In

##### Goodies

* More Inputs (in that order)
   * USB (Teensy4 can also control DSP, Bluetooth, 16bit is ok for playback)
   * BT (just plug in a module CSR8635?)
   * WLAN (Radio, Subsonic and Ampache protocols for nextcloud music) cry for ESP32 (rabbithole! [bt a2dp](https://github.com/pschatzmann/ESP32-A2DP) [iradio](https://github.com/Edzelf/ESP32Radio-V2) [streem gedoehns](https://github.com/sle118/squeezelite-esp32) )
   * SPDIF (not really on a HP amp)
   * Analog++ Phono MM input with RIAA https://sound-au.com/project06.htm 
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

# Tested so far...

## HPAmp Design

TPA6120A2 it's big (there is a QFN version) and a TPS65135 power converter as per datasheet.

After some mangling, it performs well, no noise and quite some punch.

##### Bugs v0.1

* Wrong TPA6120 footprint :-(

##### Bugs v0.2 / Eval

* ~~Oszilation on left output 12MHz ?? goes awai when osziloscoping the input line !?~~ Gone after adding C5, C4 2.2u from se reste kiste.
* There is some noise and DC offset of 500mV, as is in the PRC breakout of this amp. Added 1k @ inputs to ground -> silence, no/minimal Vout offset.
* input resistors to ground ? **YES** !
    * 47k was noisy
    * 1k is ok, depends on input ? consider previous stage power output !
* 10uF caps footprint could be larger / dual 1206?
* On/Off clics ? Not too bad.
* Add TestPoints for L/R inputs
* Add LEDs for +-5V ?
* TestPoint and pullup for EN pin.
* More ground pads.
* Does not work with small BAT/Charger? Toggles on/off

## Power Block Design

* Use Adafruit PowerThing ?
    * Added charge pump for 10V as in the DS
* How to get the teensy integrated, would need to patch into VUSB -> PowerBlock -> 5V back to the Teensy ?
    * Cut trace in the back, solder some wire to VUSB ? Or use pogopins ? Not nice.
* Noise ??? Will see... yes 200mVpp @ 65kHz, audible when directly driving a 16ohm speaker

* Cap Mult for analog voltage, or just a regulator ? [SIM](https://www.falstad.com/circuit/circuitjs.html?ctz=CQAgjCAMB0l3BWcDoBYDsAmdA2dBOdMMADhzEnxAQiVQGZqBTAWmICgAnEbTHkkjyzgwfSMkjsAxuHx8wuWX0ypxa2PEiY+6aPjAMi6dJAOpMCdCDaTuOVOEVgc4hTig9McdgDdr+d20HFgCRMXBweAiqdQR2AHN-QJUk-kE1BKFlASyQekgHDIB3HkhBYmVhCvB2ABclcFQHMDkwvIiWGDl9fEh0BHwEchILMWgcQYQtS3xzPonmuBAAEyYAMwBDAFcAG1r2EpbswV40qAOGt0um88OXR3cjxsKL+weQN+qwV+bRd+rJAAHPIIeQ3eigniqdrFEFghwQ+R-SQlRFtU4Ai5olTibE5FFws6nTD4i4hdwseh8cltAk06qfZEXJ6oE7CVnnGRPSnyVoc9SaLR8EjQYxgBAIVT0QgUVA4QQ2TIs8qtN4ZbinDmnHkecVAwk6tEcxiwo1svj8smhHVsClU24NHXa+3fErOvhonW2azOawu1pemqHVoklXKaGSAD27XSIAAHiQTGAAEYfKAaUy6njWdD0djRsCMWMJ-J-eh6HDkBACPDEaX0dwweAQFvZli4fPgIseONSQt-CjpiDyCIwJBRqEgYt90zydQQRitsfnejlEAAMQgAs0W4zFAgbBAAGENoCNlIAJa1DYAOykTHYq48m6z+59IAASkwAM4X7-Xu8HyAA)

##### Results v0.1

* C6 can be much larger according to DS. Available up to 220uF.
* Has no BAT protection ? The testbat emptied down to 2V ! Just clarify.
* Make charge Amps quick changeable with a PHT resistor ?
* Could add a PG PowerGood LED, this shows when device is connected to some power source
* Check 10V load ❗
* Add option for higher voltage as in the GP??94 controller ?

##### Bugs v0.1

* ! Q1 (low bat indicator) is **wrong** MMUN2133LT1G it's BEC(123) - just switched to the "BEC" symbol. ✅
* C5 (+10V) was connected to ground, should be between +10 and +5V, works anyway ✅
* Can it provide 50V using a longer charge pump ?

# Next up ?


## NuTube

* Create own board 
    * Bias voltage driven by OpAmp ! Input a single Pot or CV
    * With ADC ? as a FX loopback ?
* Loop back Nutube to DSP ? With an extra ADC or CODEC ? Ad


## VFD/OLED

* Make board for MN12832 ?
    * Can I borrow voltage from the power block ? Add more charge pumps..

## Teensy/ESP32/STM32 + DSP

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

## BT Audio

* Ahh just another SRC needed ??? Or switch them between Teensy and BT ? And SPDif ?
* Make a SPDIF/BT/USB I2S Switch + SRC  block design. it's all there.


    

# Log

| What | Time | Cost || What | Time | Cost |
|---|---|---|---|---|---|---|
| Make Power PCB | 1d | | | Test,Fix Power PCB | 1d | |
|  Make HPBooster PCB | 1d | | | | | |
| both mat+pcb | | 50 + 30 | | |

# Refs

Used some Symbols... https://github.com/wykys/klib 

Ti's [I2C expander collection](https://www.ti.com/interface/i2c/general-purpose-ios-gpios/overview.html?keyMatch=i/o%20expander&tisearch=search-everything)
