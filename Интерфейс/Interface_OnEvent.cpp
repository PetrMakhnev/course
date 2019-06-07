#include "app.h"

void Interface::onEvent()
{
	while (running) {
		while (SDL_PollEvent(&event)) {

			switch (event.type)
			{

			case SDL_MOUSEMOTION:
				mouseMotion(&event);
				break;

			case SDL_MOUSEBUTTONDOWN:
				mouseButtonDown(&event);
				break;

			case SDL_MOUSEBUTTONUP:
				mouseButtonUp(&event);
				break;

			case SDL_QUIT:
				quit();
				break;

			case SDL_KEYDOWN:
				keyDown(&event);
				break;

			default: break;
			}
		}
	}
}
