#pragma once
#include "PerspectiveCamera3D.h"

// TODO: Implement

class PerspectiveCameraND : public PerspectiveCamera3D {
public:
  PerspectiveCameraND() : PerspectiveCamera3D(), distance(2.0f), dimensions(3) {}
  PerspectiveCameraND(float fov) : PerspectiveCamera3D(fov), distance(2.0f), dimensions(3) {}
  PerspectiveCameraND(float fov, float distance) : PerspectiveCamera3D(fov), distance(distance) {}
  PerspectiveCameraND(float fov, float distance, size_t d) : PerspectiveCamera3D(fov), distance(distance) { if (d < 4) dimensions = 3; else dimensions = d;}

  void  SetDistance(float ndistance) { distance = ndistance; };
  float GetDistance() const { return distance; }

  virtual Point Project(Point point) const override {
    Point pos = point.GetSize();
    
    while (point.GetSize() > 3) {
      float w = 1 / (distance - point[point.GetSize()-1]);
      for (int i = 0; i < point.GetSize()) {
        point[i] * w;
      }
    }
    return PerspectiveCamera3D::Project(point);
  }

private:
  float distance;
  size_t dimensions;
};
