// Here is an example of a basic game loop using SDL2 for your own SDL Game engine in C
#include <SDL.h>
#include "engine.h"

int main(int argc, char* argv[]) {
    // Initialize the engine
    if (!engine_init()) {
        printf("Error initializing engine: %s\n", SDL_GetError());
        return 1;
    }

    // Main loop flag
    int quit = 0;

    // Event handler
    SDL_Event e;

    // While application is running
    while (!quit) {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
            // Pass event to engine
            engine_handle_event(&e);
        }

        // Update the engine
        engine_update();

        // Render the engine
        engine_render();
    }

    // Clean up the engine
    engine_cleanup();

    return 0;
}

/*
This example uses a separate engine.h file to initialize, update, render, handle events, and clean up the game engine.
*/

//======================================
//======================================

// You may need to provide the implementation of these functions in the engine.c file for example
bool engine_init()
{
    // Initialize SDL and create window
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        return 0;

    // Create window
    window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (!window)
        return 0;

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
        return 0;

    // Initialize other engine resources
    // ...

    return 1;
}

void engine_update()
{
    // Update game logic and other engine resources
    // ...
}

void engine_render()
{
    // Clear screen
    SDL_RenderClear(renderer);

    // Render game objects and other engine resources
    // ...

    // Update the window
    SDL_RenderPresent(renderer);
}

void engine_handle_event(SDL_Event* e)
{
    // Handle input events and other engine events
    // ...
}

void engine_cleanup()
{
    // Clean up engine resources
    // ...

    // Destroy renderer
    SDL_DestroyRenderer(renderer);

    // Destroy window
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();
}

/*
Keep in mind that this is just a simple example and there are many ways to organize and optimize a game engine depending on the needs of the specific game.
*/