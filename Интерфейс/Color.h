#pragma once
#include "SDL.h"

struct COLOR {
	COLOR() {
		background = { 0xF0, 0xF0, 0xF0, 0x00 };
		element_blocked = { 0xA0, 0xA0, 0xA0, 0x00 };
		element_border = { 0xAD, 0xAD, 0xAD, 0x00 };
		element_background_click = { 0xE5, 0xF1, 0xFB, 0x00 };
		element_background_focus = { 0xFD, 0xFD, 0xFD, 0x00 };
		element_background_unfocus = { 0xFD, 0xFD, 0xFD, 0x00 };
		element_border_click = { 0x50, 0xA0, 0xDF, 0x00 };
		element_list_hover = { 0x50, 0xA0, 0xDF, 0x00 };
		element_background = { 0xE1, 0xE1, 0xE1, 0x00 };
		element_text = { 0x00, 0x00, 0x00, 0x00 };
	}

	SDL_Color background;
	SDL_Color element_blocked;
	SDL_Color element_border;
	SDL_Color element_background_click;
	SDL_Color element_background_focus;
	SDL_Color element_background_unfocus;
	SDL_Color element_border_click;
	SDL_Color element_list_hover;
	SDL_Color element_background;
	SDL_Color element_text;
};