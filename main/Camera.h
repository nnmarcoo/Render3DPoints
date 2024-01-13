#pragma once
#include <initializer_list>
#include <memory>

struct Edge  { int p1, p2; };

struct Point { // Add throw for out of bounds
  
  std::unique_ptr<float[]> cords;
  size_t size;

  Point() : cords(nullptr), size(0) {}

  Point(int size) : cords(std::make_unique<float[]>(size)), size(size) {}

  Point(std::initializer_list<float> values) : size(values.size()) {
    cords = std::make_unique<float[]>(size);
    std::copy(values.begin(), values.end(), cords.get());
  }

  Point(const Point& other) : size(other.size) {
    cords = std::make_unique<float[]>(size);
    std::copy(other.cords.get(), other.cords.get() + size, cords.get());
  }

  float& operator[](size_t index) {
    return cords[index];
  }

  Point& operator=(const Point& other) {
    if (this != &other) {
      if (size != other.size) {
        cords = std::make_unique<float[]>(other.size);
        size = other.size;
      }
      std::copy(other.cords.get(), other.cords.get() + size, cords.get());
    }
    return *this;
  }
};

class Camera {

public:
  Camera(float fov) : FOV(fov) {}
  Camera()          : FOV(60.0f) {}

  void  SetFOV(float nFOV)   { FOV = nFOV; }
  float GetFOV() const       { return FOV; }

  virtual Point Project(Point point) const { return {0}; }

private:
  float FOV;
};