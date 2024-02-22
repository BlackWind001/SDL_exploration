#ifndef IMAGE_H_SPRITESHEET_INCLUDED

#include <SDL2/SDL.h>
#include <stdio.h>

SDL_Surface* loadSpritesheet(SDL_PixelFormat *desired_format);
void initSpritesheet (int rows, int columns, SDL_Window *window);
void drawSingleSprite (int row, int col, SDL_Window *window);

extern SDL_Surface *spritesheet_surface;
struct spritesheet_data {
  int rows, cols;
  int single_sprite_w, single_sprite_h;
};

typedef struct spritesheet_data SP_Data;

#endif