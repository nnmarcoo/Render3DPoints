#include "Renderer.h"
#include <chrono>
#include <U8g2lib.h>

void Renderer::Render() {
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
