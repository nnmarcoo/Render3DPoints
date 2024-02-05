#include <Arduino.h>
#include <U8g2lib.h>

#include "ExampleObjects.h"
#include "OrthographicCamera.h"
#include "PerspectiveCameraND.h"
#include "Renderer.h"

#define SCALE 20
 
U8G2_SSD1306_128X64_NONAME_F_HW_I2C display(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);

std::vector<Object*> objects = {&tesseract};

PerspectiveCameraND camera;
Renderer renderer(display, camera, objects);

void setup(void) {
  display.begin();
 // Serial.begin(2000000);
  
  renderer.SetScale(SCALE);
  renderer.SetOrigin(64, 32);
}
 
unsigned int frame = 0;
void loop(void) {
  //tesseract.Rotate(0, 2, 0.015f);
  renderer.Render();

 // if (frame < 600)
   // display.writeBufferXBM(Serial);

  frame++;
}