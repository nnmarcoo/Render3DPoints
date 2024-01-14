#include <Arduino.h>
#include <U8g2lib.h> // Should this be in the project directory?

#include "ExampleObjects.h"
#include "PerspectiveCamera.h"
#include "OrthographicCamera.h"
#include "Renderer.h"
 
//U8G2_SSD1306_128X64_ALT0_F_HW_I2C display(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);                                     // SSD1306 and SSD1308Z are compatible
//U8G2_SSD1306_128X64_NONAME_F_SW_I2C display(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);  // Low spped I2C
U8G2_SSD1306_128X64_NONAME_F_HW_I2C display(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);    // Low spped I2C Hybrid

std::vector<Object*> objects = {&cube};

PerspectiveCamera camera(6.0f);
Renderer renderer(display, camera, objects);

void setup(void) {
  display.begin();

  renderer.SetScale(20);
  renderer.SetOrigin(64, 32);
}
 
float r;
void loop(void) {
  renderer.SetRotation(r+=.015);
  renderer.Render();
}