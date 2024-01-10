#pragma once

typedef struct { float x, y, z; } Point3D;
typedef struct { float x, y;    } Point2D;
typedef struct { int n1, n2;    } Edge;

class Camera {
    
public:
  Camera(float fov) : FOV(fov) {}
  Camera()          : FOV(60.0f) {}

  void  SetFOV(float nFOV)   { FOV = nFOV;   }
  float GetFOV() const       { return FOV;   }

  virtual Point2D Project(Point3D point) { return Point2D {point.x, point.y}; }

private:
  float FOV;
};