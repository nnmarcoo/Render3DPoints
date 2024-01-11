#pragma once
#include <vector>
#include "Camera.h"
class U8G2;

class Renderer {

public:
  Renderer(U8G2 &display, Camera camera, std::vector<Point3D> points, std::vector<Edge> edges) : display(display), camera(camera), points(points), edges(edges) {};

  void Render();

  void SetScale(float nscale)    { scale = nscale;  }
  void SetPosition(Point2D npos) { position = npos; }
  void SetRotation(float nrot)   { rotation = nrot; }

  // TODO: Set rotation

private:
  U8G2 &display;
  Camera camera;

  // TODO: These attributes should probably exist for individual objects, not the entire renderer
  Point2D position;
  float scale = 1.0f;
  float rotation = 0.0f;

  std::vector<Point3D> points;
  std::vector<Edge> edges;

  Point3D RotateX(Point3D point);
  Point3D RotateY(Point3D point);
  Point3D RotateZ(Point3D point);

};