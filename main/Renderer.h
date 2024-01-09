#pragma once
#include <vector>
#include "Camera.h"


class Renderer {

public:
    Renderer(Camera camera, std::vector<point3D> points, std::vector<edge> edges) : camera(camera), points(points), edges(edges) {};

    void Render();

private:
    Camera camera;
    float DeltaTime = 0.0f; // What does this do

    std::vector<point3D> points;
    std::vector<edge> edges;

};