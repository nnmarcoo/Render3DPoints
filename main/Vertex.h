struct Edge  { int p1, p2; };

class Point { // TODO: Add throw for out of bounds
public:
  Point() : cords(nullptr), size(0) {}

  Point(size_t size) : cords(std::make_unique<float[]>(size)), size(size) {}

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

  void Translate(size_t dimension, float distance) {
    cords[dimension] += distance;
  }

private:
  std::unique_ptr<float[]> cords;
  size_t size;
};