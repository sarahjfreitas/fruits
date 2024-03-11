#include <iostream>
#include <SDL.h>
#include "headers/sprite.h"

using std::cout;

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
  SDL_Surface* windowSurface = SDL_GetWindowSurface(window);

  Sprite sprite(red, 100, 100, 100, 240);
  sprite.draw(windowSurface);

  // keeep window open
  SDL_Event event;
  bool running = true;
  const int frameDelay = 1000 / FPS;
  Uint32 frameStart;

  while(running)
  {
    frameStart = SDL_GetTicks();
    SDL_UpdateWindowSurface(window);

    if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
      running = false;

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
