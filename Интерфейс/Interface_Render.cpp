#include "app.h"

void Interface::render()
{

	SDL_SetRenderDrawColor(renderer, Colors.background.r, Colors.background.g, Colors.background.b, Colors.background.a);
	SDL_RenderFillRect(renderer, NULL);

	SDL_RenderPresent(renderer);


	for (int i = 0; i < Buttons.size(); i++) {
		Buttons.at(i)->render();
	}

	for (int i = 0; i < ItemLists.size(); i++) {
		ItemLists.at(i)->render();
	}

	for (int i = 0; i < Labels.size(); i++) {
		Labels.at(i)->render();
	}

	for (int i = 0; i < DropDownLists.size(); i++) {
		DropDownLists.at(i)->render();
	}

	for (int i = 0; i < TextFields.size(); i++) {
		TextFields.at(i)->render();
	}

	for (int i = 0; i < Inputs.size(); i++) {
		Inputs.at(i)->render();
	}
	
}
