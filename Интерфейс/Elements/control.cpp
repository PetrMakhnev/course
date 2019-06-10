#include "control.h"

Control::Control(SDL_Renderer* _renderer, SDL_Rect* _sizes, string _font, int _font_size)
{
	renderer = _renderer;
	block = false;
	sizes = _sizes;
	font_size = _font_size;
	display = true;
	click = false;
	font = TTF_OpenFont(_font.c_str(), _font_size);
}

void Control::render()
{
	// virtual
}

void Control::renderLabel(string text, SDL_Rect* renderRect, int type)
{

	SDL_Texture* textTexture = nullptr;
	SDL_Surface* textSurface = nullptr;
	SDL_Rect textRect;

	if ((textSurface = TTF_RenderUTF8_Blended(font, text.c_str(), Colors.element_text)) != nullptr) {
		textRect.w = textSurface->w;
		textRect.h = textSurface->h;
		
		if (type == LEFT_ALIGN)
			textRect.x = renderRect->x + 10;
		else if (type == CENTERED_ALIGN)
			textRect.x = renderRect->x + renderRect->w / 2 - textSurface->w / 2;

		textRect.y = renderRect->y + renderRect->h / 2 - textSurface->h / 1.88;

		textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
		SDL_FreeSurface(textSurface);
		SDL_DestroyTexture(textTexture);
	}


	SDL_RenderPresent(renderer);
}

void Control::unlock()
{
	block = false;
}

void Control::blocked()
{
	block = true;
}

void Control::hide()
{
	display = false;
}

void Control::show()
{
	display = true;
}

void Control::Click(bool value)
{
	click = value;
}

bool Control::getShow()
{
	return display;
}

bool Control::checkHover(int _x, int _y)
{
	SDL_Point point = { _x, _y };
	if (!block && display)
		return SDL_PointInRect(&point, sizes);
	return false;
}

void Control::onEvent(SDL_Event* event)
{
	// virtual
}
