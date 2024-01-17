#pragma once
#include "PerspectiveCamera4D.h"

class PerspectiveCamera5D : public PerspectiveCamera4D {
public:
  PerspectiveCamera5D() : PerspectiveCamera4D() {}
  PerspectiveCamera5D(float fov) : PerspectiveCamera4D(fov), distance(4.0f) {}
  PerspectiveCamera5D(float fov, float distance) : PerspectiveCamera4D(fov, distance) {}
  PerspectiveCamera5D(float fov, float distance, float distance2) : PerspectiveCamera4D(fov, distance), distance(distance2) {}

  void  SetDistance2(float ndistance) { distance = ndistance; };
  float GetDistance2() const { return distance; }

  virtual Point Project(Point point) const override {
    float w = 1 / (GetDistance() + GetDistance2() - point[4]);
    return 
      PerspectiveCamera4D::Project( {
        point[0] * w,
        point[1] * w,
        point[2] * w,
        point[3] * w
      });
  }

private:
  float distance;
};
