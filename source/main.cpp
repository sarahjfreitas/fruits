#include <iostream>
#include <SDL.h>
#include <vector>
#include "headers/sprite.h"
#include "headers/player.h"
#include "headers/fruit.h"

using std::cout;
using std::vector;

int main(int argc, char* argv[])
{
  SDL_Window* window;
  const int FPS = 60;

  // initialize
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    cout << "SDL_Init Error: " << SDL_GetError() << "\n";
    return 1;
  }

  // create window
  window = SDL_CreateWindow("Fruits!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE);
  if(window == NULL)
  {
    cout << "SDL_CreateWindow Error: " << SDL_GetError() << "\n";
    SDL_Quit();
    return 1;
  }

  Uint32 red = SDL_MapRGB(SDL_GetWindowSurface(window)->format, 255, 0, 0);
  Uint32 white = SDL_MapRGB(SDL_GetWindowSurface(window)->format, 255, 255, 255);

  SDL_Surface* windowSurface = SDL_GetWindowSurface(window);

  vector<Fruit> fruits;
  for (int i = 0; i < 10; i++)
  {
    int x = rand() % 640;
    int y = rand() % 480;
    Fruit fruit(x, y);
    fruits.push_back(fruit);
  }

  Player player;

  // keeep window open
  SDL_Event event;
  bool running = true;
  const int frameDelay = 1000 / FPS;
  Uint32 frameStart;

  while(running)
  {
    frameStart = SDL_GetTicks();

    // handle events and input
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
        case SDL_QUIT:
          running = false;
          break;
        case SDL_KEYDOWN:
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

    // draw
    SDL_FillRect(windowSurface, NULL, 0x000000);
    player.draw(windowSurface);
    for( auto fruit : fruits)
    {
      fruit.fall();
      fruit.draw(windowSurface);
    }
    SDL_UpdateWindowSurface(window);

    // Limit frame rate
    int frameDuration = SDL_GetTicks() - frameStart;
    if(frameDelay > frameDuration)
    {
      SDL_Delay(frameDelay - frameDuration);
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
