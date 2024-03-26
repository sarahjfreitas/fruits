#include "score.h"

Score::Score()
{}

void Score::draw(SDL_Renderer* renderer) const
{

  TTF_Font* textFont = TTF_OpenFont("fonts/Minimal5x7.ttf", 64);
  if (textFont == nullptr)
  {
    cout << "Failed to load font! SDL_ttf Error: " << string(TTF_GetError());
    return;
  }
  SDL_Color textColor = { 255, 255, 255 };
  string scoreText = "Score: " + to_string(score);

  SDL_Surface* textSurface = TTF_RenderText_Solid(textFont, scoreText.c_str(), textColor);
  if(textSurface == nullptr)
  {
    cout << "Unable to render score text surface! SDL_ttf Error: " << TTF_GetError() << endl;
    return;
  }

  SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
  if(textTexture == nullptr)
  {
    cout << "Unable to create texture from rendered score text! SDL Error: " << SDL_GetError() << endl;
    return;
  }

  int textWidth = textSurface->w;
  int textHeight = textSurface->h;

  SDL_QueryTexture(textTexture, nullptr, nullptr, &textWidth, &textHeight);
  SDL_Rect dstrect = { 1300, 64, textWidth, textHeight };
  SDL_RenderCopy(renderer, textTexture, NULL, &dstrect);

  SDL_FreeSurface(textSurface);
  TTF_CloseFont(textFont);
}