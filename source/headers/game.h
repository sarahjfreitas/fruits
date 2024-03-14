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

    int const FPS = 60;
    int const frameDelay = 1000 / FPS;
    int const windowWidth = 640;
    int const windowHeight = 480;

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
