#ifndef IMAGE_H_INCLUDED

#define IMAGE_H_INCLUDED

#include <SDL2/SDL_Surface.h>
#include <stdio.h>

void loadImage ();
void logImageInfo ();

extern SDL_Surface *image, *windowSurface;
extern char *bmpFileName;

#endif