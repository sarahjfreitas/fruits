#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include "sprite.h"
#include "fruit.h"
#include "hp.h"

using std::vector;
using std::generate_n;
using std::back_inserter;

class Player : public Sprite
{
  private:
    string const imagePath = "assets/player.png";
    int hp = playerMaxHp;
    int score = 0;
    vector<Hp> lifes;

  public:
    Player();
    void walkRight();
    void walkLeft();
    void takeDamage();
    bool isAlive() const { return hp > 0; };
    void increaseScore() { score++; };
    int getScore() const { return score; };
    void draw(SDL_Renderer* renderer) const override;
};
