#pragma once
#include <vector>
#include <initializer_list>
#include "Camera.h"

class Object {
public:
  Object(std::vector<Point>& inputPoints, std::vector<Edge>& inputEdges)
        : points(inputPoints), edges(inputEdges) {}

private:
  std::vector<Point> points;
  std::vector<Edge> edges;
};