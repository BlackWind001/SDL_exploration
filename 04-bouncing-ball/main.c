#include "main.h"

Global global;

SDL_Window* createWindow () {
  return SDL_CreateWindow(
    "Bouncing ball",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    DEFAULT_WINDOW_WIDTH,
    DEFAULT_WINDOW_HEIGHT,
    SDL_WINDOW_RESIZABLE
  );
}

static void cleanup () {
  SDL_DestroyWindow(global.window);
}

void loop () {
  bool game_is_running = true;
  SDL_Event event;

  while (game_is_running) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT: {
          game_is_running = false;
          break;
        }
      }
    }
    runAnimation();
  }
}

int main (int argc, char *argv[]) {
  global.window = createWindow();

  if (global.window == NULL) {
    printf("Error creating window: %s\n", SDL_GetError());
    return ERROR_WINDOW_CREATION;
  }

  global.window_surface = SDL_GetWindowSurface(global.window);

  if (global.window_surface == NULL) {
    printf("Error getting window surface: %s\n", SDL_GetError());
    return ERROR_WINDOW_SURFACE_GET;
  }

  loop();

  cleanup();
  return 0;
}
