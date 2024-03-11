#include "headers/sprite.h"

/// @brief Construct a new Sprite:: Sprite object
/// @param color Color of the sprite
/// @param w widht
/// @param h height
/// @param x x position
/// @param y y position
Sprite::Sprite(Uint32 color, int w, int h, int x, int y) : width(w), height(h)
{
  image = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
  SDL_FillRect(image, NULL, color);

  rect = image->clip_rect;
  rect.x = x;
  rect.y = y;
}

/// @brief Draw the sprite
/// @param destination The surface to be drawn into
void Sprite::draw(SDL_Surface *destination)
{
  SDL_BlitSurface(image, NULL, destination, &rect);
}


