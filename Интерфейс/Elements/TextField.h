#pragma once
#include "control.h"
class TextField : public Control {
private:
	vector <string> lines;

public:
	TextField(SDL_Renderer* _renderer, SDL_Rect* _sizes, string _font, int _font_size) : Control(_renderer, _sizes, _font, _font_size)
	{};

public:
	void add(string newLine);

	void render();
};