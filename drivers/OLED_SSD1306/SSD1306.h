#include "MicroBit.h"

#ifndef SSD_1306_H
#define SSD_1306_H


// register definitions

#define SSD1306_SET_CONTRAST            0x81
#define SSD1306_SET_ENTIRE_ON           0xA4
#define SSD1306_SET_NORM_INV            0xA6
#define SSD1306_SET_DISP                0xAE
#define SSD1306_SET_MEM_ADDR            0x20
#define SSD1306_SET_COL_ADDR            0x21
#define SSD1306_SET_PAGE_ADDR           0x22
#define SSD1306_SET_DISP_START_LINE     0x40
#define SSD1306_SET_SEG_REMAP           0xA0
#define SSD1306_SET_MUX_RATIO           0xA8
#define SSD1306_SET_COM_OUT_DIR         0xC0
#define SSD1306_SET_DISP_OFFSET         0xD3
#define SSD1306_SET_COM_PIN_CFG         0xDA
#define SSD1306_SET_DISP_CLK_DIV        0xD5
#define SSD1306_SET_PRECHARGE           0xD9
#define SSD1306_SET_VCOM_DESEL          0xDB
#define SSD1306_SET_CHARGE_PUMP         0x8D


extern MicroBit uBit;

// Driver for SSD_1306 series of OLED drivers.

class SSD1306 {
public:
  SSD1306(uint16_t width, uint16_t height, uint8_t address = 0x78);
  void sendData(uint8_t *data, int length);

  int _width;
  int _height;

  uint8_t _external_vcc;
  uint8_t _pages;
  uint8_t _addr;

void writeCommand(uint8_t *data, uint8_t len);
void writeCommand(uint8_t data, int param = -1);

};

#endif
