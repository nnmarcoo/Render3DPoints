#pragma once

class PerspectiveCamera {

public:
    PerspectiveCamera(float fov);
    PerspectiveCamera();

    inline float GetFOV() { return FOV; }


private:
    float FOV;


};