#include "MicroBit.h"
#include "SSD1306.h"

MicroBit uBit;

// Define the dimensions of the display.
#define OLED_WIDTH       128
#define OLED_HEIGHT      64

int main()
{  
    uBit.init();

    uBit.io.P19.setPull(PullMode::Up);
    uBit.io.P20.setPull(PullMode::Up);

    // Wait a while, just for ease of testing.
    uBit.sleep(1000);

    // Indicate we're starting...
    uBit.serial.printf("  INIT...");

    // Create the display driver
    SSD1306 *oled = new SSD1306(OLED_WIDTH, OLED_HEIGHT, 0x78);

    // Indicate we're starting...
    uBit.serial.printf("  DONE\r\n");

    // First byte in the dat abuffer MUST be 0x80 - this is part of the communication protocol.
    ManagedBuffer buf(((OLED_WIDTH * OLED_HEIGHT)/8) + 1);
    buf[0] = 0x40;

    // Set up an on/off pattern, just for testing.
    for (int i=1; i<buf.length(); i++)
        buf[i] = 0xFF;

    // Indicate we're about to send data...
    uBit.serial.printf("  SENDING IMAGE DATA...");

    // Send the image buffer to the OLED display
    oled->sendData(buf.getBytes(), buf.length());

    // Indicate we've finished...
    uBit.serial.printf("DONE\r\n", oled->_addr);

    // All done. Just sleep forever...
    while(1)
        uBit.sleep(1000);
}