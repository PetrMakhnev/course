#include "Label.h"

Label::Label(SDL_Renderer* _renderer, SDL_Rect* _coord, int _type, string newString, const char* _font, int _font_size)
{ 
	renderer = _renderer;
	display = true;
	textTexture = nullptr;
	textSurface = nullptr;
	coord = *_coord;
	
	type = _type;
	label = newString;
	font = TTF_OpenFont(_font, _font_size);

}

void Label::render()
{
	if (!display) {
		SDL_SetRenderDrawColor(renderer, Colors.background.r, Colors.background.g, Colors.background.b, Colors.background.a);
		SDL_Rect clearRect = textRect;
		clearRect.w = 160;
		SDL_RenderFillRect(renderer, &clearRect);
		return;
	}
		
	SDL_SetRenderDrawColor(renderer, Colors.background.r, Colors.background.g, Colors.background.b, Colors.background.a);
	SDL_Rect clearRect = textRect;
	clearRect.w = 160;
	SDL_RenderFillRect(renderer, &clearRect);

	if ((textSurface = TTF_RenderUTF8_Blended(font, label.c_str(), Colors.element_text)) != nullptr) {
		textRect.w = textSurface->w;
		textRect.h = textSurface->h;
		if (type == BY_RIGHT)
			textRect.x = coord.x - textSurface->w - 10;
		else if (type == BY_LEFT)
			textRect.x = coord.x;

		textRect.y = coord.y + coord.h / 2 - textSurface->h / 2;

		textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
		SDL_FreeSurface(textSurface);
		SDL_DestroyTexture(textTexture);
		SDL_RenderPresent(renderer);
	}
}

void Label::show(bool value)
{
	display = value;
}

void Label::setText(string text)
{
	label = text;
}
