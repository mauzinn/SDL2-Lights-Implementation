#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SDL2\SDL.h>
#include "../controllers/animation.hpp"
#include "../vectors/vector2.hpp"

class Entity {
    private:
    Animation animation;
    Vector2::Vector2f position, size;
    int id, texture_id;
    unsigned char bright;
    bool animated, show;

    public:
    Entity();
    void update();
    void draw(SDL_Renderer* _renderer, SDL_Texture* _texture);

    void setId(int _id);
    void setAnimation(int _texture_id, int _frames, int _columns, int _current_column, int _current_frame);
    void setAnimated(bool _animated);
    void setShow(bool _show);
    void setPosition(Vector2::Vector2f _position);
    void setSize(Vector2::Vector2f _size);
    void setBright(int bright);

    Vector2::Vector2f getPosition();
    Vector2::Vector2f getSize();
    unsigned char getBright();
    int getTextureId();
    int getId();
};

#endif