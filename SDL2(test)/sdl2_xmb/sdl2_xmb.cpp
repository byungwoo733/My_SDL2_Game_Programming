#include <SDL.h>
#include <SDL_ttf.h>

int main(int argc, char* argv[])
{
    // Initialize SDL and TTF
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        // Error initializing SDL
        return 1;
    }
    if (TTF_Init() != 0)
    {
        // Error initializing TTF
        return 1;
    }

    // Load a font
    TTF_Font* font = TTF_OpenFont("arial.ttf", 24);
    if (!font)
    {
        // Error loading font
        return 1;
    }

    // Create the window
    SDL_Window* window = SDL_CreateWindow("My GUI", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
    if (!window)
    {
        // Error creating window
        return 1;
    }

    // Create the renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
    {
        // Error creating renderer
        return 1;
    }

    // Create a button
    SDL_Color buttonColor = { 0, 0, 255, 255 };
    SDL_Surface* buttonSurface = TTF_RenderText_Solid(font, "Click me!", buttonColor);
    SDL_Texture* buttonTexture = SDL_CreateTextureFromSurface(renderer, buttonSurface);
    SDL_Rect buttonRect = { 10, 10, 100, 50 };

    // Create a text box
    SDL_Color textBoxColor = { 255, 255, 255, 255 };
    SDL_Surface* textBoxSurface = TTF_RenderText_Solid(font, "Enter your name:", textBoxColor);
    SDL_Texture* textBoxTexture = SDL_CreateTextureFromSurface(renderer, textBoxSurface);
    SDL_Rect textBoxRect = { 10, 70, 200, 50 };

    // Run the main loop
    bool running = true;
    while (running)
    {
        // Handle events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                // Check if the button was clicked
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x >= buttonRect.x && x < buttonRect.x + buttonRect.w && y >= buttonRect.y && y < buttonRect.y + buttonRect.h)
                {
                    // Button was clicked, do something...
                }
            }
        }

  // Draw the button and text box
        SDL_RenderCopy(renderer, buttonTexture, NULL, &buttonRect);
        SDL_RenderCopy(renderer, textBoxTexture, NULL, &textBoxRect);

        // Display the window
        SDL_RenderPresent(renderer);
    }

    // Clean up
    SDL_DestroyTexture(buttonTexture);
    SDL_FreeSurface(buttonSurface);
    SDL_DestroyTexture(textBoxTexture);
    SDL_FreeSurface(textBoxSurface);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}