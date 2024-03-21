#pragma once
#include <SDL.h>
#include <SDL_Image.h>
#include <string>

using std::string;

class Sprite {
  private:
    int x, y, w, h;
    string imageFilename;

  protected:
    void setImage(string const& filename);
    void move(int x, int y);
    void setPosition(int x, int y);
    void genericDraw(SDL_Renderer* renderer, bool fullScreen) const;

  public:
    Sprite(int x = 0, int y = 0, int w = 0, int h = 0);
    void update();
    void draw(SDL_Renderer *renderer) const;
    bool isOutOfBounds(int const& windowWidth, int const& windowHeight) const;
};
