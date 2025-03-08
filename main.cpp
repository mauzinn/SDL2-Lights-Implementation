#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "./include/managers/scene.hpp"
#include "./include/entities/entity.hpp"
#include "./include/vectors/vector2.hpp"

bool setup(SDL_Window** _window, SDL_Renderer** _renderer);

int SDL_main(int argc, char* argv[]) {
    Scene scene;
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::vector<Entity> entities;
    int buffer_map[10][10] = {
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {0, 1, -1, -1, -1, 1, -1, -1, -1, 1},
        {0, 0, 1, -1, 1, 0, -1, -1, 1, 0},
        {0, 0, 0, 1, -1, -1, -1, 1, 0, 0},
        {0, -1, -1, -1, -1, -1, -1, 0, 0, 0},
        {0, -1, -1, -1, -1, -1, 1, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 0, 0, 0, 0}
    };

    if (setup(&window, &renderer)) {
        int texture1 = scene.setTexture(renderer, "assets/default_blocks.bmp");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (buffer_map[i][j] >= 0) {
                    Entity buffer_block;
                    if (buffer_map[i][j] == 1) {
                        buffer_block.setAnimation(texture1, 8, 8, 3, 1);
                    } else if (buffer_map[i][j] == 0) {
                        buffer_block.setAnimation(texture1, 8, 8, 3, 2);
                    }
    
                    buffer_block.setShow(true);
                    buffer_block.setAnimated(false);
                    buffer_block.setSize(Vector2::Vector2f(35, 35));
                    Vector2::Vector2f init_map(1280 / 2 - buffer_block.getSize().x * 10 / 2, 720 / 2 - buffer_block.getSize().y * 10 / 2);
                    buffer_block.setPosition(Vector2::Vector2f(j * buffer_block.getSize().x + init_map.x, i * buffer_block.getSize().y + init_map.y));
    
                    entities.push_back(buffer_block);
                }
            }
        }

        for (int i = 0; i < entities.size(); i++) {
            scene.setEntity(entities[i]);
        }

        Entity torch_mouse;
        torch_mouse.setSize(Vector2::Vector2f(35, 35));
        torch_mouse.setAnimation(texture1, 8, 8, 3, 6);
        torch_mouse.setShow(true);
        torch_mouse.setAnimated(false);

        scene.setEntity(torch_mouse);

        Light light1;
        light1.setBright(255);

        scene.setLight(light1);

        bool window_open = true;
        while (window_open) {
            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        window_open = false;
                        break;

                    case SDL_MOUSEMOTION:
                        light1.setPosition(Vector2::Vector2f(event.motion.x, event.motion.y));
                        break;
                }
            }
            scene.update();
            Vector2::Vector2f buffer_position = light1.getPosition();
            buffer_position.x -= 35 / 2;
            buffer_position.y -= 35 / 2;
            torch_mouse.setPosition(buffer_position);

            SDL_RenderClear(renderer);
            scene.draw(renderer);
            SDL_RenderPresent(renderer);
            SDL_Delay(22);
        }

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    return 0;
}

bool setup(SDL_Window** _window, SDL_Renderer** _renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "ERROR IN SDL_INIT.\n";
        return false;
    }

    *_window = SDL_CreateWindow(
        "basic_window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280,
        720,
        SDL_WINDOW_SHOWN
    );

    if (!*_window) {
        std::cerr << "ERROR IN SDL_Window.\n";
        SDL_Quit();
        return false;
    }

    *_renderer = SDL_CreateRenderer(*_window, -1, 0);

    if (!*_renderer) {
        std::cerr << "ERROR IN SDL_Renderer.\n";
        SDL_DestroyWindow(*_window);
        SDL_Quit();
        return false;
    }

    return true;
}