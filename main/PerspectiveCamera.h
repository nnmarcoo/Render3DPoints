#pragma once
#include "Camera.h"

class PerspectiveCamera : public Camera {
    
public:
    PerspectiveCamera(float fov, float roll) : Camera(fov, roll) {}
    PerspectiveCamera(float fov) : Camera(fov) {}
    PerspectiveCamera() : Camera() {}

    virtual point2D Project(point3D point);
    
    // TODO: Add calculate point pos
};
