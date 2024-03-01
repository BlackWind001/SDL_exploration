#ifndef MAIN_H_BOUNCING_BALL_INCLUDED

#define MAIN_H_BOUNCING_BALL_INCLUDED

#define SDL_MAIN_HANDLED

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "animation.h"

#define DEFAULT_WINDOW_WIDTH 640
#define DEFAULT_WINDOW_HEIGHT 480

#define ERROR_WINDOW_CREATION -1
#define ERROR_WINDOW_SURFACE_GET -1

typedef struct {
  SDL_Window *window;
  SDL_Surface *window_surface;
} Global;

extern Global global;

#endif // MAIN_H_BOUNCING_BALL_INCLUDED
