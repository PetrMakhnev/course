#pragma once
#include "string"
#include "vector"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "iostream"
#include "../Color.h"
using namespace std;

enum TYPE_ALIGN {
	CENTERED_ALIGN,
	LEFT_ALIGN
};

class Control {
protected:
	SDL_Rect* sizes;

	SDL_Event event;

	TTF_Font* font;

	SDL_Renderer* renderer;

	COLOR Colors;

	int font_size;

	bool block;
	bool display;

	bool click;
public:
	Control(SDL_Renderer * renderer, SDL_Rect* _sizes, string _font, int _font_size);
public:

	virtual void render();
	virtual void renderLabel(string text, SDL_Rect* renderRect, int type);

	void unlock();
	void blocked();

	void hide();
	void show();

	void Click(bool);

	bool getShow();

	bool checkHover(int x, int y);

	virtual void onEvent(SDL_Event* event);
};