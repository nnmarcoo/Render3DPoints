#pragma once
#include "Camera.h"

class PerspectiveCamera3D : public Camera {
public:
  PerspectiveCamera3D() : Camera() {}
  PerspectiveCamera3D(float fov) : Camera(fov) {}

  virtual Point Project(Point point) const override {
    return { (GetFOV() * point[0]) / (GetFOV() + point[2]),
             (GetFOV() * point[1]) / (GetFOV() + point[2])};
  }
};
