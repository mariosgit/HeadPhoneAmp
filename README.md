# HeadPhoneAmp

Got a CS4398 DAC and a TPA6120 based HP AMP board from China.
They can just be plugged together to work but that's not cool, just like the crapy Volume Pot on the AMP.
So The idea is to develop a digital volume control, a ATTiny84 which reads a pot and sends volume data via i2c to the DAC, that should result in a more hifiish product. Also got a simple 4 digid LED display to show the volume level. Eventually a button to switch digital filters could be added too...

# Status

* Theory ok.
* All Parts aquired.

# Todo

* find I2C port on the DAC board
* wire up the ATiny
* program it
* housing !
* (add an analog HP EQ)

# Links

ATTiny84 pinout
![attiny84](https://1.bp.blogspot.com/-ls0T5IG8Sqk/Ugpi7XUCIpI/AAAAAAAAE2I/AjR5pnzEZ-U/s1600/attiny84+Pins+for+arduino-tiny+cores.jpg "ATTiny84")

Connect ISP to ATTiny84
![isp](https://42bots.com/wp-content/uploads/2014/01/programming-attiny44-attiny84-with-arduino-uno.png)