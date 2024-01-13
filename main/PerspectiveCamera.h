#pragma once
#include "Camera.h"

class PerspectiveCamera : public Camera {

public:
  PerspectiveCamera(float fov) : Camera(fov) {}
  PerspectiveCamera() : Camera() {}

  Point2D Project(Point3D point) const override;
  
/*
  template <typename T, size_t size>
  Point<T, size> Project(Point point) const override;
  */
};
