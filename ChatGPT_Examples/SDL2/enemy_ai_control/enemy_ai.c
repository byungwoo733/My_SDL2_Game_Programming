// Here's an example of how you might implement an enemy AI in a 2D RPG game using C and SDL2
#include <SDL2/SDL.h>

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("Enemy AI Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Create a player character and an enemy
    SDL_Rect player = { 200, 200, 40, 40 };
    SDL_Rect enemy = { 100, 100, 40, 40 };

    // Game loop
    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        // Move the enemy towards the player
        int playerX = player.x + player.w / 2;
        int playerY = player.y + player.h / 2;
        int enemyX = enemy.x + enemy.w / 2;
        int enemyY = enemy.y + enemy.h / 2;

        int xDiff = playerX - enemyX;
        int yDiff = playerY - enemyY;

        float distance = sqrt(xDiff * xDiff + yDiff * yDiff);
        float stepX = xDiff / distance;
        float stepY = yDiff / distance;

        enemy.x += stepX * 0.5f;
        enemy.y += stepY * 0.5f;

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw the player and the enemy
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &player);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &enemy);

        // Update the screen
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}