#include "Renderer.h"
#include <chrono>
#include <U8g2lib.h>

void Renderer::Render() {
  display.clearBuffer();

  for (auto obj : objects) {
    std::vector<Point> points = obj->GetPoints();
    std::vector<Edge>  edges  = obj->GetEdges();

    for (auto edge : edges) {
      Point n1 = camera.Project(RotateX(RotateZ(RotateY(points[edge.p1]))));
      Point n2 = camera.Project(RotateX(RotateZ(RotateY(points[edge.p2]))));

      display.drawLine(scale * n1[0] + origin[0],
                      -scale * n1[1] + origin[1],
                       scale * n2[0] + origin[0],
                      -scale * n2[1] + origin[1]);
    }
  }
  display.sendBuffer();
}

Point Renderer::RotateX(Point point) {
  Point output(3);
  output[0] = point[0];
  output[1] = cos(rotation) * point[1] - sin(rotation) * point[2];
  output[2] = sin(rotation) * point[1] + cos(rotation) * point[2];
  return output;
}

Point Renderer::RotateY(Point point) {
  Point output(3);
  output[0] = cos(rotation) * point[0] + sin(rotation) * point[2];
  output[1] = point[1];
  output[2] = -sin(rotation) * point[0] + cos(rotation) * point[2];
  return output;
}

Point Renderer::RotateZ(Point point) {
  Point output(3);
  output[0] = cos(rotation) * point[0] - sin(rotation) * point[1];
  output[1] = sin(rotation) * point[0] + cos(rotation) * point[1];
  output[2] = point[2];
  return output;
}
