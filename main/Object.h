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

  void Translate(size_t dimension, float distance) {
    position.Translate(dimension, distance);
    for (Point &point : points)
      point.Translate(dimension, distance);
  }

  // TODO: Implement universal rotation somehow

private:
  Point position;
  Point rotation;

  std::vector<Point> points;
  std::vector<Edge> edges;
};