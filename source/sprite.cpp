#include "sprite.h"
#include <iostream>

using std::cout;
using std::endl;

/// @brief Construct a new Sprite:: Sprite object
/// @param x x position
/// @param y y position
Sprite::Sprite(int x, int y) : x(x), y(y)
{
  surface = SDL_CreateRGBSurface(0, 10, 10, 32, 0, 0, 0, 0);
  if(surface == NULL) throw std::runtime_error(SDL_GetError());

  SDL_FillRect(surface, NULL, 0x000000);
  update();
}

Sprite& Sprite::operator=(const Sprite& other)
{
  if(this != &other)
  {
    x = other.x;
    y = other.y;
    rect = other.rect;
    surface = other.surface;
  }

  return *this;
}

/// @brief Draw the sprite
/// @param destination The surface to be drawn into
void Sprite::draw(SDL_Surface *destination)
{
  SDL_BlitSurface(surface, NULL, destination, &rect);
}

/// @brief Set the sprite background image
/// @param filename path to the image to be used
/// @param x x position
/// @param y y postion
void Sprite::setImage(string filename)
{
  surface = IMG_Load(filename.c_str());
  if(surface == NULL) throw std::runtime_error(SDL_GetError());
  update();
}

void Sprite::move(int x, int y)
{
  this->x += x;
  this->y += y;
  update();
}

void Sprite::setPosition(int x, int y)
{
  this->x = x;
  this->y = y;
  update();
}

void Sprite::update()
{
  rect = surface->clip_rect;
  rect.x = x;
  rect.y = y;
}

bool Sprite::isOutOfBounds(int windowWidth, int windowHeight)
{
  return x < 0 || x > windowWidth || y < 0 || y > windowHeight;
}
