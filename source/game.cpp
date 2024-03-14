#include "game.h"

/// @brief Initialize libraries and create window
void Game::init()
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    throw std::runtime_error(SDL_GetError());
  }

  window = SDL_CreateWindow("Fruits!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_RESIZABLE);
  if(window == NULL)
  {
    throw std::runtime_error(SDL_GetError());
  }

  windowSurface = SDL_GetWindowSurface(window);
}

/// @brief Main game loop
void Game::run()
{
  bool running = true;
  int currentStep = 0;
  int speed = 50;
  int stepToGenerateFruit = 0;

  while(running)
  {
    currentStep++;
    if(currentStep > speed){
      currentStep = 0;
      stepToGenerateFruit = rand() % speed;
    }

    if(currentStep == stepToGenerateFruit && fruits.size() < 10)
      fruits.push_back(Fruit::generateRandom(windowWidth));


    Uint32 frameStart = SDL_GetTicks();

    //remove fruits that are out of the screen
    fruits.erase(std::remove_if(fruits.begin(), fruits.end(), [this](Fruit& fruit) { return fruit.isOutOfBounds(windowWidth, windowHeight); }), fruits.end());

    if(currentStep == rand() % speed && fruits.size() < 10)
      std::generate_n(std::back_inserter(fruits), 1, [this]() { return Fruit::generateRandom(windowWidth); });

    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
        case SDL_QUIT:
          running = false;
          break;
        case SDL_KEYDOWN:
          handleKeyInput();
          break;
      }
    }

    draw();
    limitFrameRate(frameStart);
  }
}

/// @brief Handle user input
void Game::handleKeyInput()
{
  //TODO: make sure that player can only walk once per frame
  switch (event.key.keysym.sym)
  {
    case SDLK_RIGHT:
      player.walkRight();
      break;
    case SDLK_LEFT:
      player.walkLeft();
      break;
  }
}

/// @brief Draw the window surface
void Game::draw()
{
  SDL_FillRect(windowSurface, NULL, 0x000000); // clear the window

  player.draw(windowSurface);
  for( auto& fruit : fruits)
  {
    fruit.fall();
    fruit.draw(windowSurface);
  }

  SDL_UpdateWindowSurface(window);
}

/// @brief Limit the frame rate acording to the FPS configuration
/// @param frameStart Time that current frame started
void Game::limitFrameRate(Uint32 frameStart)
{
  int frameDuration = SDL_GetTicks() - frameStart;
  if(frameDelay > frameDuration)
  {
    SDL_Delay(frameDelay - frameDuration);
  }
}

/// @brief Destructor that clears remaining pointers
Game::~Game() {
  SDL_FreeSurface(windowSurface);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
