#include "image.h"

SDL_Surface *spritesheet_surface = NULL;
struct spritesheet_data {
  int rows, cols;
  int single_sprite_w, single_sprite_h;
} sp_data;

SDL_Surface* loadSpritesheet(SDL_PixelFormat *desired_format) {
  SDL_Surface *raw_surface = NULL;
  raw_surface = SDL_LoadBMP("assets/stickman.bmp");
  spritesheet_surface = SDL_ConvertSurface(raw_surface, desired_format, 0);

  if (spritesheet_surface == NULL) {
    printf("Error loading the spritesheet: %s", SDL_GetError());
  }

  SDL_FreeSurface(raw_surface);
  return spritesheet_surface;
}

void initSpritesheet (int rows, int columns, SDL_Window *window) {

  SDL_Surface *window_surface = SDL_GetWindowSurface(window);

  loadSpritesheet(window_surface->format);

  if (spritesheet_surface == NULL) {
    return;
  }
  
  sp_data.rows = rows;
  sp_data.cols = columns;
  sp_data.single_sprite_w = spritesheet_surface->w/columns;
  sp_data.single_sprite_h = spritesheet_surface->h/rows;

  drawSingleSprite(0,0, window);
}

void drawSingleSprite (int row, int col, SDL_Window *window) {
  SDL_Surface* window_surface = SDL_GetWindowSurface(window);
  SDL_Rect current_sprite;

  current_sprite.x = sp_data.single_sprite_w * col;
  current_sprite.y = sp_data.single_sprite_h * row;
  current_sprite.w = sp_data.single_sprite_w;
  current_sprite.h = sp_data.single_sprite_h;

  SDL_FillRect(window_surface, NULL, SDL_MapRGB(window_surface->format, 255, 255, 255));
  SDL_BlitSurface(spritesheet_surface, &current_sprite, window_surface, NULL);
  SDL_UpdateWindowSurface(window);
}
