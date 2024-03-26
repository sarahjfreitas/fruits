#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
//#include <GL/glew.h>

#include "sprite.h"
#include "player.h"
#include "fruit.h"
#include "background.h"
#include "config.h"

using std::vector;
using std::runtime_error;


class Game
{
  public:
    Game();
    ~Game();

    void handleEvents();
    void update();
    void render() const;
    bool isRunning() const { return running; };

  private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    bool running = true;

    // TODO: temp vars, move this
    int currentStep = 0;
    int speed = 200;
    int stepToGenerateFruit = 0;

    Player player;
    Background background;
    vector<std::unique_ptr<Fruit>> fruits;
    vector<std::unique_ptr<Fruit>> fruitsOnTheFloor;

    void limitFrameRate(Uint32 const& frameStart);
    void initSdl(string windowTitle);
    void initOpenGl();
};
