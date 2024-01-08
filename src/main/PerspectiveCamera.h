#pragma once
#include "Camera.h"

class PerspectiveCamera : public Camera {
    
public:
    PerspectiveCamera(float fov, float roll) : Camera(fov, roll) {}
    PerspectiveCamera(float fov) : Camera(fov) {}
    PerspectiveCamera() : Camera() {}
    
    // TODO: Add calculate point pos
};
