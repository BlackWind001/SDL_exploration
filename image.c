#include "image.h"
#include "main.h"

char *bmpFileName = "assets/bmp_24.bmp";
SDL_Surface *image, *windowSurface;
SDL_Rect imageRect;

void loadImage () {
  image = SDL_LoadBMP(bmpFileName);

  if (image == NULL || window == NULL) {
    printf("Failed to load image: %s\n", SDL_GetError());
  }

  imageRect.w = image->w;
  imageRect.h = image->h;

  windowSurface = SDL_GetWindowSurface(window);
  draw();
}

void draw() {
  SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface->format, 0, 0, 0));
  SDL_BlitSurface(image, NULL, windowSurface, &imageRect);
  SDL_UpdateWindowSurface(window);
}

void moveImageRight () {
  imageRect.x = imageRect.x + 10;
  draw();
}

void moveImageLeft () {
  imageRect.x = imageRect.x - 10;
  draw();
}

void moveImageUp () {
  imageRect.y = imageRect.y - 10;
  draw();
}

void moveImageDown () {
  imageRect.y = imageRect.y + 10;
  draw();
}
