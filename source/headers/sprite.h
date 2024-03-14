#pragma once
#include <SDL.h>
#include <SDL_Image.h>
#include <string>

using std::string;

class Sprite {
  private:
    SDL_Surface *surface;
    SDL_Rect rect;
    int x, y;

  protected:
    void setImage(string filename);
    void move(int x, int y);
    void setPosition(int x, int y);

  public:
    Sprite(int x = 0, int y = 0);
    Sprite& operator=(const Sprite& other);
    void update();
    void draw(SDL_Surface *destination);
    bool isOutOfBounds(int windowWidth, int windowHeight);
};
