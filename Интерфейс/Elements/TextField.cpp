#include "../Elements/TextField.h"

void TextField::add(string newLine)
{
	lines.push_back(newLine);
}

void TextField::render()
{
	SDL_SetRenderDrawColor(renderer, Colors.element_background.r, Colors.element_background.g, Colors.element_background.b, Colors.element_background.a);
	SDL_RenderFillRect(renderer, sizes);

	SDL_Rect rect = { sizes->x + 5, sizes->y + 10, sizes->w - 10, 15 };

	for (size_t i = 0; i < lines.size(); i++) {
		renderLabel(lines.at(i), &rect, LEFT_ALIGN);
		rect.y += 16;
	}


	SDL_RenderPresent(renderer);
}
