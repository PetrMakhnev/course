#include "button_.h"

void Button_::render()
{
	if (!display) {
		SDL_Rect clearRect = *sizes;
		clearRect.x--;
		clearRect.y--;
		clearRect.w += 2;
		clearRect.h += 2;

		SDL_SetRenderDrawColor(renderer, Colors.background.r, Colors.background.g, Colors.background.b, Colors.background.a);

		SDL_RenderFillRect(renderer, &clearRect);
		SDL_RenderPresent(renderer);
		return;
	}

	SDL_Texture* textTexture;
	SDL_Surface* textSurface;
	SDL_Rect textRect;

	// Отрисовка обводки
	{
		SDL_Rect border = *sizes;
		border.x--;
		border.y--;
		border.w += 2;
		border.h += 2;

		if (click && !block)
			SDL_SetRenderDrawColor(renderer, Colors.element_border_click.r, Colors.element_border_click.g, Colors.element_border_click.b, Colors.element_border_click.a);
		else
			SDL_SetRenderDrawColor(renderer, Colors.element_border.r, Colors.element_border.g, Colors.element_border.b, Colors.element_border.a);

		SDL_RenderFillRect(renderer, &border);
	}
	// Отрисовка заднего фона в зависимости от состояния
	{
		if (block)
			SDL_SetRenderDrawColor(renderer, Colors.element_blocked.r, Colors.element_blocked.g, Colors.element_blocked.b, Colors.element_blocked.a);
		else
			if (click)
				SDL_SetRenderDrawColor(renderer, Colors.element_background_click.r, Colors.element_background_click.g, Colors.element_background_click.b, Colors.element_background_click.a);
			else
				SDL_SetRenderDrawColor(renderer, Colors.element_background.r, Colors.element_background.g, Colors.element_background.b, Colors.element_background.a);

		SDL_RenderFillRect(renderer, sizes);
	}
	// Отрисовка текста в кнопке
	{
		textSurface = TTF_RenderUTF8_Blended(font, text.c_str(), Colors.element_text);
		textRect.w = textSurface->w;
		textRect.h = textSurface->h;
		textRect.x = sizes->x + sizes->w / 2 - textSurface->w / 2;
		textRect.y = sizes->y + sizes->h / 2 - textSurface->h / 1.888;

		textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
		SDL_FreeSurface(textSurface);
	}

	SDL_RenderPresent(renderer);
}
