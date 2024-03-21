#include "background.h"

Background::Background() : Sprite() {
  setImage(imagePath);
}

void Background::draw(SDL_Renderer* renderer) const
{
  Sprite::genericDraw(renderer, true);
}