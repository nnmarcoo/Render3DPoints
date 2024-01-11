#include <Arduino.h>
#include <U8g2lib.h> // Should this be in the project directory?
#include <vector>

#include "PerspectiveCamera.h"
#include "Renderer.h"
 
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
 
//U8G2_SSD1306_128X64_ALT0_F_HW_I2C display(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);                                     // SSD1306 and SSD1308Z are compatible
//U8G2_SSD1306_128X64_NONAME_F_SW_I2C display(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);  // Low spped I2C
U8G2_SSD1306_128X64_NONAME_F_HW_I2C display(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);    // Low spped I2C Hybrid


std::vector<Point3D> points { Point3D {-1.0f, -1.0f, -1.0f}, Point3D {-1.0f, -1.0f,  1.0f},
                              Point3D { 1.0f, -1.0f, -1.0f}, Point3D {-1.0f,  1.0f, -1.0f}, 
                              Point3D {-1.0f,  1.0f,  1.0f}, Point3D { 1.0f, -1.0f,  1.0f},
                              Point3D { 1.0f,  1.0f, -1.0f}, Point3D { 1.0f,  1.0f,  1.0f}};

std::vector<Edge> edges     { Edge {0, 1}, Edge {0, 2}, Edge {0, 3}, 
                              Edge {2, 5}, Edge {3, 6}, Edge {3, 4}, 
                              Edge {4, 7}, Edge {6, 7}, Edge {7, 5}, 
                              Edge {5, 1}, Edge {4, 1}, Edge {2, 6}};
                              
/*
std::vector<Point3D> points { Point3D {-1.0f, -1.0f, -1.0f}, Point3D {-1.0f, -1.0f, 1.0f},
                              Point3D { 1.0f, -1.0f, -1.0f}, Point3D { 1.0f, -1.0f, 1.0f},
                              Point3D {0.0f, 1.0f, 0.0f}};

std::vector<Edge> edges     { Edge {0, 1}, Edge {0, 2}, Edge {1, 3}, 
                              Edge {2, 3}, Edge {0, 4}, Edge {1, 4}, 
                              Edge {2, 4}, Edge {3, 4}};
                              */

PerspectiveCamera camera(60.0f);
Renderer renderer(display, camera, points, edges);

void setup(void) {
  display.begin();

  renderer.SetScale(25);
  renderer.SetPosition(Point2D {64, 32});
  renderer.SetRotation(5.0f);
}
 
float r;
void loop(void) {
  r+=.08;
  renderer.SetRotation(r);
  renderer.Render();
}
