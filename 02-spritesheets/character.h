#ifndef CHARACTER_H_SPRITESHEET_INCLUDED

#define CHARACTER_H_SPRITESHEET_INCLUDED
#include <SDL2/SDL.h>
#include "image.h"
#include "global.h"

enum CURRENT_ACTION {
  STILL,
  WALKING
};

enum DIRECTION {
  LEFT = -1,
  RIGHT = 1
};

struct Character {
  SP_Data *sp_data; // ToDo: NULL initialize this value
  int pos_x, pos_y;
  enum CURRENT_ACTION current_action;
  enum DIRECTION current_direction;
};

typedef struct Character Character;

int initCharacterFromSpriteSheet (int sp_rows, int sp_cols);
int moveCharacterForward ();
int moveCharacterBackward ();
int makeCharacterStill ();
void cleanup();

#endif // CHARACTER_H_SPRITESHEET_INCLUDED