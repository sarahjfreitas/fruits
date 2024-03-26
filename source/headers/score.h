#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <stdexcept>
#include <iostream>

using std::string;
using std::to_string;
using std::runtime_error;
using std::cout;
using std::endl;

class Score
{
  public:
    Score();
    void increaseScore() {score++;};
    void resetScore() {score = 0;};
    void draw(SDL_Renderer* renderer) const;

  private:
    int score = 0;
    SDL_Color const textColor = { 255, 255, 255 };
};