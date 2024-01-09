#include "PerspectiveCamera.h"


Point2D PerspectiveCamera::Project(Point3D point) {
  // TODO: Project point onto screen
  return Point2D{point.x, point.y};
}

