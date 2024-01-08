@pragma once

typedef struct {
    float x, y, z;
} point3D;

typedef struct {
    float x, y;
} point2D;

typedef struct {
    int n1, n2;
} edge;

class Camera {
    
    public:
        Camera(float fov, float roll) : FOV(fov), roll(roll) {}
        Camera(float fov) : FOV(fov), roll(0.0f) {}
        Camera() : FOV(60), roll(0.0f) {}

        void  setFOV(float newFOV) { FOV = newFOV; }
        float getFOV() const { return FOV; }
        void  setRoll(float newRoll) { roll = newRoll; }
        float getRoll() const { return roll; }

        virtual point2D Project(point3D point) = 0;

    private:
        float FOV, roll;
};