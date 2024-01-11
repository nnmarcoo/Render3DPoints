#pragma once
#include "Camera.h"

class PerspectiveCamera : public Camera {
    
public:
  PerspectiveCamera(float fov) : Camera(fov) {}
  PerspectiveCamera() : Camera() {}

  Point2D Project(Point3D point) override;
};
