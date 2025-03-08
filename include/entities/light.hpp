#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <vector>
#include "./entity.hpp"
#include "../vectors/vector2.hpp"

class Light {
    private:
    Vector2::Vector2f position;
    int bright;

    public:
    void setBright(int _light_bright);
    void setPosition(Vector2::Vector2f _position);

    Vector2::Vector2f getPosition();

    void updateBrightofBlocks(std::vector<Entity*>& _entities);
};

#endif