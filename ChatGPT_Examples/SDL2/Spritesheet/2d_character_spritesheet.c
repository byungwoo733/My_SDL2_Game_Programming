#include <SDL2/SDL.h>

int main() {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Sprite Sheet Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // Load the sprite sheet
    SDL_Surface* spriteSheet = SDL_LoadBMP("character.bmp");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, spriteSheet);
    SDL_FreeSurface(spriteSheet);

    // Set the starting animation frame
    int frame = 0;
    // Set the animation to the walking right animation
    SDL_Rect srcRect = {frame * 64, 0, 64, 64}; // 64 is the width and height of each frame

    // Main game loop
    while (1) {
        // Handle events
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                break;
            }
        }

        // Update the animation frame
        frame = (frame + 1) % 8; // 8 is the number of frames in the sprite sheet

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

/* here is an example of how you could handle input controls for a character in a 2D game using C and SDL library
// Update the character's position based on input
const Uint8* state = SDL_GetKeyboardState(NULL);
if (state[SDL_SCANCODE_LEFT]) {
    srcRect.x -= 5;
    // Set the animation to the walking left animation
    srcRect.y = 64;
}
if (state[SDL_SCANCODE_RIGHT]) {
    srcRect.x += 5;
    // Set the animation to the walking right animation
    srcRect.y = 0;
}
if (state[SDL_SCANCODE_UP]) {
    srcRect.y -= 5;
    // Set the animation to the jumping animation
    srcRect.y = 128;
}
if (state[SDL_SCANCODE_DOWN]) {
    srcRect.y += 5;
    // Set the animation to the crouching animation
    srcRect.y = 192;
}

*/