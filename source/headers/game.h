#pragma once
#include <SDL.h>
#include <vector>
#include <algorithm>

#include "sprite.h"
#include "player.h"
#include "fruit.h"

using std::vector;


class Game
{
  private:
    SDL_Window* window;
    SDL_Surface* windowSurface;
    SDL_Event event;

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Player player;
    vector<Fruit> fruits;

    void handleKeyInput();
    void draw();
    void limitFrameRate(Uint32 frameStart);

  public:
    Game() {};
    ~Game();

    void init();
    void run();
};
