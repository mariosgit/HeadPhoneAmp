#include <Arduino.h>
#include <TM1637Display.h>
#include <TinyWireM.h>

// I2C:
// TinyWireM: https://github.com/adafruit/TinyWireM

// 7 Segment LED Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3

#define pinVolume A0
// #define PORT_USI_SDA	PA6
// #define PORT_USI_SCL	PA4

// The amount of time (in milliseconds) between tests
#define TEST_DELAY 2000

const uint8_t SEG_DONE[] = {
    SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,         // d
    SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F, // O
    SEG_C | SEG_E | SEG_G,                         // n
    SEG_A | SEG_D | SEG_E | SEG_F | SEG_G          // E
};

TM1637Display display(CLK, DIO);

void setup()
{
    TinyWireM.begin();
    /*
        TinyWireM.beginTransmission(DS1621_ADDR);
        TinyWireM.send(0xAC);                 // Access Command Register
        TinyWireM.send(B00000001);            // Using one-shot mode for battery savings
        //TinyWireM.send(B00000000);          // if setting continious mode for fast reads
        TinyWireM.endTransmission();          // Send to the slave

        CS4398 Test mit Mute on/off
        Mute Register = 0x04
        default = B11000000 = 0xC0
        muted =   B11011000 = 0xd8

        write = adr + regadr + data
                10011xx + 0x04 + 0xd8
                xx are what the AD[10] pins are set to.

    */
    // this should mute it
    TinyWireM.beginTransmission(B01001100);
    TinyWireM.send(0x04);
    TinyWireM.send(B11011000);
    TinyWireM.endTransmission();
}

void loop()
{
    // example for volume control
    while(1)
    {
        // CS4398 volume: 0=0dB, 1=-.5dB, 255=-127.5 dB
        int aval = analogRead(pinVolume) - 1023;
        display.showNumberDec(aval / 8, false); // Expect: ___0
        delay(20);
    }

    int k;
    uint8_t data[] = {0xff, 0xff, 0xff, 0xff};
    display.setBrightness(0x0f);

    // All segments on
    display.setSegments(data);
    delay(TEST_DELAY);

    // Selectively set different digits
    data[0] = display.encodeDigit(0);
    data[1] = display.encodeDigit(1);
    data[2] = display.encodeDigit(2);
    data[3] = display.encodeDigit(3);
    display.setSegments(data);
    delay(TEST_DELAY);

    /*
  for(k = 3; k >= 0; k--) {
	display.setSegments(data, 1, k);
	delay(TEST_DELAY);
	}
  */

    display.clear();
    display.setSegments(data + 2, 2, 2);
    delay(TEST_DELAY);

    display.clear();
    display.setSegments(data + 2, 2, 1);
    delay(TEST_DELAY);

    display.clear();
    display.setSegments(data + 1, 3, 1);
    delay(TEST_DELAY);

    // Show decimal numbers with/without leading zeros
    display.showNumberDec(0, false); // Expect: ___0
    delay(TEST_DELAY);
    display.showNumberDec(0, true); // Expect: 0000
    delay(TEST_DELAY);
    display.showNumberDec(1, false); // Expect: ___1
    delay(TEST_DELAY);
    display.showNumberDec(1, true); // Expect: 0001
    delay(TEST_DELAY);
    display.showNumberDec(301, false); // Expect: _301
    delay(TEST_DELAY);
    display.showNumberDec(301, true); // Expect: 0301
    delay(TEST_DELAY);
    display.clear();
    display.showNumberDec(14, false, 2, 1); // Expect: _14_
    delay(TEST_DELAY);
    display.clear();
    display.showNumberDec(4, true, 2, 2); // Expect: __04
    delay(TEST_DELAY);
    display.showNumberDec(-1, false); // Expect: __-1
    delay(TEST_DELAY);
    display.showNumberDec(-12); // Expect: _-12
    delay(TEST_DELAY);
    display.showNumberDec(-999); // Expect: -999
    delay(TEST_DELAY);
    display.clear();
    display.showNumberDec(-5, false, 3, 0); // Expect: _-5_
    delay(TEST_DELAY);
    display.showNumberHexEx(0xf1af); // Expect: f1Af
    delay(TEST_DELAY);
    display.showNumberHexEx(0x2c); // Expect: __2C
    delay(TEST_DELAY);
    display.showNumberHexEx(0xd1, 0, true); // Expect: 00d1
    delay(TEST_DELAY);
    display.clear();
    display.showNumberHexEx(0xd1, 0, true, 2); // Expect: d1__
    delay(TEST_DELAY);

    // Run through all the dots
    for (k = 0; k <= 4; k++)
    {
        display.showNumberDecEx(0, (0x80 >> k), true);
        delay(TEST_DELAY);
    }

    // Brightness Test
    for (k = 0; k < 4; k++)
        data[k] = 0xff;
    for (k = 0; k < 7; k++)
    {
        display.setBrightness(k);
        display.setSegments(data);
        delay(TEST_DELAY);
    }

    // On/Off test
    for (k = 0; k < 4; k++)
    {
        display.setBrightness(7, false); // Turn off
        display.setSegments(data);
        delay(TEST_DELAY);
        display.setBrightness(7, true); // Turn on
        display.setSegments(data);
        delay(TEST_DELAY);
    }

    // Done!
    display.setSegments(SEG_DONE);

    //   while(1);
}
