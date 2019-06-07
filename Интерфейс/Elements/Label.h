#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "iostream"
#include "../Color.h"
using namespace std;

enum TYPES {
	BY_RIGHT,
	BY_LEFT
};

class Label {
private:
	string label;
	SDL_Renderer* renderer;
	SDL_Texture* textTexture;
	SDL_Surface* textSurface;
	TTF_Font* font;

	SDL_Rect coord;
	SDL_Rect textRect;

	COLOR Colors;

	bool display;

	int type;

public:
	Label(SDL_Renderer * renderer, SDL_Rect * coord, int type, string newString, const char * _font, int _font_size);
public:
	void render();
	void show(bool value);
	
	void setText(string text);
};