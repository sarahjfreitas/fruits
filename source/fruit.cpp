#include "fruit.h"

Fruit::Fruit(int x, int y) : Sprite(x, y) {
  int randomIndex = rand() % imagePaths.size();
  selectedImagePath = imagePaths[randomIndex];
  setImage(selectedImagePath);
}

Fruit& Fruit::operator=(const Fruit& other) {
  if (this != &other) {
    Sprite::operator=(other);
    selectedImagePath = other.selectedImagePath;
    setImage(selectedImagePath);
  }

  return *this;
}

void Fruit::fall() {
  move(0, 1);
}

Fruit Fruit::generateRandom(int windowWidth) {
  return Fruit(rand() % windowWidth, 0);
}
