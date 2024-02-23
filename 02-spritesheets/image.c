#include "image.h"

static SP_Data sp_data;

SDL_Surface* loadSpritesheet(SDL_PixelFormat *desired_format) {
  SDL_Surface *raw_surface = NULL;
  raw_surface = SDL_LoadBMP("assets/stickman.bmp");
  sp_data.spritesheet_surface = SDL_ConvertSurface(raw_surface, desired_format, 0);

  if (sp_data.spritesheet_surface == NULL) {
    printf("Error loading the spritesheet: %s", SDL_GetError());
  }

  SDL_FreeSurface(raw_surface);
  return sp_data.spritesheet_surface;
}

SP_Data* initSpritesheet (int rows, int columns) {

  SDL_Window *window = global.window;
  SDL_Surface *window_surface = global.window_surface;

  loadSpritesheet(window_surface->format);

  if (sp_data.spritesheet_surface == NULL) {
    return NULL;
  }
  
  sp_data.rows = rows;
  sp_data.cols = columns;
  sp_data.single_sprite_w = sp_data.spritesheet_surface->w/columns;
  sp_data.single_sprite_h = sp_data.spritesheet_surface->h/rows;

  return &sp_data;
}

// ToDo: Return an int value depending on if the drawing failed or succeeded.
int drawSingleSprite (int row, int col, SDL_Rect dest_rect) {
  SDL_Window *window = global.window;
  SDL_Surface* window_surface = global.window_surface;
  SDL_Rect src_rect;

  src_rect.x = sp_data.single_sprite_w * col;
  src_rect.y = sp_data.single_sprite_h * row;
  src_rect.w = sp_data.single_sprite_w;
  src_rect.h = sp_data.single_sprite_h;

  SDL_FillRect(window_surface, NULL, SDL_MapRGB(window_surface->format, 255, 255, 255));
  SDL_BlitSurface(sp_data.spritesheet_surface, &src_rect, window_surface, &dest_rect);
  SDL_UpdateWindowSurface(window);

  // ToDo: Add logic to return a different value on error
  return 0;
}
