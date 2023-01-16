
// Player Handle Input
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* argv[]) {
    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow("My 2D RPG Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Handle keyboard input
    bool quit = false;
    while (!quit) {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        player_y -= PLAYER_SPEED;
                        break;
                    case SDLK_DOWN:
                        player_y += PLAYER_SPEED;
                        break;
                    case SDLK_LEFT:
                        player_x -= PLAYER_SPEED;
                        break;
                    case SDLK_RIGHT:
                        player_x += PLAYER_SPEED;
                        break;
                    default:
                        break;
                }
            }
        }

        // Update game state
        updateEnemies();
        updatePlayer();

        // Render game graphics
        SDL_RenderClear(renderer);
        renderPlayer();
        renderEnemies();
        SDL_RenderPresent(renderer);
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

//======================

// Here's an example of how you might initialize SDL2 and create a window for the game
// Initialize SDL2
if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 1;
}

// Create window
SDL_Window* window = SDL_CreateWindow("My 2D RPG Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
if (window == NULL) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return 1;
}

// Here's an example of how you might handle keyboard input for player movement
// Handle keyboard input
SDL_Event e;
while (SDL_PollEvent(&e) != 0) {
    if (e.type == SDL_QUIT) {
        quit = true;
    }
    else if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
            case SDLK_UP:
                player_y -= PLAYER_SPEED;
                break;
            case SDLK_DOWN:
                player_y += PLAYER_SPEED;
                break;
            case SDLK_LEFT:
                player_x -= PLAYER_SPEED;
                break;
            case SDLK_RIGHT:
                player_x += PLAYER_SPEED;
                break;
            default:
                break;
        }
    }
}

// Game loop
while (!quit) {
    // Update game state
    updateEnemies();
    updatePlayer();

    // Render game graphics
    SDL_RenderClear(renderer);
    renderPlayer();
    renderEnemies();
    SDL_RenderPresent(renderer);
}

//============================