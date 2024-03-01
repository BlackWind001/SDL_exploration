#include "main.h"

Global global;

int main(int argc, char* argv[]) {
  int is_setup_success = setup();

  if (is_setup_success == 0) {
    loop();
  }

  cleanup();
  return 0;
}

int setup () {
  global.window = SDL_CreateWindow(
    "Circle",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    DEFAULT_WINDOW_WIDTH,
    DEFAULT_WINDOW_HEIGHT,
    0
  );

   if (global.window == NULL) {
    printf("Error creating window: %s", SDL_GetError());
    cleanup();
    return -1;
  }

  global.window_surface = SDL_GetWindowSurface(global.window);

  if (global.window_surface == NULL) {
    printf("Error getting window surface: %s", SDL_GetError());
    cleanup();
    return -2;
  }

  return 0;
}

void loop () {
  SDL_Event event;
  int is_game_running = 1;

  drawCircle(global.window_surface, global.window);
  while (is_game_running) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT: {
          is_game_running = 0;
          break;
        }
      }
    }
  }

}

void cleanup () {
  SDL_DestroyWindow(global.window);
  SDL_Quit();
}
