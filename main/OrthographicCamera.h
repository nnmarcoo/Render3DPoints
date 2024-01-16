#pragma once
#include "Camera.h"

class OrthographicCamera : public Camera {
public:
  PerspectiveCamera3D() : Camera() {}
  PerspectiveCamera3D(float fov) : Camera(fov) {}
  
  virtual Point Project(Point point) const override {
    return { point[0], point[1] };
  }
};
