#include "main.h"

SDL_Window *window;

int main(int argc, char *argv[]) {
  window = start();
  if (window != NULL){
    initSpritesheet(4, 9, window);
    loop();
  }
  end(window);
  return 0;
}

SDL_Window* start () {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("Error during initialization: %s", SDL_GetError());
    return NULL;
  }

  SDL_Window *window = SDL_CreateWindow(
    "Spritesheets Experiment",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    DEFAULT_DIMENSION_WIDTH, DEFAULT_DIMENSION_HEIGHT,
    SDL_WINDOW_RESIZABLE
  );

  if (window == NULL) {
    printf("Error during window creation: %s", SDL_GetError());
    return NULL;
  }

  return window;

}

void loop () {
  int game_is_running = 1;
  SDL_Event event;

  while (game_is_running) { // Game loop
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT: {
          game_is_running = 0;
          break;
        }
        case SDL_KEYDOWN: {
          switch(event.key.keysym.sym) {
            case SDLK_RIGHT: {
              // moveForward();
            }
          }
        }
      }
    }
  }
}

void end (SDL_Window* window) {
  SDL_FreeSurface(spritesheet_surface);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
