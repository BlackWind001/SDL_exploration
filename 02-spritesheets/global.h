#ifndef GLOBAL_H_SPRITESHEET_INCLUDED

#define GLOBAL_H_SPRITESHEET_INCLUDED
#include <SDL2/SDL.h>

extern struct Global {
  SDL_Window *window;
  SDL_Surface *window_surface;
} global;

typedef struct Global Global;

#endif // GLOBAL_H_SPRITESHEET_INCLUDED