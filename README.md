# HeadPhoneAmp

Got a CS4398 DAC and a TPA6120 based HP AMP board from China.
They can just be plugged together to work but that's not cool, just like the crapy Volume Pot on the AMP.
So The idea is to develop a digital volume control, a ATTiny84 which reads a pot and sends volume data via i2c to the DAC, that should result in a more hifiish product. Also got a simple 4 digid LED display to show the volume level. Eventually a button to switch digital filters could be added too...

# Status

* Theory ok.
* All Parts aquired.
* Tested DAC+AMP.
    * Bad Pot - no LOG, channels unequal
    * Too Loud / Gain / Pot Range

## Pin Assignment

Poti:
* any Analog in: A1/D9

I2C:
* PORT_USI_SDA	PA6
* PORT_USI_SCL	PA4

LED Disp:
* CLK:  D2
* DATA: D3



# Todo

* find I2C port on the DAC board
* wire up the ATiny
* program it
* housing !
* (add an analog HP EQ)

# Links

ATTiny84 pinout
![pinout2](https://slideplayer.com/slide/6582475/23/images/24/ATtiny84+pinout+http:/forum.arduino.cc/index.php/topic,146315.0.html.jpg)

Connect ISP to ATTiny84
![isp](https://42bots.com/wp-content/uploads/2014/01/programming-attiny44-attiny84-with-arduino-uno.png)