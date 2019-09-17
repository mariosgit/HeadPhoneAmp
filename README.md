# HeadPhoneAmp

Got a CS4398 DAC and a Tpa6120 base HP AMP board from China.
They can just be plugged together to work but that's not cool, just like the Volume Pot on the AMP.
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