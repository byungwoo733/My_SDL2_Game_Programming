// Here is an example of how you might implement transitioning from one stage to the next in a 2D RPG game using C and SDL2
#include <SDL2/SDL.h>

enum GameState { MainMenu, GameLevel };

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    GameState state = MainMenu;

    SDL_Texture* mainMenuBackground = NULL;
    mainMenuBackground = SDL_CreateTextureFromSurface(renderer, 
                                                      IMG_Load("main_menu_bg.png"));
    SDL_Texture* gameLevelBackground = NULL;
    gameLevelBackground = SDL_CreateTextureFromSurface(renderer, 
                                                       IMG_Load("game_level_bg.png"));
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 800;
    rect.h = 600;

    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = 0;
                }
                if (event.key.keysym.sym == SDLK_SPACE) {
                    if (state == MainMenu) {
                        state = GameLevel;
                    } else {
                        state = MainMenu;
                    }
                }
            }
        }

        SDL_RenderClear(renderer);
        if (state == MainMenu) {
            SDL_RenderCopy(renderer, mainMenuBackground, NULL, &rect);
        } else {
            SDL_RenderCopy(renderer, gameLevelBackground, NULL, &rect);
        }
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
