#ifndef MAIN_H_INCLUDED

#define MAIN_H_INCLUDED

#define SDL_MAIN_HANDLED
#include <stdio.h>
#include <SDL2/SDL.h>

#define DIMENSION_WIDTH 640
#define DIMENSION_HEIGHT 480

extern const char *windowTitle;
extern SDL_Window *window;
extern SDL_Event event;

#endif /* MAIN_H_INCLUDED */