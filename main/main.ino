#include <Arduino.h>
#include <U8g2lib.h> // Should this be in the project directory?

#include "PerspectiveCamera.h"
 
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
 
//U8G2_SSD1306_128X64_ALT0_F_HW_I2C display(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);                                     // SSD1306 and SSD1308Z are compatible
//U8G2_SSD1306_128X64_NONAME_F_SW_I2C display(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);  // Low spped I2C
U8G2_SSD1306_128X64_NONAME_F_HW_I2C display(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);    // Low spped I2C Hybrid

PerspectiveCamera camera();


 
void setup(void) {
  display.begin();
}
 
void loop(void) {
  display.clearBuffer();

  // Calculate points here

  display.sendBuffer();
}
