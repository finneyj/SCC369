A simple CODAL driver for the SCC369 2.13' 250x122 BLACK/WHITE AND OR RED Display

INSTALLATION
============

Place this code into the "source" folder of you microbit-v2-samples build, and compile as normal using "python build.py" in the root microbit-v2-samples folder. Copy the resulting HEX file to the micro:bit v2 as normal.

Once running, this should display a red image example, a black image example and then two images of cats

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
| CS             | P1 <               | CHIP SELECT      |
| BUSY           | P2                 | BUSY             |
