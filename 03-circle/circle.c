#include "circle.h"

void drawCircle (SDL_Surface* surface, SDL_Window *window) {
  //take a point from center at a distance R
  int currentX = WINDOW_CENTER_X;
  int currentY = WINDOW_CENTER_Y + RADIUS;
  double newY;
  SDL_Rect pixel, center_pixel;

  pixel.h = 1;
  pixel.w = 1;
  center_pixel.h = 1;
  center_pixel.w = 1;
  center_pixel.x = WINDOW_CENTER_X;
  center_pixel.y = WINDOW_CENTER_Y;

  SDL_FillRect(surface, &center_pixel, SDL_MapRGB(surface->format, 0, 0, 255));
    SDL_UpdateWindowSurface(window);

  // up until y is the same as y of the center, keep looping
  while (currentY != WINDOW_CENTER_Y) {
    pixel.x = currentX;
    pixel.y = currentY;

    SDL_FillRect(surface, &pixel, SDL_MapRGB(surface->format, 255, 255, 255));
    SDL_UpdateWindowSurface(window);

    newY = sqrt(pow(RADIUS, 2) - pow(currentX + 1 - WINDOW_CENTER_X, 2)) + WINDOW_CENTER_Y;

    currentX = currentX + 1;
    currentY = newY;

    printf("(%d, %d), newY: %lf\n", currentX, currentY, newY);
  }
}
