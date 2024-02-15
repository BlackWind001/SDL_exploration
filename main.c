#define SDL_MAIN_HANDLED
#include "main.h"
#include "image.h"

const char *windowTitle = "New Window";
SDL_Window *window;
SDL_Event event;

int main (int argc, char* argv[]) {

  int running = SDL_Init(SDL_INIT_VIDEO) == 0 ? 1 : 0;

  if (!running) {
    printf("Running Error: %s", SDL_GetError());
    return 1;
  }

  window = SDL_CreateWindow(
    "New Window",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    DIMENSION_WIDTH, DIMENSION_HEIGHT,
    0
  );

  if (window == NULL) {
    printf("Window Error: %s", SDL_GetError());
    return 1;
  }

  loadImage();

  while(running) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT: {
          printf("Quit event recognized");
          running = 0;
          break;
        }
      }
    }
  }


  SDL_FreeSurface(image);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
