#ifndef FRAMETIME_HPP
#define FRAMETIME_HPP

#include <chrono>

class Frametime {
    private:
    std::chrono::high_resolution_clock::time_point last_time;
    int millisecond_frame;

    public:
    Frametime();

    void setFramerate(int _framerate);

    bool getElapsedUpdate();
};

#endif