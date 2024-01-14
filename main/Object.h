#pragma once
#include <vector>
#include <initializer_list>
#include "Camera.h"

class Object {
public:
  Object(std::vector<Point> points, std::vector<Edge> edges)
        : points(points), edges(edges) {}

  Object(std::initializer_list<Point> points, std::initializer_list<Edge> edges)
        : points(points), edges(edges) {}

  void SetPoints(const std::vector<Point>& npoints) { points = npoints; }
  void SetEdges(const std::vector<Edge>& nedges)    { edges = nedges;   }

  const std::vector<Point>& GetPoints() const { return points; }
  const std::vector<Edge>& GetEdges() const   { return edges;  }

private:
  std::vector<Point> points;
  std::vector<Edge> edges;
};