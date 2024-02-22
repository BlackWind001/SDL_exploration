#ifndef MAIN_H_SPRITESHEET_INCLUDED

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <stdio.h>
// ToDo: Once all the references to image related functions
// are removed from main.c, the following include directive
// should be removed.
#include "image.h"

#define DEFAULT_DIMENSION_WIDTH 720
#define DEFAULT_DIMENSION_HEIGHT 600

SDL_Window* start ();
void loop();
void loadImage();
void end (SDL_Window* window);

#endif // MAIN_H_SPRITESHEET_INCLUDED