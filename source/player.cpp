#include "player.h"

Player::Player() : Sprite(300, 670, 128, 192) {
  setImage(imagePath);
  for (int i = 1; i <= hp; i++)
  {
    lifes.push_back(Hp(i));
  }
}

void Player::walkRight()
{

  move(10, 0);
}

void Player::walkLeft()
{
  move(-10,0);
}

void Player::takeDamage()
{
  hp--;
  if (!lifes.empty())
  {
    lifes.pop_back();
  }
}

void Player::draw(SDL_Renderer* renderer) const
{
  for (auto const& life : lifes)
  {
    life.draw(renderer);
  }
  Sprite::draw(renderer);
}
