#include "image.h"
#include "main.h"

char *bmpFileName = "assets/bmp_24.bmp";
SDL_Surface *image, *windowSurface;
SDL_Rect imageRect;
bool shouldAnimateImage = false;
int directionX = 1, directionY = 1;

double _movementTracker = 0.0;

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

void animateImage () {

  if (!shouldAnimateImage) {
    return;
  }

  _movementTracker += (1.0/24.0);

  // NOTE: Removing the following printf
  // causes the animation to be very fast.
  // I assume that printf takes so long to run
  // that it causes a noticable difference when
  // call to printf is removed but this hypothesis
  // needs to be verified.
  printf("%lf\n", _movementTracker);

  if (_movementTracker >= 1) {
    _movementTracker = 0.0;

    imageRect.x = imageRect.x + directionX * 1;
    imageRect.y = imageRect.y + directionY * 1;

    // Update direction for next draw
    if ((imageRect.x + imageRect.w) == windowSurface->w || imageRect.x == 0) {
      directionX = -directionX;
    }

    if ((imageRect.y + imageRect.h) == windowSurface->h || imageRect.y == 0) {
      directionY = -directionY;
    }

    draw();
  }
}
