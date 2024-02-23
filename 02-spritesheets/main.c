#include "main.h"

Global global;

int main(int argc, char *argv[]) {
  global.window = start();
  if (global.window != NULL){
    global.window_surface = SDL_GetWindowSurface(global.window);
    initCharacterFromSpriteSheet(4, 9);
    loop();
  }
  end(global.window);
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
    SDL_PollEvent(&event);
    if (event.type == SDL_KEYDOWN) {
      switch(event.key.keysym.sym) {
        case SDLK_RIGHT: {
          moveCharacterForward();
          break;
        }
        case SDLK_LEFT: {
          moveCharacterBackward();
        }
      }
    }
    else if (event.type  == SDL_KEYUP) {
      makeCharacterStill();
    }
    else if (event.type == SDL_QUIT) {
      game_is_running = 0;
    }
  }
}

void end (SDL_Window* window) {
  cleanup();
  SDL_DestroyWindow(global.window);
  SDL_Quit();
}
