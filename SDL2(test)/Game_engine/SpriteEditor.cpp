// Here's an example of how you could move the sprite using keyboard input in SDL2
#include "SDL.h"
#include <iostream>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Sprite Editor",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          800, 600,
                                          SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // Load the sprite image
    SDL_Surface* sprite_surface = SDL_LoadBMP("sprite.bmp");
    SDL_Texture* sprite_texture = SDL_CreateTextureFromSurface(renderer, sprite_surface);
    SDL_FreeSurface(sprite_surface);

    // Set the initial position of the sprite
    SDL_Rect sprite_rect;
    sprite_rect.x = 400;
    sprite_rect.y = 300;
    SDL_QueryTexture(sprite_texture, NULL, NULL, &sprite_rect.w, &sprite_rect.h);

    float speed = 200.0f; // pixels per second
    Uint32 last_time = SDL_GetTicks();

    bool running = true;
    while (running) {
        Uint32 current_time = SDL_GetTicks();
        float elapsed = (current_time - last_time) / 1000.0f;
        last_time = current_time;

        // Handle events
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_LEFT:
                    sprite_rect.x -= speed * elapsed;
                    break;
                case SDLK_RIGHT:
                    sprite_rect.x += speed * elapsed;
                    break;
                case SDLK_UP:
                    sprite_rect.y -= speed * elapsed;
                    break;
                case SDLK_DOWN:
                    sprite_rect.y += speed * elapsed;
                    break;
                }
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, sprite_texture, NULL, &sprite_rect);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(sprite_texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}





/* Here is an example of how to create a simple sprite editor using the SDL2 library in C++
#include "SDL.h"
#include <iostream>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Sprite Editor",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          800, 600,
                                          SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // Load the sprite image
    SDL_Surface* sprite_surface = SDL_LoadBMP("sprite.bmp");
    SDL_Texture* sprite_texture = SDL_CreateTextureFromSurface(renderer, sprite_surface);
    SDL_FreeSurface(sprite_surface);

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, sprite_texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(sprite_texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}