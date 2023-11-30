A simple CODAL driver for the SCC369 2.9' 296x128 monochrome eink display module
This code is ported from the Waveshare arduino driver: https://github.com/waveshareteam/e-Paper/blob/4822c075f5df714f88b02e10c336b4eeff7e603e/RaspberryPi_JetsonNano/c/lib/e-Paper/EPD_2in9.c

INSTALLATION
============

Place this code into the "source" folder of you microbit-v2-samples build, and compile as normal using "python build.py" in the root microbit-v2-samples folder. Copy the resulting HEX file to the micro:bit v2 as normal.

Once running, this should display two images of cats


HARDWARE CONFIGURATION
======================

The driver can be configured to use any of the edge connector pins. The main.cpp file illustrates this. To run this example "out of the box" wire up the hardware as follows:

| LCD Module Pin | Edge Connector Pin | Role             |
| -------------- | ------------------ | ---------------- |
| GND            | 0V                 | Power Supply 0V  |
| VCC            | P0                 | Power Supply 3V  |
| DIN            | P15                | SPI Data In      |
| CLK            | P13                | SPI Clock        |
| RST            | P8                 | RESET            |
| DC             | P9                 | DATA/COMMAND     |
| CS             | P16                | CHIP SELECT      |
| BUSY           | P2                 | BUSY             |
