// Here's a sample code snippet that demonstrates how you might use SDL2 to create a portal that transitions the player to a new stage when they interact with it
#include <SDL2/SDL.h>
#include <string>

const int PORTAL_WIDTH = 32;
const int PORTAL_HEIGHT = 32;

int portal_x = 100;
int portal_y = 100;

std::string next_stage = "stage2.tmx";

void update_game(SDL_Event& e) {
    if(e.type == SDL_MOUSEBUTTONDOWN) {
        int mouse_x, mouse_y;
        SDL_GetMouseState(&mouse_x, &mouse_y);

        if(mouse_x > portal_x && mouse_x < portal_x + PORTAL_WIDTH && mouse_y > portal_y && mouse_y < portal_y + PORTAL_HEIGHT) {
            load_stage(next_stage);
        }
    }
}

void render_game(SDL_Renderer* renderer) {
    SDL_Rect portal_rect = {portal_x, portal_y, PORTAL_WIDTH, PORTAL_HEIGHT};
    SDL_RenderCopy(renderer, portal_texture, NULL, &portal_rect);
}
