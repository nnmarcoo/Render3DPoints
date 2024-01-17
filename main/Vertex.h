#include <initializer_list>
#include <memory>

struct Edge { int p1, p2; };

class Point {
public:
  Point() : cords(nullptr), size(0) {}

  Point(size_t size) : cords(new float[size]), size(size) {}

  Point(std::initializer_list<float> values) : size(values.size()) {
    cords = new float[size];
    std::copy(values.begin(), values.end(), cords);
  }

  Point(const Point& other) : size(other.size) {
    cords = new float[size];
    std::copy(other.cords, other.cords + size, cords);
  }

  ~Point() {
    delete[] cords;
  }

  float& operator[](size_t index) {
    return cords[index];
  }

  Point& operator=(const Point& other) {
    if (this != &other) {
      delete[] cords;

      size = other.size;
      cords = new float[size];
      std::copy(other.cords, other.cords + size, cords);
    }
    return *this;
  }

  void Translate(size_t dimension, float distance) {
    cords[dimension] += distance;
  }

  size_t GetSize() const { return size; }

private:
  float* cords;
  size_t size;
};
