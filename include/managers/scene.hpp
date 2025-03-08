#ifndef SCENE_HPP
#define SCENE_HPP

#include <SDL2\SDL.h>
#include <vector>
#include <string>
#include "../vectors/vector2.hpp"
#include "../entities/entity.hpp"
#include "../entities/light.hpp"
#include "../controllers/frametime.hpp"

class Scene {
    private:
    Frametime frametime_update;
    std::vector<SDL_Texture*> textures;
    std::vector<Entity*> entities;
    std::vector<Light*> lights;

    public:
    Scene();
    ~Scene();
    void update();
    void draw(SDL_Renderer* _renderer);

    int setTexture(SDL_Renderer* _renderer, std::string _source);
    void setLight(Light& _light);
    void setEntity(Entity& _entity);

    SDL_Texture* getTexture(int _texture_id);
    Entity* getEntity(int _entity_id);
    int getEntitiesSize();
};

#endif