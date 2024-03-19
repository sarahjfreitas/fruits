#pragma once
#include <SDL.h>
#include <vector>
#include <algorithm>
#include <memory>

#include "sprite.h"
#include "player.h"
#include "fruit.h"

using std::vector;


class Game
{
  private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    int const FPS = 60;
    int const frameDelay = 1000 / FPS;
    int const windowWidth = 640;
    int const windowHeight = 480;

    bool running = true;

    // temp
    int currentStep = 0;
    int speed = 50;
    int stepToGenerateFruit = 0;


    Player player;
    vector<std::unique_ptr<Fruit>> fruits;

    void limitFrameRate(Uint32 const& frameStart);

  public:
    Game();
    ~Game();

    void handleEvents();
    void update();
    void render() const;
    bool isRunning() const { return running; };
};
