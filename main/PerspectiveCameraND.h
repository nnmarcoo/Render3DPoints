#pragma once
#include "PerspectiveCamera3D.h"

class PerspectiveCameraND : public PerspectiveCamera3D {
public:
  PerspectiveCameraND() : PerspectiveCamera3D(), distance(2.0f) {}
  PerspectiveCameraND(float fov) : PerspectiveCamera3D(fov), distance(2.0f) {}
  PerspectiveCameraND(float fov, float distance) : PerspectiveCamera3D(fov), distance(distance) {}

  void  SetDistance(float ndistance) { distance = ndistance; };
  float GetDistance() const { return distance; }

  virtual Point Project(Point point) const override {
    for (int i = point.GetSize(); i > 3; i--) {
      float w = 1 / (distance - point[i-1]);
      for (int j = 0; j < i-1; j++) {
        point[j] *= w;
      }
    }
    return PerspectiveCamera3D::Project(point);
  }

private:
  float distance;
};
