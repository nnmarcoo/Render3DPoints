#include "Renderer.h"
#include <chrono>
#include <U8g2lib.h>

void Renderer::Render() {
  auto before = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration(0);

  display.clearBuffer();

  for (auto edge : edges) {
    
  }

  display.sendBuffer();

  auto after = std::chrono::high_resolution_clock::now();
  duration = after - before;
  deltatime = duration.count();
  before = after;
}