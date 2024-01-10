#pragma once
#include <vector>
#include "Camera.h"
class U8G2;

class Renderer {

public:
  Renderer(U8G2 &display, Camera camera, std::vector<Point3D> points, std::vector<Edge> edges) : display(display), camera(camera), points(points), edges(edges) {};

  void Render();

private:
  U8G2 &display;
  Camera camera;
  float deltatime = 0.0f; // What does this do

  std::vector<Point3D> points;
  std::vector<Edge> edges;

};