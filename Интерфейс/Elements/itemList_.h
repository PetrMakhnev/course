#pragma once
#include "control.h"

enum ITEM_LIST_TYPES {
	NULLELE,

	TEST_STRING_EQUAL,
	TEST_STRING_GET_LENGTH,

	TEST_IDENTIFICATION_OPERATOR_TO_LOWER_CASE,
	TEST_IDENTIFICATION_OPERATOR_EQUAL,
	TEST_IDENTIFICATION_OPERATOR_SUBTRACTION,
	TEST_IDENTIFICATION_INDEX_OF,

	TEST_BINARY_REVERSE,
	TEST_BINARY_SUBTRACTION
};

typedef struct Item {
	Item() {
		hover = false;
		flag = 0;
		blocked = false;
	}

	string text;
	bool hover;
	int flag;

	bool blocked;

	void Hover(bool value) {
		hover = value;
	}

	void Block(bool value) {
		blocked = value;
	}

	bool Hover() {
		return hover;
	}
} Item;

class ItemList_ : public Control {
private:
	vector <Item *> List;
	SDL_Rect* itemSizes;
	

	string mainLabel;
	bool show_menu;

public:
	
	ItemList_(SDL_Renderer* _renderer, SDL_Rect* _sizes, SDL_Rect* _itemSizes, string _mainLabel,string _font, int _font_size) : Control(_renderer, _sizes, _font, _font_size)
	{
		mainLabel = _mainLabel;
		itemSizes = _itemSizes;

		show_menu = false;
	};


public:

	void render();

	void add(string text, int flag);

	void open(bool value);
	bool open();

	int checkItemHover(int x, int y);
};