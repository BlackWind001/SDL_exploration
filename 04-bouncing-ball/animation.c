#include "animation.h"

// Velocity is usually metres per second.
// But when time is not involved and instead we have frames,
// we can convert velocity into pixels per frame.
static double velocityY = 0.16, incrementY = 0, velocityX = 0.016, incrementX = 0;
static int directionY = 1, directionX = 1;
SDL_Rect rect = { 10, ANIMATION_START_Y, 50, 50 };

void drawRect (SDL_Rect *rect) {
  int error;
  SDL_FillRect(global.window_surface, NULL, SDL_MapRGB(global.window_surface->format, 255, 255, 255));
  error = SDL_FillRect(global.window_surface, rect, SDL_MapRGB(global.window_surface->format, 0, 0, 0));

  SDL_UpdateWindowSurface(global.window);

  if (error != 0) {
    printf("Error drawing rectangle: %s\n", SDL_GetError());
  }
}

void runAnimation () {
  incrementY += velocityY;
  incrementX += velocityX;

  if (incrementY >= 1) {
    rect.y += directionY * (int)incrementY;
    incrementY = 0;

    // detect collision
    if ((rect.y + rect.h) >= global.window_surface->h || rect.y <= ANIMATION_START_Y) {
      directionY = -directionY;
    }
  }

  if (incrementX >= 1) {
    rect.x += directionX * (int)incrementX;
    incrementX = 0;

    if ((rect.x + rect.w) >= global.window_surface->w || rect.x <= ANIMATION_START_X) {
      directionX = -directionX;
    }
  }

  drawRect(&rect); 
}

static void cleanup () {}
