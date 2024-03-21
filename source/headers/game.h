#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include <memory>
#include <SDL.h>
#include <stdexcept>
//#include <GL/glew.h>

#include "sprite.h"
#include "player.h"
#include "fruit.h"

using std::vector;


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

    int const FPS = 60;
    int const frameDelay = 1000 / FPS;
    int const windowWidth = 1600;
    int const windowHeight = 1024;

    bool running = true;

    // temp
    int currentStep = 0;
    int speed = 50;
    int stepToGenerateFruit = 0;


    Player player;
    vector<std::unique_ptr<Fruit>> fruits;

    void limitFrameRate(Uint32 const& frameStart);
    void initSdl(string windowTitle);
    void initOpenGl();
};
