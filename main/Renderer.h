#pragma once
#include <vector>
#include "Object.h"

#include <U8g2lib.h>

class Renderer {
public:
  Renderer(U8G2 &display, Camera &camera, std::vector<Object*> objects) 
          : display(display), camera(camera), objects(objects) {};

  void SetScale(float nscale)  { scale = nscale;  }
  void SetOrigin(int x, int y) { origin = {x,y};  }

  void Render() {
  display.clearBuffer();

  for (auto obj : objects) {
    std::vector<Point> points = obj->GetPoints();
    std::vector<Edge>  edges  = obj->GetEdges();

    for (auto edge : edges) {
      Point n1 = camera.Project(points[edge.p1]);
      Point n2 = camera.Project(points[edge.p2]);

      display.drawLine(scale * n1[0] + origin[0],
                      -scale * n1[1] + origin[1],
                       scale * n2[0] + origin[0],
                      -scale * n2[1] + origin[1]);
    }
  }
  display.sendBuffer();
}

private:
  U8G2 &display;
  Camera &camera;
  Point origin;

  // TODO: Add rotation ??
  float scale = 1.0f;
  float rotation = 0.0f;

  std::vector<Object*> objects;

};
