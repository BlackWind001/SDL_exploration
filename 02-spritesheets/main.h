#ifndef MAIN_H_SPRITESHEET_INCLUDED

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <stdio.h>
#include "global.h"
#include "character.h"

#define DEFAULT_DIMENSION_WIDTH 720
#define DEFAULT_DIMENSION_HEIGHT 600

SDL_Window* start ();
void loop();
void loadImage();
void end (SDL_Window* window);

#endif // MAIN_H_SPRITESHEET_INCLUDED