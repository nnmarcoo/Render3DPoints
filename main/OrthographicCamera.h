#pragma once
#include "Camera.h"

class OrthographicCamera : public Camera {
public:

  OrthographicCamera() : Camera() {}
  OrthographicCamera(float fov) : Camera(fov) {}

  Point Project(Point point) const override {
    return { point[0], point[1] };
  }
};
