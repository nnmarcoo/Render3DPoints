#pragma once
#include "Camera.h"

class PerspectiveCamera : public Camera {
public:
  Point Project(Point point) const override {
    return { (GetFOV() * point[0]) / (GetFOV() + point[2]),
             (GetFOV() * point[1]) / (GetFOV() + point[2])};
  }
};
