#include "PerspectiveCamera.h"

Point2D PerspectiveCamera::Project(Point3D point) {
  return Point2D { (GetFOV() * point.x) / (GetFOV() + point.z), 
                   (GetFOV() * point.y) / (GetFOV() + point.y)};
}

