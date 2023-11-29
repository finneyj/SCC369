A simple CODAL driver for the SCC369 1.8' 128x160 RGB TFT_LCD module 
This code is ported from the Adafruit arduino driver: https://github.com/adafruit/Adafruit-ST7735-Library/

INSTALLATION
============

Place this code into the "source" folder of you microbit-v2-samples build, and compile as normal using "python build.py" in the root microbit-v2-samples folder. Copy the resulting HEX file to the micro:bit v2 as normal.

Once running, this should cycle through the primary colours on the display.


HARDWARE CONFIGURATION
======================

The driver can be configured to use any of the edge connector pins. The main.cpp file illustrates this. To run this example "out of the box" wire up the hardware as follows:

| LCD Module Pin | Edge Connector Pin | Role             |
| -------------- | ------------------ | ---------------- |
| GND            | 0V                 | Power Supply 0V  |
| Vcc            | 3V                 | Power Supply 3V  |
| SCK            | P13                | SPI Clock        |
| SDA            | P15                | SPI Main Output  |
| RES            | P0                 | LCD RESET        |
| DC             | P1                 | LCD DATA/COMMAND |
| CS             | P2                 | LCD CHIP SELECT  |

