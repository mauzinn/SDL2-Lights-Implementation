#include <SDL2\SDL.h>
#include <vector>
#include <string>
#include "../include/vectors/vector2.hpp"
#include "../include/entities/entity.hpp"
#include "../include/entities/light.hpp"
#include "../include/controllers/frametime.hpp"
#include "../include/managers/scene.hpp"

Scene::Scene() {
    Scene::frametime_update.setFramerate(30);
};

Scene::~Scene() {
    for (int i = 0; i < Scene::textures.size(); i++) {
        SDL_DestroyTexture(Scene::textures[i]);
    }
}

void Scene::update() {
    if (Scene::frametime_update.getElapsedUpdate()) {
        for (int i = 0; i < Scene::entities.size(); i++) {
            Scene::entities[i]->update();
        }

        for (int i = 0; i < Scene::lights.size(); i++) {
            Scene::lights[i]->updateBrightofBlocks(Scene::entities);
        }
    }
}

void Scene::draw(SDL_Renderer* _renderer) {
    for (int i = 0; i < Scene::entities.size(); i++) {
        Scene::entities[i]->draw(_renderer, Scene::getTexture(Scene::entities[i]->getTextureId()));
    }
}

int Scene::setTexture(SDL_Renderer* _renderer, std::string _source) {
    SDL_Surface* surface = SDL_LoadBMP(_source.c_str());

    if (surface) {
        SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, surface);
        int buffer_texture_id = Scene::textures.size();
        Scene::textures.push_back(texture);

        return buffer_texture_id;
    }
    return -1;
}

void Scene::setLight(Light& _light) {
    Scene::lights.push_back(&_light);
}

void Scene::setEntity(Entity& _entity) {
    _entity.setId(Scene::entities.size());
    Scene::entities.push_back(&_entity);
}

SDL_Texture* Scene::getTexture(int _texture_index) {
    return Scene::textures[_texture_index];
}

Entity* Scene::getEntity(int _texture_index) {
    return Scene::entities[_texture_index];
}

int Scene::getEntitiesSize() {
    return Scene::entities.size();
}