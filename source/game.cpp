#include "game.h"

/// @brief Initialize libraries and create window
Game::Game()
{
  initSdl("Fruit Catcher");
  //initOpenGl(); TODO: change sdl image to open gl
}

/// @brief Destructor that clears remaining pointers
Game::~Game() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

/// @brief Handle user input
void Game::handleEvents()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:
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
        break;
    }
  }
}

/// @brief Update game state on each frame
void Game::update()
{
  Uint32 frameStart = SDL_GetTicks();

  currentStep++;
  if(currentStep > speed){
    currentStep = 0;
    stepToGenerateFruit = rand() % speed;
  }

  if(currentStep == stepToGenerateFruit && fruits.size() < 20)
    fruits.push_back(Fruit::generateRandom());

  //remove fruits that are out of the screen

  fruits.erase(std::remove_if(fruits.begin(), fruits.end(), [this](std::unique_ptr<Fruit>& fruit) { 
    if (fruit->isOutOfBounds())
    {
      player.takeDamage();
      fruitsOnTheFloor.push_back(std::move(fruit));
      return true;
    }
    if (checkColision(player.collider, fruit->collider))
    {
      player.increaseScore();
      return true;
    }

    return false; // keep the fruit
  }), fruits.end());

  if (!player.isAlive())
  {
    running = false;
  }

  if(currentStep == rand() % speed && fruits.size() < 10)
    std::generate_n(std::back_inserter(fruits), 1, [this]() { return Fruit::generateRandom(); });

  limitFrameRate(frameStart);

  player.update();
  for(auto& fruit : fruits)
  {
    fruit->fall(speed / 50);
  }
}

/// @brief Draw the window surface
void Game::render() const
{
  SDL_RenderClear(renderer);

  background.draw(renderer);
  player.draw(renderer);
  for(auto& fruit : fruits)
  {
    fruit->draw(renderer);
  }
  for (auto& fruit : fruitsOnTheFloor)
  {
    fruit->draw(renderer);
  }

  SDL_RenderPresent(renderer);
}

/// @brief Limit the frame rate acording to the FPS configuration
/// @param frameStart Time that current frame started
void Game::limitFrameRate(Uint32 const& frameStart)
{
  int frameDuration = SDL_GetTicks() - frameStart;
  if(frameDelay > frameDuration)
  {
    SDL_Delay(frameDelay - frameDuration);
  }
}

/// @brief Initialize SDL and create window
void Game::initSdl(string windowTitle)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    throw std::runtime_error(SDL_GetError());
  }

  window = SDL_CreateWindow(
    windowTitle.c_str(),
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    windowWidth, windowHeight, SDL_WINDOW_FULLSCREEN_DESKTOP
  );

  if(window == nullptr)
  {
    throw std::runtime_error(SDL_GetError());
  }

  renderer = SDL_CreateRenderer(window, -1, 0);
  if(renderer == nullptr)
  {
    throw std::runtime_error(SDL_GetError());
  }

  SDL_RenderSetLogicalSize(renderer, windowWidth, windowHeight);
}

/// @brief Initialize OpenGL
void Game::initOpenGl()
{
  /*SDL_GLContext glContext = SDL_GL_CreateContext(window);
  if(glContext == nullptr)
  {
    throw std::runtime_error(SDL_GetError());
  }

  GLenum glewError = glewInit();
  if (glewError != GLEW_OK)
  {
    throw std::runtime_error(reinterpret_cast<const char*>(glewGetErrorString(glewError)));
  }*/
}
