#include "image.h"
#include "main.h"
#include "utils.h"

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

void logImageInfo () {
  SDL_PixelFormat *format;
  char dest[33];
  char *s1 = "Alex", *s2 = "Pereira";

  if (image == NULL) {
    return;
  }

  format = image->format;
  printf("The number of bits per pixel: %lu\n", format->BitsPerPixel);
  printf("The number of bytes per pixel: %lu\n", format->BytesPerPixel);
  printf("Rmask: %lu\nGmask: %lu\nBmask: %lu\nAmask: %lu\n", format->Rmask, format->Gmask, format->Bmask, format->Amask);
  printf("Rmask in binary is: %s\n", uint32_to_bit_string(dest, format->Rmask));
  dest[0] = '\0';
  printf("Gmask in binary is: %s\n", uint32_to_bit_string(dest, format->Gmask));
  dest[0] = '\0';
  printf("Bmask in binary is: %s\n", uint32_to_bit_string(dest, format->Bmask));
  dest[0] = '\0';
  printf("Amask in binary is: %s\n", uint32_to_bit_string(dest, format->Amask));
  dest[0] = '\0';
}