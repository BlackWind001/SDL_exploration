#include "character.h"

Character character;
double _movementTracker = 0.0;

void _initRect (SDL_Rect *rect) {
  rect->h = character.sp_data->single_sprite_h;
  rect->w = character.sp_data->single_sprite_w;
  rect->x = character.pos_x;
  rect->y = character.pos_y;
}

// setup and draw the character
int initCharacterFromSpriteSheet (int sp_rows, int sp_cols) {
  // Get the spritesheet data and initialize sp_data.
  SP_Data *sp_data = initSpritesheet(sp_rows, sp_cols);
  SDL_Rect rect;

  if (sp_data == NULL) {
    printf("Error getting the spritesheet surface\n");
    return -1;
  }

  character.sp_data = sp_data;
  character.pos_x = 0;
  character.pos_y = 0;

  // Initial drawing of a single sprite.
  _initRect(&rect);
  drawSingleSprite(0, 0, rect);
}

// update character position on keypress
int moveCharacterForward () {
  SDL_Rect rect;
  character.current_action = WALKING;
  character.current_direction = RIGHT;

  character.pos_x += character.current_direction * 1;

  _initRect(&rect);

  return drawSingleSprite(2, 1, rect);
}

int moveCharacterBackward () {
  SDL_Rect rect;
  character.current_action = WALKING;
  character.current_direction = LEFT;

  character.pos_x += character.current_direction * 1;

  _initRect(&rect);

  return drawSingleSprite(1, 7, rect);
}

int makeCharacterStill () {
  SDL_Rect rect;
  character.current_action = STILL;

  _initRect(&rect);

  return drawSingleSprite(0, 0, rect);
}

// cleanup
void cleanup () {
  SDL_FreeSurface(character.sp_data->spritesheet_surface);
}
