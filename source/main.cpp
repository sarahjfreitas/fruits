#include <iostream>
#include "game.h"


int main(int argc, char* argv[])
{
  try
  {
    Game game;
    game.init();
    game.run();
  }
  catch(const std::runtime_error& e)
  {
    std::cerr << e.what() << std::endl;
  }
}
