#include <Arduino.h>
#include <U8g2lib.h>
 
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
 
//U8G2_SSD1306_128X64_ALT0_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);                                     // SSD1306 and SSD1308Z are compatible
//U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);  // Low spped I2C
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);    // Low spped I2C Hybrid

 
void setup(void) {
  u8g2.begin();
  Serial.begin(115200); // Set Serial baud rate to 115200
}
 
void loop(void) {
  static int posX = 0;
  static int add = 1;
  u8g2.clearBuffer();

  u8g2.drawBox(posX, 24, 16, 16);

  posX+=add;
  if (posX > 128-16)
    add = -1;
  if (posX < 0)
    add = 1;

  u8g2.sendBuffer();
}
