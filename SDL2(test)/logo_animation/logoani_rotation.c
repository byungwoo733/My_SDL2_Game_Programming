// Here's an example of how you can create a window and display an animation of a logo using C and the SDL2 library
#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create the window
    SDL_Window* window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create the renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Load the image
    SDL_Surface* surface = SDL_LoadBMP("logo.bmp");
    if (surface == NULL)
    {
        printf("Unable to load image %s! SDL_Error: %s\n", "logo.bmp", SDL_GetError());
        return 1;
    }

    // Create the texture
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL)
    {
        printf("Unable to create texture from %s! SDL_Error: %s\n", "logo.bmp", SDL_GetError());
        return 1;
    }

    // Free the surface
    SDL_FreeSurface(surface);

    // Create a rectangle to represent the logo's position and size
    SDL_Rect logoRect = {200, 150, 400, 300};

    // Create a variable to store the angle of rotation
    double angle = 0.0;

    // Create a variable to store the time of the last frame
    Uint32 lastFrame = 0;

    // Start the game loop
    int quit = 0;
    while (!quit)
    {
        // Handle events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = 1;
            }
        }

        // Clear the screen
        SDL_RenderClear(renderer);

        // Draw the texture
        SDL_RenderCopyEx(renderer, texture, NULL, &logoRect, angle, NULL, SDL_FLIP_NONE);

        // Update the screen
        SDL_RenderPresent(renderer);

          // Update the angle of rotation
        Uint32 currentFrame = SDL_GetTicks();
        double deltaTime = (currentFrame - lastFrame) / 1000.0;
        angle += deltaTime * 180; // Rotate 180 degrees per second
        lastFrame = currentFrame;