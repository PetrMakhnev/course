#pragma once
#include "control.h"


enum InputTypes {
	INPUT_COUNT_ELEMENT,
	INPUT_START_VALUE
};

class Input_ : public Control {
private:
	string inputText;

	bool focus;

	int type;

public:
	Input_(SDL_Renderer * _renderer, SDL_Rect* _sizes, int _type, string _font, int _font_size) : Control(_renderer, _sizes, _font, _font_size)
	{
		type = _type;
		focus = false;
		inputText = "";
	};

private:
	void textRender();

public:
	void render();

	void onEvent(SDL_Event* event);

	void clear();

	string getValue();

	void Focus(bool value);
};