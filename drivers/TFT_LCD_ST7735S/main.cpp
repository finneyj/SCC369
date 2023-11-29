#include "MicroBit.h"
#include "Adafruit_ST7735.h"

MicroBit uBit;

// Define the MICROBIT EDGE CONNECTOR pins where the display is connected...
#define LCD_PIN_CS      2
#define LCD_PIN_DC      1
#define LCD_PIN_RST     0
#define LCD_PIN_MOSI    15
#define LCD_PIN_MISO    14
#define LCD_PIN_SCLK    13

// Define the dimensions of the display.
#define LCD_WIDTH       128
#define LCD_HEIGHT      160

// Some useful constants for primaries. I *think* these are right, but might be off by one LSB bit :)
#define LCD_RED_16_BIT      0xFC00
#define LCD_BLUE_16_BIT     0x03E0
#define LCD_GREEN_16_BIT    0x001F

// Utility function to fill a given buffer with the given colour
void setColour(ManagedBuffer buf, uint16_t value)
{
    uint16_t *p = (uint16_t *) &buf[0];

    while(p < (uint16_t *) &buf[buf.length()])
    {
        *p = value;
        p++;
    }
}

int main()
{  
    uBit.init();

    // wait a little while, just to make sure the LCD is full powered on.
    // not sure if we need this, but good to be conservative when developing!
    uBit.sleep(100);

    // Create some memory to hold our screen buffer at 16 bits per pixel.
    ManagedBuffer img(LCD_WIDTH * LCD_HEIGHT * 2);
    int colour = 0;

    // Indicate we're starting...
    uBit.serial.printf("  INIT...");

    // Bring up the SPI display driver.
    Adafruit_ST7735 *lcd = new Adafruit_ST7735(LCD_PIN_CS, LCD_PIN_DC, LCD_PIN_RST, LCD_PIN_MOSI, LCD_PIN_MISO, LCD_PIN_SCLK);
    lcd->initR(INITR_GREENTAB);

    uBit.serial.printf("  DONE\r\n");

    while(1)
    {
        uBit.serial.printf("  NEXT COLOUR...");

        if (colour == 0)
        {
            uBit.serial.printf("  GREEN...");
            setColour(img, LCD_GREEN_16_BIT);
        }

        if (colour == 1)
        {
            uBit.serial.printf("  RED...");
            setColour(img, LCD_RED_16_BIT);
        }

        if (colour == 2)
        {
            uBit.serial.printf("  BLUE...");
            setColour(img, LCD_BLUE_16_BIT);
        }
        
        uBit.serial.printf("\r\n");
        
        colour++;

        if (colour == 3)
            colour = 0;

        lcd->sendData(0, 0, LCD_WIDTH, LCD_HEIGHT, img.getBytes());

        uBit.sleep(500);
    }
}

