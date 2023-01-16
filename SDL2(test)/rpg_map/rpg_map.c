// Here is an example of a C file that creates a window and renders a 2D world map using the SDL2 library and an array to store the map data
#include "rpg_map.h"

const int MAP_WIDTH = 100;
const int MAP_HEIGHT = 100;

int rpg_map[MAP_WIDTH][MAP_HEIGHT];

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("RPG World Map", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface* tileset = IMG_Load("tileset.png");
    SDL_Texture* tileset_texture = SDL_CreateTextureFromSurface(renderer, tileset);
    load_map_data();

    while (1) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                goto end;
            }
        }
        render_map(renderer, tileset_texture);
        SDL_RenderPresent(renderer);
    }

end:
    SDL_DestroyTexture(tileset_texture);
    SDL_FreeSurface(tileset);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

/*
Note that the load_map_data() function should fill the world_map array with the appropriate data and the render_map() function should use that data to render the map using the SDL2 renderer. Also, it is important to note that this is just an example, you will likely have to make some adjustments to make it work in your specific use case and also you can use texture in sdl2 to map the world.

[번역]
load_map_data() 함수는 world_map 배열을 적절한 데이터로 채워야 하고 render_map() 함수는 해당 데이터를 사용하여 SDL2 렌더러를 사용하여 지도를 렌더링해야 합니다. 또한 이것은 단지 예일 뿐이며 특정 사용 사례에서 작동하도록 약간의 조정이 필요할 수 있으며 sdl2의 텍스처를 사용하여 세계를 매핑할 수도 있다는 점에 유의하는 것이 중요합니다.
*/