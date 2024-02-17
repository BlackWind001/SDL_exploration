#ifndef IMAGE_H_INCLUDED

#define IMAGE_H_INCLUDED

#include <SDL2/SDL_Surface.h>
#include <stdio.h>
#include <stdbool.h>

void loadImage ();
void moveImageRight ();
void moveImageLeft ();
void moveImageUp ();
void moveImageDown ();
void draw();
void animateImage();

extern SDL_Surface *image, *windowSurface;
extern char *bmpFileName;
extern bool shouldAnimateImage;

#endif