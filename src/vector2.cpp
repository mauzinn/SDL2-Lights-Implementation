#include <cmath>
#include "../include/vectors/vector2.hpp"

Vector2::Vector2f Vector2::getDirection(Vector2::Vector2f _vector1, Vector2::Vector2f _vector2) {
    return Vector2::Vector2f(_vector2.x - _vector1.x, _vector2.y - _vector1.y);
}

float Vector2::getMagnitude(Vector2::Vector2f _vector) {
    return float(sqrt(pow(_vector.x, 2.0f) + pow(_vector.y, 2.0f)));
}

Vector2::Vector2f Vector2::getNormalized(Vector2::Vector2f _vector) {
    float buffer_magnitude = Vector2::getMagnitude(_vector);
    return Vector2::Vector2f(_vector.x / buffer_magnitude, _vector.y / buffer_magnitude);
}

bool Vector2::verifyCollision(Vector2f _min1, Vector2f _max1, Vector2f _min2, Vector2f _max2) {
    return (
        _min1.x < _max2.x && _max1.x > _min2.x &&
        _min1.y < _max2.y && _max1.y > _min2.y
    );
}