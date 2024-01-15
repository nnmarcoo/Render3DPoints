#pragma once
#include <vector>
#include "Object.h"

class U8G2;

class Renderer {
public:
  Renderer(U8G2 &display, Camera &camera, std::vector<Object*> objects) 
          : display(display), camera(camera), objects(objects) {};

  void Render();

  void SetScale(float nscale)  { scale = nscale;  }
  void SetOrigin(int x, int y) { origin = {x,y};  }
  void SetRotation(float nrot) { rotation = nrot; }

private:
  U8G2 &display;
  Camera &camera;
  Point origin;

  // TODO: These attributes should probably exist for individual objects, not the entire renderer
  float scale = 1.0f;
  float rotation = 0.0f;

  std::vector<Object*> objects;

  Point RotateX(Point point);
  Point RotateY(Point point);
  Point RotateZ(Point point);
};
