#include "PerspectiveCamera.h"

Point2D PerspectiveCamera::Project(Point3D point) const {
  return Point2D { (GetFOV() * point.x) / (GetFOV() + point.z),
                   (GetFOV() * point.y) / (GetFOV() + point.z)};
}
/*
template <typename T, size_t size>
Point<T, size> PerspectiveCamera::Project(Point<T, size> point) const {
  return Point<T, 2> {(GetFOV() * point.x) / (GetFOV() + point.z),
                      (GetFOV() * point.y) / (GetFOV() + point.z)};
}
*/

