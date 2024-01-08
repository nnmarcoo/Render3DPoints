#pragma once

typedef struct {
    float x, y, z;
} 3DPoint;

typedef struct {
    float x, y;
} 2DPoint;

typedef struct {
    int n1, n2;
} edge;

class PerspectiveCamera {

public:
    PerspectiveCamera(float fov);
    PerspectiveCamera();

    inline float GetFOV() { return FOV; }



private:
    float FOV;
    float roll;

};