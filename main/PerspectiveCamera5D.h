#pragma once
#include "PerspectiveCamera4D.h"

class PerspectiveCamera5D : public PerspectiveCamera4D {
public:
  PerspectiveCamera5D() : PerspectiveCamera4D() {}
  PerspectiveCamera5D(float fov) : PerspectiveCamera4D(fov) {}
  PerspectiveCamera5D(float fov, float distance) : PerspectiveCamera4D(fov, distance) {} 

  virtual Point Project(Point point) const override {
    float w = 1 / (GetDistance() - point[4]);
    return 
      PerspectiveCamera4D::Project( {
        point[0] * w,
        point[1] * w,
        point[2] * w,
        point[3] * w
      });
  }
};
