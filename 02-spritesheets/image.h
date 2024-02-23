#ifndef IMAGE_H_SPRITESHEET_INCLUDED

#define IMAGE_H_SPRITESHEET_INCLUDED

#include <SDL2/SDL.h>
#include <stdio.h>
#include "global.h"

extern SDL_Surface *spritesheet_surface;
struct spritesheet_data {
  SDL_Surface *spritesheet_surface;
  int rows, cols;
  int single_sprite_w, single_sprite_h;
};

typedef struct spritesheet_data SP_Data;

SDL_Surface* loadSpritesheet(SDL_PixelFormat *desired_format);
SP_Data* initSpritesheet (int rows, int columns);
int drawSingleSprite (int row, int col, SDL_Rect dest_rect);

#endif