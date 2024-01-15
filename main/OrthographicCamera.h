#pragma once
#include "Camera.h"

class OrthographicCamera : public Camera {
public:
  virtual Point Project(Point point) const override {
    return { point[0], point[1] };
  }
};
