#pragma once

typedef struct {
  float x, y, z;
} Point3D;

typedef struct {
  float x, y;
} Point2D;

typedef struct {
  int n1, n2;
} Edge;

class Camera {
    
public:
  Camera(float fov, float roll) : FOV(fov), roll(roll) {}
  Camera(float fov) : FOV(fov), roll(0.0f) {}
  Camera() : FOV(60), roll(0.0f) {}

  void  SetFOV(float nFOV)   { FOV = nFOV;   }
  void  SetRoll(float nroll) { roll = nroll; }
  float GetFOV() const       { return FOV;   }
  float GetRoll() const      { return roll;  }

  virtual Point2D Project(Point3D point) { return Point2D{point.x, point.y}; }

private:
  float FOV, roll;
};