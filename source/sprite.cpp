#include "sprite.h"
#include <iostream>

using std::cout;
using std::endl;

/// @brief Construct a new Sprite:: Sprite object
/// @param x x position
/// @param y y position
Sprite::Sprite(int x, int y) : x(x), y(y)
{
  update();
}

/// @brief Draw the sprite
/// @param destination The surface to be drawn into
void Sprite::draw(SDL_Renderer *renderer) const
{
  if(imageFilename.empty())
  {
    return;
  }

  SDL_Texture* texture = IMG_LoadTexture(renderer, imageFilename.c_str());
  if(texture == nullptr)
  {
    cout << "Failed to load texture: " << imageFilename << endl;
    return;
  }

  SDL_Rect destRect;
  destRect.x = x;
  destRect.y = y;
  destRect.w = 32;
  destRect.h = 32;

  SDL_QueryTexture(texture, nullptr, nullptr, &destRect.w, &destRect.h);
  SDL_RenderCopy(renderer, texture, NULL, &destRect);
  SDL_DestroyTexture(texture);
}

/// @brief Set the sprite background image
/// @param filename path to the image to be used
/// @param x x position
/// @param y y postion
void Sprite::setImage(string const& filename)
{
  imageFilename = filename;
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
{}

bool Sprite::isOutOfBounds(int const& windowWidth, int const& windowHeight) const
{
  return x < 0 || x > windowWidth || y < 0 || y > windowHeight;
}
