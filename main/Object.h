#pragma once
#include <vector>
#include <cmath>
#include "Camera.h"

// TODO: Support constructor that takes list of Objects

class Object {
public:
  Object(size_t dimensions, std::vector<Point> points, std::vector<Edge> edges)
        : position(dimensions), rotation(dimensions),  points(points), edges(edges) {}

  void SetPoints(const std::vector<Point> npoints) { points = npoints; }
  void SetEdges(const std::vector<Edge> nedges)    { edges = nedges;   }

  const std::vector<Point>& GetPoints() const { return points; }
  const std::vector<Edge>&  GetEdges()  const { return edges;  }

  void Translate(size_t dimension, float distance) {
    position.Translate(dimension, distance);
    for (Point &point : points)
      point.Translate(dimension, distance);
  }

  void Setorigin(Point norigin) {
    origin = norigin;
  }

  void Rotate(size_t d1, size_t d2, float angle) {
    rotation[d1] += angle;
    rotation[d2] += angle;
    
    for (Point &point : points) {
      for (size_t d = 0; d < point.GetSize(); d++)
        point.Translate(d, -position[d] - origin[d]);
    
      float oldpoint = point[d1];
      point[d1] = cos(angle) * point[d1] - sin(angle) * point[d2];
      point[d2] = sin(angle) * oldpoint  + cos(angle) * point[d2];

      for (size_t d = 0; d < point.GetSize(); d++)
          point.Translate(d, position[d] + origin[d]);
    }
  }

private:
  Point position;
  Point rotation;
  Point origin;

  std::vector<Point> points;
  std::vector<Edge> edges;
};