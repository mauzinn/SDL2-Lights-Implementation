#include <SDL2\SDL.h>
#include <iostream>
#include "../include/controllers/animation.hpp"
#include "../include/vectors/vector2.hpp"
#include "../include/entities/entity.hpp"

Entity::Entity() {
    Entity::id = 0;
    Entity::bright = 30;
    Entity::animated = false;
    Entity::show = false;
};

void Entity::update() {
    if (Entity::animated) {
        Entity::animation.update();
    }
}

void Entity::draw(SDL_Renderer* _renderer, SDL_Texture* _texture) {
    int buffer_coordinates[6][2] = {
        {0, 0},
        {1, 0},
        {1, 1},
        {1, 1},
        {0, 1},
        {0, 0}
    };
    if (Entity::show) {
        SDL_Vertex buffer_vertexes[6];

        for (int i = 0; i < 6; i++) {
            Vector2::Vector2f buffer_position = Entity::position;
            Vector2::Vector2f buffer_texture_position = Entity::animation.getPosition();
            if (buffer_coordinates[i][0]) {
                buffer_position.x += Entity::size.x;
                buffer_texture_position.x += Entity::animation.getSize().x;
            } 
            
            if (buffer_coordinates[i][1]) {
                buffer_position.y += Entity::size.y;
                buffer_texture_position.y += Entity::animation.getSize().y;
            }

            buffer_vertexes[i].color = {Entity::bright, Entity::bright, Entity::bright, 255};
            buffer_vertexes[i].position = {buffer_position.x, buffer_position.y};
            buffer_vertexes[i].tex_coord = {buffer_texture_position.x, buffer_texture_position.y};
        }

        SDL_RenderGeometry(_renderer, _texture, buffer_vertexes, 6, nullptr, 0);
    }
}

void Entity::setId(int _id) {
    Entity::id = _id;
}

void Entity::setAnimation(int _texture_id, int _frames, int _columns, int _current_column, int _current_frame) {
    Entity::texture_id = _texture_id;
    Entity::animation.setData(_frames, _columns, _current_column, _current_frame);
}

void Entity::setAnimated(bool _animated) {
    Entity::animated = _animated;
}

void Entity::setShow(bool _show) {
    Entity::show = _show;
}

void Entity::setPosition(Vector2::Vector2f _position) {
    Entity::position = _position;
}

void Entity::setSize(Vector2::Vector2f _size) {
    Entity::size = _size;
}

void Entity::setBright(int _bright) {
    Entity::bright = _bright;
}

Vector2::Vector2f Entity::getPosition() {
    return Entity::position;
}

Vector2::Vector2f Entity::getSize() {
    return Entity::size;
}

unsigned char Entity::getBright() {
    return Entity::bright;
}

int Entity::getTextureId() {
    return Entity::texture_id;
}

int Entity::getId() {
    return Entity::id;
}