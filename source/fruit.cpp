#include "fruit.h"

Fruit::Fruit(int x, int y) : Sprite(x, y, 32, 32),  selectedImagePath(imagePaths[rand() % imagePaths.size()]) {
  setImage(selectedImagePath);
}

void Fruit::fall(int speed) {
  move(0, speed);
}

std::unique_ptr<Fruit> Fruit::generateRandom() {
  return std::make_unique<Fruit>(rand() % (windowWidth - 32), startingHeight);
}
