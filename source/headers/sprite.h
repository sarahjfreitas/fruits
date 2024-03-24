#pragma once
#include <SDL.h>
#include <SDL_Image.h>
#include <string>

using std::string;

class Sprite {
  private:
    int w, h;
    string imageFilename;
    SDL_Point position;

  protected:
    void setImage(string const& filename);
    void move(int x, int y);
    void setPosition(int x, int y);
    void genericDraw(SDL_Renderer* renderer, bool fullScreen) const;
    void setSize(int w, int h);

  public:
    Sprite(int x = 0, int y = 0, int w = 0, int h = 0);
    void update();
    virtual void draw(SDL_Renderer *renderer) const;
    bool isOutOfBounds(int const& windowWidth, int const& windowHeight) const;
    SDL_Rect collider;
};

bool checkColision(SDL_Rect const& a, SDL_Rect const& b);