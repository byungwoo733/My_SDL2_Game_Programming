// Here is some sample code for creating a 2D sprite sheet in C using SDL
#include <SDL2/SDL.h>

int main() {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Sprite Sheet Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // Load the sprite sheet
    SDL_Surface* spriteSheet = SDL_LoadBMP("sprites.bmp");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, spriteSheet);
    SDL_FreeSurface(spriteSheet);

    // Set the current frame to the first frame
    SDL_Rect srcRect = {0, 0, 64, 64};

    // Main game loop
    while (1) {
        // Handle events
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                break;
            }
        }

        // Update the current frame
        srcRect.x = frame * 64;

        // Clear the window
        SDL_RenderClear(renderer);

        // Draw the sprite
        SDL_RenderCopy(renderer, texture, &srcRect, NULL);

        // Display the window
        SDL_RenderPresent(renderer);
    }

    // Clean up
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

/* here's a sample code for handling input controls in C using SDL
const Uint8* state = SDL_GetKeyboardState(NULL);
if (state[SDL_SCANCODE_LEFT]) {
    // Move the sprite left
    srcRect.x -= 5;
}
if (state[SDL_SCANCODE_RIGHT]) {
    // Move the sprite right
    srcRect.x += 5;
}
if (state[SDL_SCANCODE_UP]) {
    // Move the sprite up
    srcRect.y -= 5;
}
if (state[SDL_SCANCODE_DOWN]) {
    // Move the sprite down
    srcRect.y += 5;
}

*/