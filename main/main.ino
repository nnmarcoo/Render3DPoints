#include <Arduino.h>
#include <U8g2lib.h> // Should this be in the project directory?

#include "ExampleObjects.h"
#include "PerspectiveCamera.h"
#include "OrthographicCamera.h"
#include "Renderer.h"

#define SCALE 20
 
U8G2_SSD1306_128X64_NONAME_F_HW_I2C display(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);

std::vector<Object*> objects = {&cube};

PerspectiveCamera camera;
Renderer renderer(display, camera, objects);

void setup(void) {
  display.begin();
  Serial.begin(2000000);
  
  renderer.SetScale(SCALE);
  renderer.SetOrigin(64, 32);
}
 
float r;
unsigned int frame = 0;
void loop(void) {
  r += 0.015;
  //renderer.SetRotation(r);
  cube.Translate(0, 2.5*cos(r*5) / SCALE);
  renderer.Render();
  //if (frame < 500)
    //display.writeBufferXBM(Serial);

  frame++;
}