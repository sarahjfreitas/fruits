#pragma once
#include <SDL.h>

class Sprite {
  private:
    SDL_Surface *image;
    SDL_Rect rect;
    int width, height;

  public:
    Sprite(Uint32 color, int w = 48, int h = 64, int x = 0, int y = 0);
    void update() { }; // to be overwritten
    void draw(SDL_Surface *destination);
};
