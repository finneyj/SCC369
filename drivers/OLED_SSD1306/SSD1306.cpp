
#include "SSD1306.h"

/**************************************************************************/
/*!
    @brief  Instantiate Adafruit ST77XX driver with software SPI
    @param  w     Display width in pixels at default rotation setting (0)
    @param  h     Display height in pixels at default rotation setting (0)
    @param  sda   I2C SDA pin #
    @param  scl   I2C SCL pin #
*/
/**************************************************************************/
SSD1306::SSD1306(uint16_t width, uint16_t height, uint8_t address)
{
  _width = width;
  _height = height;

  _external_vcc = 0;
  _addr = address;

  _pages = height / 8;

  // Initialize the display.
  writeCommand(SSD1306_SET_DISP);

  writeCommand(SSD1306_SET_MEM_ADDR);
  writeCommand(0);

  writeCommand(SSD1306_SET_DISP_START_LINE);

  writeCommand(SSD1306_SET_SEG_REMAP | 0x01);

  writeCommand(SSD1306_SET_MUX_RATIO);
  writeCommand(height - 1);

  writeCommand(SSD1306_SET_COM_OUT_DIR | 0x08);
  
  writeCommand(SSD1306_SET_DISP_OFFSET);
  writeCommand(0x00);

  writeCommand(SSD1306_SET_COM_PIN_CFG);
  writeCommand(_width > 2*_height ? 0x02 : 0x12);

  writeCommand(SSD1306_SET_DISP_CLK_DIV);
  writeCommand(0x80);
  
  writeCommand(SSD1306_SET_PRECHARGE);
  writeCommand(_external_vcc ? 0x22 : 0xF1);
  
  writeCommand(SSD1306_SET_VCOM_DESEL);
  writeCommand(0x30);

  writeCommand(SSD1306_SET_CONTRAST);
  writeCommand(0xFF);

  writeCommand(SSD1306_SET_ENTIRE_ON);
  writeCommand(SSD1306_SET_NORM_INV);

  writeCommand(SSD1306_SET_CHARGE_PUMP);
  writeCommand(_external_vcc ? 0x10 : 0x14);

  writeCommand(SSD1306_SET_DISP | 0x01);
}

void SSD1306::writeCommand(uint8_t *data, uint8_t len)
{
    uBit.i2c.write(_addr, data, len);
}

void SSD1306::writeCommand(uint8_t data, int param)
{
    uint8_t packet[3];

    packet[0] = 0x80;
    packet[1] = data;
    packet[2] = param;

    writeCommand(packet, param == -1 ? 2 : 3);
}

void SSD1306::sendData(uint8_t *data, int length)
{
    uint8_t x0 = 0;
    uint8_t x1 = _width - 1;

    writeCommand(SSD1306_SET_COL_ADDR);
    writeCommand(x0);
    writeCommand(x1);
    writeCommand(SSD1306_SET_PAGE_ADDR);
    writeCommand(0);
    writeCommand((uint8_t) (_pages - 1));

    uBit.i2c.write(_addr, data, length);
}