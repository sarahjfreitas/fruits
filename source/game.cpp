#include "headers/game.h"

/// @brief Initialize libraries and create window
void Game::init()
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    throw std::runtime_error(SDL_GetError());
  }

  window = SDL_CreateWindow("Fruits!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE);
  if(window == NULL)
  {
    throw std::runtime_error(SDL_GetError());
  }

  windowSurface = SDL_GetWindowSurface(window);
}

/// @brief Main game loop
void Game::run()
{
  //TODO :remove temporary code
  std::generate_n(std::back_inserter(fruits), 10, []() { return Fruit(rand() % 640, rand() % 480); });

  bool running = true;

  while(running)
  {
    Uint32 frameStart = SDL_GetTicks();

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
  for( auto fruit : fruits)
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
