#include "Label.h"

Label::Label(SDL_Renderer* _renderer, SDL_Rect* _sizes, int _type, string _new_string, const char* _font, int _font_size) : Control(_renderer, _sizes, _font, _font_size)
{
	renderer = _renderer;
	display = true;
	sizes = _sizes;

	type = _type;
	label = _new_string;
	font = TTF_OpenFont(_font, _font_size);
};

void Label::render()
{
	if (!display) {
		SDL_SetRenderDrawColor(renderer, Colors.background.r, Colors.background.g, Colors.background.b, Colors.background.a);
		SDL_Rect clearRect = *sizes;
		clearRect.w = 160;
		SDL_RenderFillRect(renderer, &clearRect);
		return;
	}
	
	SDL_Texture* textTexture = nullptr;
	SDL_Surface* textSurface = nullptr;

	SDL_SetRenderDrawColor(renderer, Colors.background.r, Colors.background.g, Colors.background.b, Colors.background.a);
	SDL_Rect clearRect = *sizes;
	clearRect.w = 160;
	SDL_RenderFillRect(renderer, &clearRect);

	if ((textSurface = TTF_RenderUTF8_Blended(font, label.c_str(), Colors.element_text)) != nullptr) {
		sizes->w = textSurface->w;
		sizes->h = textSurface->h;

		if (type == BY_RIGHT)
			sizes->x -= sizes->w - 10;
		else if (type == BY_LEFT)
			sizes->x = sizes->x;

		sizes->y += sizes->h / 2 - textSurface->h / 2.8;

		textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		SDL_RenderCopy(renderer, textTexture, NULL, sizes);
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
