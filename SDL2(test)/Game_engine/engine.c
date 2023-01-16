// Here is an example of a main.c file for an SDL2 game engine
#include <SDL.h>
#include "engine.h"

int main(int argc, char* argv[]) {
    // Initialize the engine
    if (!engine_init()) {
        // Handle initialization error
    }

    // Main loop flag
    bool quit = false;

    // Event handler
    SDL_Event e;

    // While application is running
    while (!quit) {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
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
This example uses a separate engine.h file to initialize, update, and render the game engine.
*/
