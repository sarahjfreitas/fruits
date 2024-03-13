#include "headers/fruit.h"

Fruit::Fruit(int x, int y) : Sprite(x, y) {
  int randomIndex = rand() % imagePaths.size();
  setImage(imagePaths[randomIndex]);
}

void Fruit::fall() {
  move(0, 1);
}
