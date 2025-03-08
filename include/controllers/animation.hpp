#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "../vectors/vector2.hpp"
#include "./frametime.hpp"

class Animation {
    private:
    Frametime frametime_update;
    int frames, columns,
    current_frame, current_column;
    
    public:
    Animation();
    void update();

    void setData(int _frames, int _columns, int _current_column, int _current_frame);

    Vector2::Vector2f getPosition();
    Vector2::Vector2f getSize();
};

#endif