#include <Arduino.h>
#include <U8g2lib.h> // Should this be in the project directory?

#include "PerspectiveCamera.h"
#include "Renderer.h"
 
//U8G2_SSD1306_128X64_ALT0_F_HW_I2C display(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);                                     // SSD1306 and SSD1308Z are compatible
//U8G2_SSD1306_128X64_NONAME_F_SW_I2C display(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);  // Low spped I2C
U8G2_SSD1306_128X64_NONAME_F_HW_I2C display(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);    // Low spped I2C Hybrid

//cube
std::vector<Point3D> points { Point3D {-1.0f, -1.0f, -1.0f}, Point3D {-1.0f, -1.0f,  1.0f},
                              Point3D { 1.0f, -1.0f, -1.0f}, Point3D {-1.0f,  1.0f, -1.0f}, 
                              Point3D {-1.0f,  1.0f,  1.0f}, Point3D { 1.0f, -1.0f,  1.0f},
                              Point3D { 1.0f,  1.0f, -1.0f}, Point3D { 1.0f,  1.0f,  1.0f}};

std::vector<Edge> edges     { Edge {0, 1}, Edge {0, 2}, Edge {0, 3}, 
                              Edge {2, 5}, Edge {3, 6}, Edge {3, 4}, 
                              Edge {4, 7}, Edge {6, 7}, Edge {7, 5}, 
                              Edge {5, 1}, Edge {4, 1}, Edge {2, 6}};

PerspectiveCamera camera;
Renderer renderer(display, camera, points, edges);

void setup(void) {
  display.begin();

  renderer.SetScale(20);
  renderer.SetOrigin(Point2D {64, 32});
}
 
float r;
void loop(void) {
  renderer.SetRotation(r+=.03);
  renderer.Render();
}
