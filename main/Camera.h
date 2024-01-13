#pragma once
#include <stddef.h>

template <typename T, size_t size>
struct Point { 
  T cords[size];

  T& operator[](size_t index) {
        return cords[index];
  }
};

typedef struct { float x, y, z; } Point3D;
typedef struct { float x, y;    } Point2D;
typedef struct { int n1, n2;    } Edge;

class Camera {

public:
  Camera(float fov) : FOV(fov) {}
  Camera()          : FOV(60.0f) {}

  void  SetFOV(float nFOV)   { FOV = nFOV; }
  float GetFOV() const       { return FOV; }

  virtual Point2D Project(Point3D point) const { return {0,0}; }
/*
  template <typename T, size_t size>
  virtual Point<T, size> Project(Point point) { return Point<T, size>; }
  */

private:
  float FOV;
};
