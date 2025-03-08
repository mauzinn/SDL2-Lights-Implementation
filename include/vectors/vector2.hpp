#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include "./vector2f.hpp"
#include "./vector2i.hpp"

namespace Vector2 {
    using ::Vector2f;
    using ::Vector2i;
    Vector2f getDirection(Vector2f _vector1, Vector2f _vector2);
    Vector2f getNormalized(Vector2f _vector);
    float getMagnitude(Vector2f _vector);
    bool verifyCollision(Vector2f _min1, Vector2f _max1, Vector2f _min2, Vector2f _max2);
};

#endif