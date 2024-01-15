#pragma once
#include <vector>
#include "Camera.h"

class Object {
public:
  Object(size_t dimensions, std::vector<Point> points, std::vector<Edge> edges)
        : position(dimensions), rotation(dimensions),  points(points), edges(edges) {}

  void SetPoints(const std::vector<Point>& npoints) { points = npoints; }
  void SetEdges(const std::vector<Edge>& nedges)    { edges = nedges;   }

  const std::vector<Point>& GetPoints() const { return points; }
  const std::vector<Edge>& GetEdges() const   { return edges;  }

  // TODO: This doesn't move the origin of the object
  void Translate(size_t dimension, float distance) {
    for (Point &point : points)
      point.Translate(dimension, distance);
  }

private:
  Point position;
  Point rotation;

  std::vector<Point> points;
  std::vector<Edge> edges;
};