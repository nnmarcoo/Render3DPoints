#pragma once
#include "PerspectiveCamera3D.h"

// TODO: Implement

class PerspectiveCameraND : public PerspectiveCamera3D {
public:
  PerspectiveCameraND() : PerspectiveCamera3D(), distance(2.0f), dimensions(1) {}
  PerspectiveCameraND(float fov) : PerspectiveCamera3D(fov), distance(2.0f) {}
  PerspectiveCameraND(float fov, float distance) : PerspectiveCamera3D(fov), distance(distance) {}

  void  SetDistance(float ndistance) { distance = ndistance; };
  float GetDistance() const { return distance; }

  virtual Point Project(Point point) const override {
    Point pos = {0,0,0};
    float w = 1 / (distance - point[3]);
    return 
      PerspectiveCamera3D::Project( {
        point[0] * w,
        point[1] * w,
        point[2] * w
      });
  }

private:
  float distance;
  size_t dimensions;
};
