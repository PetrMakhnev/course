#pragma once
#include "control.h"

enum DROP_ITEM_LIST_TYPES {
	DROP_BASE_CLASS = 10,
	DROP_ID_CLASS = 11,
	DROP_BIN_CLASS = 12
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
	string mainLabel;
	bool show_menu;

	int flag_select;

	int type;


	SDL_Texture* dropButton;

public:

	DropDownList(SDL_Renderer* _renderer, SDL_Rect* _sizes, SDL_Rect* _itemSizes, int _type, string _font, int _font_size) : Control(_renderer, _sizes, _font, _font_size)
	{
		type = _type;
		itemSizes = _itemSizes;
		dropButton = IMG_LoadTexture(renderer, "sfx/drop_button.png");
		show_menu = false;
		
	};


public:

	void render();

	DropDownItem* add(string text, int flag);

	void open(bool value);
	bool open();

	int checkItemHover(int x, int y);

	void setValue(string value);
	string getValue();
	int getFlag();
	vector <DropDownItem*> getItems();

	void clear();

	DropDownList* deleteItems();

};