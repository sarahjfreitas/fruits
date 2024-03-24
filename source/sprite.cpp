#include "sprite.h"
#include <iostream>

using std::cout;
using std::endl;

/// @brief Construct a new Sprite:: Sprite object
/// @param x x position
/// @param y y position
Sprite::Sprite(int x, int y, int w, int h) : w(w), h(h)
{
  setPosition(x, y);
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
    SDL_QueryTexture(texture, nullptr, nullptr, nullptr, nullptr);
    SDL_RenderCopy(renderer, texture, nullptr, &collider);
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
  position.x += x;
  position.y += y;
  update();
}

void Sprite::setPosition(int x, int y)
{
  position.x = x;
  position.y = y;
  update();
}

void Sprite::update()
{
  collider.x = position.x;
  collider.y = position.y;
  collider.w = w;
  collider.h = h;
}

bool Sprite::isOutOfBounds() const
{
  return position.x < 0 || position.x > windowWidth || position.y < 0 || position.y > windowHeight;
}


bool checkColision(SDL_Rect const& a, SDL_Rect const& b)
{
  // a coords
  int aLeft = a.x;
  int aRight = a.x + a.w;
  int aTop = a.y;
  int aBottom = a.y + a.h;

  // b coords
  int bLeft = b.x;
  int bRight = b.x + b.w;
  int bTop = b.y;
  int bBottom = b.y + b.h;

  bool ARightOfB = aLeft > bRight;
  bool ALeftOfB = aRight < bLeft;
  bool AAboveB = aBottom < bTop;
  bool ABelowB = aTop > bBottom;
  
  if (ARightOfB || ALeftOfB || AAboveB || ABelowB)
  {
    return false;
  }

  return true;
}

void Sprite::setSize(int w, int h)
{
  this->w = w;
  this->h = h;
};