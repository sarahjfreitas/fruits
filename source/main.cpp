#include <iostream>
#include "game.h"


int main(int argc, char* argv[])
{
  try
  {
    Game game;

    while (game.isRunning())
    {
      game.handleEvents();
      game.update();
      game.render();
    }
  }
  catch(const std::runtime_error& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
