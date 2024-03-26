#include "player.h"
#include "config.h"

Player::Player() : Sprite(300, floorHeight - playerHeigh, 128, playerHeigh) {
  setImage(imagePath);

  int i = 1;
  generate_n(back_inserter(lifes), hp, [&i]() { return Hp(i++); });
}

void Player::walkRight()
{
  move(playerWalkSpeed, 0);
  if (isOutOfBounds())
  {
    move(playerWalkSpeed * -1, 0);
  }
}

void Player::walkLeft()
{
  move(playerWalkSpeed * -1, 0);
  if (isOutOfBounds())
  {
    move(playerWalkSpeed, 0);
  }
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
  score.draw(renderer);
  Sprite::draw(renderer);
}