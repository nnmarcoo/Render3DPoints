#include "PerspectiveCamera.h"


point2D PerspectiveCamera::Project(point3D point) {
  // TODO: Project point onto screen
  return point2D{point.x, point.y};
}

