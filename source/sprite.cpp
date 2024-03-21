#include "sprite.h"
#include <iostream>

using std::cout;
using std::endl;

/// @brief Construct a new Sprite:: Sprite object
/// @param x x position
/// @param y y position
Sprite::Sprite(int x, int y, int w, int h) : x(x), y(y), w(w), h(h)
{
  update();
}

/// @brief Draw the sprite
/// @param destination The surface to be drawn into
void Sprite::draw(SDL_Renderer *renderer) const
{
  genericDraw(renderer, false);
}

void Sprite::genericDraw(SDL_Renderer* renderer, bool fullScreen) const
{
  if (imageFilename.empty())
  {
    return;
  }

  SDL_Texture* texture = IMG_LoadTexture(renderer, imageFilename.c_str());
  if (texture == nullptr)
  {
    cout << "Failed to load texture: " << imageFilename << endl;
    return;
  }


  if (fullScreen) {
    SDL_QueryTexture(texture, nullptr, nullptr, nullptr, nullptr);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
  }
  else {
    SDL_Rect destRect;
    destRect.x = x;
    destRect.y = y;
    destRect.w = w;
    destRect.h = h;

    SDL_QueryTexture(texture, nullptr, nullptr, &destRect.w, &destRect.h);
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
  }

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
