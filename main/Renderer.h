#pragma once
#include <vector>
#include "Camera.h"
class U8G2;

class Renderer {

public:
  Renderer(U8G2 &display, Camera &camera, std::vector<Point3D> points, std::vector<Edge> edges) : display(display), camera(camera), points(points), edges(edges) {};

  void Render();

  void SetScale(float nscale)     { scale = nscale;   }
  void SetOrigin(Point2D norigin) { origin = norigin; }
  void SetRotation(float nrot)    { rotation = nrot;  }

private:
  U8G2 &display;
  Camera &camera;
  Point2D origin;

  // TODO: These attributes should probably exist for individual objects, not the entire renderer
  float scale = 1.0f;
  float rotation = 0.0f;

  std::vector<Point3D> points;
  std::vector<Edge> edges;

  // NOTE: These exist mostly for demo
  Point3D RotateX(Point3D point);
  Point3D RotateY(Point3D point);
  Point3D RotateZ(Point3D point);
};
