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

| DAC | AMP |
| ------- | -------- |
| CS4398 [DAC board like this](https://www.aliexpress.com/item/4000013124428.html?spm=a2g0o.productlist.0.0.3c4918649quVu4&algo_pvid=18450fce-c0a6-4c35-8596-8e73343cff46&algo_expid=18450fce-c0a6-4c35-8596-8e73343cff46-0&btsid=369025fc-1d40-4033-9a47-80dc7a496913&ws_ab_test=searchweb0_0,searchweb201602_5,searchweb201603_52) | HP AMP [TPA6120](https://www.aliexpress.com/item/33009022873.html?spm=a2g0o.productlist.0.0.44cd18c6uZEk8I&algo_pvid=68202129-c45c-407c-a77e-ace2c0134305&algo_expid=68202129-c45c-407c-a77e-ace2c0134305-0&btsid=e1ea3df3-0052-4e6e-938e-5456bce36f61&ws_ab_test=searchweb0_0,searchweb201602_5,searchweb201603_52) |
| ![DAC board](https://ae01.alicdn.com/kf/HTB1vwvxaAY2gK0jSZFgq6A5OFXaC/Optical-Coaxial-Audio-Decoder-Cs8416-Cs4398-Chip-24Bit192Khz-Spdif-Coaxial-Optical-Fiber-Dac-Decode-Board-for.jpg_220x220xz.jpg) | ![AMP](https://ae01.alicdn.com/kf/HLB1pHPyf13tHKVjSZSgq6x4QFXap/Tpa6120-Headphone-Amplifier-Board-Hifi-Tpa6120A2-Enthusiast-Headphones-Amp-Amplificador-Zero-Noise-Diy.jpg_220x220xz.jpg) |

ATTiny84 pinout
![pinout2](https://slideplayer.com/slide/6582475/23/images/24/ATtiny84+pinout+http:/forum.arduino.cc/index.php/topic,146315.0.html.jpg)

Connect ISP to ATTiny84
![isp](https://42bots.com/wp-content/uploads/2014/01/programming-attiny44-attiny84-with-arduino-uno.png)