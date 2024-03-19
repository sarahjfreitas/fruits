#include "fruit.h"

const int Fruit::startingHeight;

Fruit::Fruit(int x, int y) : Sprite(x, y),  selectedImagePath(imagePaths[rand() % imagePaths.size()]) {
  setImage(selectedImagePath);
}

void Fruit::fall() {
  move(0, 1);
}

std::unique_ptr<Fruit> Fruit::generateRandom(const int& windowWidth) {
  return std::make_unique<Fruit>(rand() % windowWidth, startingHeight);
}
