#pragma once
#include "control.h"
using namespace std;

enum TYPES {
	BY_RIGHT,
	BY_LEFT
};

class Label : public Control{
private:
	string label;
	int type;

public:
	Label(SDL_Renderer* _renderer, SDL_Rect* _sizes, int _type, string _new_string, const char* _font, int _font_size);

public:
	void render();
	void show(bool value);
	
	void setText(string text);
};