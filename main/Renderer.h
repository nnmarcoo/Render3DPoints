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

private:
  U8G2 &display;
  Camera &camera;
  Point origin;

  // TODO: Add rotation ??
  float scale = 1.0f;
  float rotation = 0.0f;

  std::vector<Object*> objects;

};
