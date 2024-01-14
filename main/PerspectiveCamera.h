#pragma once
#include "Camera.h"

class PerspectiveCamera : public Camera {
public:
  PerspectiveCamera() : Camera() {}
  PerspectiveCamera(float fov) : Camera(fov) {}

  Point Project(Point point) const override {
    return { (GetFOV() * point[0]) / (GetFOV() + point[2]),
             (GetFOV() * point[1]) / (GetFOV() + point[2])};
  }
};
