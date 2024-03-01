#ifndef MAIN_H_CIRCLE_INCLUDED

#define MAIN_H_CIRCLE_INCLUDED
#define SDL_MAIN_HANDLED

#include <stdio.h>
#include <SDL2/SDL.h>
#include "circle.h"

#define DEFAULT_WINDOW_WIDTH 640
#define DEFAULT_WINDOW_HEIGHT 480

typedef struct {
  SDL_Window* window;
  SDL_Surface* window_surface;
} Global;

int setup ();
void loop ();
void cleanup ();

extern Global global;

#endif // CIRCLE_H_CIRCLE_INCLUDED
