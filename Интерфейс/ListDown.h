#pragma once
#include "Elements/control.h"

enum DropElement {
	DROP_BASE_CLASS = 10,
	DROP_ID_CLASS = 11,
	DROP_DEC_CLASS = 12
};

enum TYPE {
	LEFT_SIDE = 1,
	DOWN_SIDE = 2
};

typedef struct DropDownItem {
	DropDownItem() {
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

	bool Block() {
		return blocked;
	}

	bool Hover() {
		return hover;
	}
} DropDownItem;

class DropDownList : public Control {
private:
	vector <DropDownItem*> List;
	SDL_Rect* itemSizes;
	int count;

	int flag_select;

	int type;

	string mainLabel;
	bool show_menu;

	SDL_Texture* dropButton;

public:

	DropDownList(SDL_Renderer* _renderer, SDL_Rect* _sizes, SDL_Rect* _itemSizes, int _type, string _font, int _font_size) : Control(_renderer, _sizes, _font, _font_size)
	{
		type = _type;
		itemSizes = _itemSizes;
		dropButton = IMG_LoadTexture(renderer, "sfx/drop_button.png");
		show_menu = false;
		count = 0;
	};


public:

	void render();

	DropDownItem* add(string text, int flag);

	void open(bool value);
	bool open();

	void setValue(string value);
	string getValue();
	int getFlag();
	vector <DropDownItem*> getItems();

	DropDownList* clear();

	DropDownList* deleteItems();

	int checkItemHover(int x, int y);

};