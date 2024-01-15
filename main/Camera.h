#pragma once
#include <initializer_list>
#include <memory>
#include "Point.h"

class Camera {
public:
  Camera(float fov) : FOV(fov) {}
  Camera()          : FOV(15.0f) {}

  void  SetFOV(float nFOV)   { FOV = nFOV; }
  float GetFOV() const       { return FOV; }

  virtual Point Project(Point point) const { return {0}; }

private:
  float FOV;
};