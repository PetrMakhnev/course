#include "input_.h"

void Input_::render()
{
	if (!display) {
		SDL_Rect* clearRect = sizes;

		clearRect->x--;
		clearRect->y--; clearRect;
		clearRect->w += 2;
		clearRect->h += 2;

		SDL_SetRenderDrawColor(renderer, Colors.background.r, Colors.background.g, Colors.background.b, Colors.background.a);

		SDL_RenderFillRect(renderer, clearRect);

		return;
	}
		

	// Отрисовка обводки
	{
		SDL_Rect border = *sizes;
		border.x--;
		border.y--;
		border.w += 2;
		border.h += 2;

		if (focus && !block)
			SDL_SetRenderDrawColor(renderer, Colors.element_border_click.r, Colors.element_border_click.g, Colors.element_border_click.b, Colors.element_border_click.a);
		else
			SDL_SetRenderDrawColor(renderer, Colors.element_border.r, Colors.element_border.g, Colors.element_border.b, Colors.element_border.a);

		SDL_RenderFillRect(renderer, &border);
	}
	// Отрисовка заднего фона в зависимости от состояния
	{
		if (focus && !block)
			SDL_SetRenderDrawColor(renderer, Colors.element_background_focus.r, Colors.element_background_focus.g, Colors.element_background_focus.b, Colors.element_background_focus.a);
		else {
			if (block)
				SDL_SetRenderDrawColor(renderer, Colors.element_blocked.r, Colors.element_blocked.g, Colors.element_blocked.b, Colors.element_blocked.a);
			else
				SDL_SetRenderDrawColor(renderer, Colors.element_background_unfocus.r, Colors.element_background_unfocus.g, Colors.element_background_unfocus.b, Colors.element_background_unfocus.a);
		}
	}


	SDL_RenderFillRect(renderer, sizes);

	renderLabel(inputText, sizes, LEFT_ALIGN);
}

void Input_::onEvent(SDL_Event* event) 
{
	while (focus) {
		SDL_StartTextInput();
		while (SDL_PollEvent(event)) {
			switch (event->type)
			{

			case SDL_KEYDOWN:
			{
				if (event->key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0)
					inputText.pop_back();
				else if (event->key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL)
					SDL_SetClipboardText(inputText.c_str());
				else if (event->key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL)
					inputText = SDL_GetClipboardText();

				break;
			}

			case SDL_TEXTINPUT:
				if (!((event->text.text[0] == 'c' || event->text.text[0] == 'C') && (event->text.text[0] == 'v' || event->text.text[0] == 'V') && SDL_GetModState() & KMOD_CTRL))
					if (inputText.size() * (font_size - 2) + 10 < sizes->w)
						inputText += event->text.text;
					
				break;

			case SDL_MOUSEBUTTONDOWN:
			{
				int x, y;
				SDL_GetMouseState(&x, &y);

				SDL_Point point = { x, y };

				if (!SDL_PointInRect(&point, sizes))
					focus = false;
				render();
				break;
			}

			}
			render();
		}
	}
	SDL_StopTextInput();
}

void Input_::clear()
{
	inputText = "";
}

string Input_::getValue()
{
	return inputText;
}

void Input_::Focus(bool value)
{
	focus = value;
}