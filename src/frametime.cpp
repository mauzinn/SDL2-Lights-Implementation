#include <chrono>
#include "../include/controllers/frametime.hpp"

Frametime::Frametime() {
    Frametime::millisecond_frame = 1000 / 60;
    Frametime::last_time = std::chrono::high_resolution_clock::now();
}

void Frametime::setFramerate(int _frames) {
    Frametime::millisecond_frame = 1000 / _frames;
}

bool Frametime::getElapsedUpdate() {
    std::chrono::high_resolution_clock::time_point current_time = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - Frametime::last_time);

    if (elapsed_time.count() < Frametime::millisecond_frame) return false;
    Frametime::last_time = current_time;
    return true;
}