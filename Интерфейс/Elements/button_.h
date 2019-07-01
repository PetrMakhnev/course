#pragma once
#include "control.h"

enum BUTTON_TYPES {
	BUTTON_OK_COUNT_ELEMENT,
	BUTTON_OK_SET_START_VALUE,

	BUTTON_OK_PERFORM_OPERATION,
	BUTTON_QUIT
};

class Button_ : public Control {
private:
	string text;
	int type;

public:
	Button_(SDL_Renderer* _renderer, SDL_Rect* _sizes, string _text, int _type, string _font, int _font_size) : Control(_renderer, _sizes, _font, _font_size)
	{
		type = _type;
		text = _text;
	};

public:
	void render();

};