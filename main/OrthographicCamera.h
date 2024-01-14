#pragma once
#include "Camera.h"

class OrthographicCamera : public Camera {
public:
  Point Project(Point point) const override {
    return { point[0], point[1] };
  }
};
