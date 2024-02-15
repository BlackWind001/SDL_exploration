#include "image.h"
#include "main.h"

char *bmpFileName = "assets/bmp_24.bmp";
SDL_Surface *image, *windowSurface;

void loadImage () {
  image = SDL_LoadBMP(bmpFileName);

  if (image == NULL || window == NULL) {
    printf("Failed to load image: %s\n", SDL_GetError());
  }

  windowSurface = SDL_GetWindowSurface(window);
  SDL_BlitSurface(image, NULL, windowSurface, NULL);
  SDL_UpdateWindowSurface(window);
}
