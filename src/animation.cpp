#include "../include/vectors/vector2.hpp"
#include "../include/controllers/animation.hpp"

Animation::Animation() {
    Animation::current_frame = 0;
    Animation::current_column = 0;
    Animation::frametime_update.setFramerate(12);
}

void Animation::update() {
    if (Animation::frametime_update.getElapsedUpdate()) {
        Animation::current_frame = (Animation::current_frame + 1) % Animation::frames;
    }
}

void Animation::setData(int _frames, int _columns, int _current_column, int _current_frame) {
    Animation::frames = _frames;
    Animation::columns = _columns;
    Animation::current_column = _current_column;
    Animation::current_frame = _current_frame;
}

Vector2::Vector2f Animation::getPosition() {
    Vector2::Vector2f buffer_size = Animation::getSize();
    return Vector2::Vector2f(buffer_size.x * Animation::current_frame, buffer_size.y * Animation::current_column);
}

Vector2::Vector2f Animation::getSize() {
    return Vector2::Vector2f(1.0f / Animation::frames, 1.0f / Animation::columns);
}