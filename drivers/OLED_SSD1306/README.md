A simple CODAL driver for the SCC369 I2C 0.96-inch OLED Display module 
This code is ported from a trult hideous micropython driver: https://wiki.52pi.com/index.php?title=S-0018

INSTALLATION
============

Place this code into the "source" folder of you microbit-v2-samples build, and compile as normal using "python build.py" in the root microbit-v2-samples folder. Copy the resulting HEX file to the micro:bit v2 as normal.

Once running, this should illuminate all the pixels on the display.


HARDWARE CONFIGURATION
======================

The driver uses the defaul I2C edge connector pins. To run this example "out of the box" wire up the hardware as follows:

| LCD Module Pin | Edge Connector Pin | Role             |
| -------------- | ------------------ | ---------------- |
| GND            | 0V                 | Power Supply 0V  |
| Vcc            | 3V                 | Power Supply 3V  |
| SCL            | P19                | SPI Clock        |
| SDA            | P20                | SPI Main Output  |
