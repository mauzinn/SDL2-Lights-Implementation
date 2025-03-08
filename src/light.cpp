#include <vector>
#include <iostream>
#include <SDL2\SDL.h>
#include "../include/entities/entity.hpp"
#include "../include/vectors/vector2.hpp"
#include "../include/entities/light.hpp"

void Light::setBright(int _bright) {
    Light::bright = _bright;
}

void Light::setPosition(Vector2::Vector2f _position) {
    Light::position = _position;
}

Vector2::Vector2f Light::getPosition() {
    return Light::position;
}

void Light::updateBrightofBlocks(std::vector<Entity*>& _entities) {
    for (int i = 0; i < _entities.size(); i++) {
        Vector2::Vector2f buffer_position_centered = _entities[i]->getPosition();
        buffer_position_centered.x += _entities[i]->getSize().x / 2;
        buffer_position_centered.y += _entities[i]->getSize().y / 2;

        float buffer_magnitude = Light::bright - Vector2::getMagnitude(Vector2::getDirection(Light::position, buffer_position_centered));
        _entities[i]->setBright(buffer_magnitude < 30 ? 30 : buffer_magnitude);
    }
}