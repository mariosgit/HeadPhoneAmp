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
* (add an analog HP EQ - could be hacked into the OpAmp socket on the DAC board :) just lift the feedback pins and add some parts)

# Links

| DAC | AMP |
| --- | --- |
| CS4398 [DAC board like this](https://www.aliexpress.com/item/4000013124428.html?spm=a2g0o.productlist.0.0.3c4918649quVu4&algo_pvid=18450fce-c0a6-4c35-8596-8e73343cff46&algo_expid=18450fce-c0a6-4c35-8596-8e73343cff46-0&btsid=369025fc-1d40-4033-9a47-80dc7a496913&ws_ab_test=searchweb0_0,searchweb201602_5,searchweb201603_52) | HP AMP [TPA6120](https://www.aliexpress.com/item/33009022873.html?spm=a2g0o.productlist.0.0.44cd18c6uZEk8I&algo_pvid=68202129-c45c-407c-a77e-ace2c0134305&algo_expid=68202129-c45c-407c-a77e-ace2c0134305-0&btsid=e1ea3df3-0052-4e6e-938e-5456bce36f61&ws_ab_test=searchweb0_0,searchweb201602_5,searchweb201603_52) |
| ![DAC board](https://ae01.alicdn.com/kf/HTB1vwvxaAY2gK0jSZFgq6A5OFXaC/Optical-Coaxial-Audio-Decoder-Cs8416-Cs4398-Chip-24Bit192Khz-Spdif-Coaxial-Optical-Fiber-Dac-Decode-Board-for.jpg_220x220xz.jpg) | ![AMP](https://ae01.alicdn.com/kf/HLB1pHPyf13tHKVjSZSgq6x4QFXap/Tpa6120-Headphone-Amplifier-Board-Hifi-Tpa6120A2-Enthusiast-Headphones-Amp-Amplificador-Zero-Noise-Diy.jpg_220x220xz.jpg) |
| **Power** | **Display** |
| [Classic Trafo](https://www.reichelt.de/trafo-6va-2x-12v-2x-250ma-ui-30-10-5-212-p27548.html?&trstct=pol_5)  2x12V ~5W or more | [LED 0.36"](https://www.aliexpress.com/item/32869623201.html?spm=a2g0o.productlist.0.0.588b25c53beVNQ&algo_pvid=f4e53f3f-f191-4221-8414-23aea6d29d2a&algo_expid=f4e53f3f-f191-4221-8414-23aea6d29d2a-0&btsid=dc824e0f-71a9-4ad4-ba05-c1954363921b&ws_ab_test=searchweb0_0,searchweb201602_5,searchweb201603_52) TM1637 |
| ![](https://cdn-reichelt.de/bilder/web/artikel_ws/C500/!UI3010BL.jpg) | ![bild](https://ae01.alicdn.com/kf/HTB15zf.acvrK1Rjy0Feq6ATmVXaE/4-Digit-LED-0-36-inch-0-36-White-Display-Tube-Decimal-7-Segments-TM1637-Clock.jpg_220x220xz.jpg) |

ATTiny84 pinout
![pinout2](https://slideplayer.com/slide/6582475/23/images/24/ATtiny84+pinout+http:/forum.arduino.cc/index.php/topic,146315.0.html.jpg)

AVRISP
![avrisp](https://lh4.googleusercontent.com/_N4orY3Ztc3M/Tcq0gtaX_gI/AAAAAAAAAKM/9fju_il9l5U/s800/avrispmkII-pin-out.jpg)

Connect ISP to ATTiny84
![isp](https://42bots.com/wp-content/uploads/2014/01/programming-attiny44-attiny84-with-arduino-uno.png)