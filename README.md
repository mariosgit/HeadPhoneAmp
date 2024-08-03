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

* TPA6120A2 in the works with 5V conveter, it's big (there is a QFN version)

##### Bugs v0.1

* Wrong TPA footprint :-((

##### Bugs v0.2 / Eval

* ~~Oszilation on left output 12MHz ?? goes awai when osziloscoping the input line !?~~ Gone after adding C5, C4 2.2u from se reste kiste.
* There is some noise, as is in the PRC breakout of this amp. Added 1k @ inputs to ground -> silence, no out v offset allmost.
* input resistors to ground ? **YES** !
    * 47k was noisy
    * 1k is ok, depends on input ? previous stage power !
* 10uF caps footprint could be larger / dual 1206?
* On/Off clics ? Not too bad.
* Add TPs for L/R inputs
* Add LEDs for +-5V ?

#### Power Block Design

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

* ! Q1 is **wrong** MMUN2133LT1G it's BEC(123) - just switched to the "BEC" symbol. ✅
* C5 (+10V) was connected to ground, should be between +10 and +5V, works anyway ✅

#### NuTube

* Create own board 
    * Bias voltage driven by OpAmp ! Input a single Pot or CV
    * With ADC ? as a FX loopback ?

#### VFD/OLED

* Make board for MN12832 ?
    * Can I borrow voltage from the booster ? Add more charge pumps..

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

#### BT Audio

* Ahh just another SRC needed ??? Or switch them between Teensy and BT ? And SPDif ?
* Make a SPDIF/BT/USB I2S Switch + SRC  block design. it's all there.

##### Advanced 

* Loop back Nutube ? With an extra ADC or CODEC ? Ad

* Voltage monitoring TI Chips... [Supervisor IC for voltage monitoring ?](https://www.ti.com/power-management/supervisor-reset-ic/products.html#1455=1%3B1&)
    * [Undervoltage detectors](https://www.ti.com/power-management/supervisor-reset-ic/products.html#1455=1%3B1&1811=3%20x%206.4%3B4.2%20x%203.26%3B4.9%20x%206%3B9.81%20x%209.43&2192=Undervoltage%3BUndervoltage%20and%20overvoltage%20monitor%3BUndervoltage%20monitor%20only&2954=SOIC%3BSOT-23%3BSOT-23-THN%3BSOT-5X3%3BTSSOP%3BWSON&790typ=Adjustable%3Badjustable%3BTrimmable&)
    * TL7712A: /reset and reset signal @ 12V ? Looks simple enouth.Variants with lower voltage available. Max Voltage 20V !
    * TPS38X-Q1 Wide VIN 65 V, dual voltage... X-choose type of action, have to order concrete function, 80cent , also can. TPS38F010122DSKRQ1 ???  qfn/wson 10 ?
        * [TPS37F010122DSKR ???](https://www.ti.com/lit/ds/symlink/tps37.pdf) 3EUR der Pups, output=HIGH  otherwise use A version
    

# Log

| What | Time | Cost || What | Time | Cost |
|---|---|---|---|---|---|---|
| Make Power PCB | 1d | | | Test,Fix Power PCB | 1d | |
|  Make HPBooster PCB | 1d | | | | | |
| both mat+pcb | | 50 + 30 | | |

# Refs

Used some Symbols... https://github.com/wykys/klib 

Ti's [I2C expander collection](https://www.ti.com/interface/i2c/general-purpose-ios-gpios/overview.html?keyMatch=i/o%20expander&tisearch=search-everything)
