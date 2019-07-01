#include "ListDown.h"

void DropDownList::render()
{
	if (!display) {
		SDL_Rect clearRect = *sizes;
		clearRect.x--;
		clearRect.y--;
		clearRect.w += 2;
		clearRect.h += 2;

		SDL_SetRenderDrawColor(renderer, Colors.background.r, Colors.background.g, Colors.background.b, Colors.background.a);
		SDL_RenderFillRect(renderer, &clearRect);
		return;
	}
		
	// sizes — размеры главного объекта
	// itemSizes — размеры одного эдемента списка

	SDL_Rect renderRect = *itemSizes;

	if (type == LEFT_SIDE) {
		renderRect.x = sizes->x + sizes->w + 2;
		renderRect.y = sizes->y - 1;
	}
	else if (type == DOWN_SIDE){
		renderRect.x = sizes->x;
		renderRect.y = sizes->y + sizes->h + 2;
	}

	// Отрисовка обводки
	{
		SDL_Rect * border = new SDL_Rect;
		*border = *sizes;
		border->x--;
		border->y--;
		border->w += 2;
		border->h += 2;


		SDL_SetRenderDrawColor(renderer, Colors.element_border.r, Colors.element_border.g, Colors.element_border.b, Colors.element_border.a);

		SDL_RenderFillRect(renderer, border);

		delete border;
	}

	// Отрисовка тела
	{
		if (block)
			SDL_SetRenderDrawColor(renderer, Colors.element_blocked.r, Colors.element_blocked.g, Colors.element_blocked.b, Colors.element_blocked.a);
		else
			SDL_SetRenderDrawColor(renderer, Colors.element_background_unfocus.r, Colors.element_background_unfocus.g, Colors.element_background_unfocus.b, Colors.element_background_unfocus.a);
	}
	
	// Отрисовка кнопки
	SDL_Rect dropButtonRect;
	{
		dropButtonRect = { sizes->x + sizes->w - 15, sizes->y + 6, 8, 8 };
		SDL_RenderFillRect(renderer, sizes);
	}

	renderLabel(mainLabel, sizes, LEFT_ALIGN);
	SDL_RenderCopy(renderer, dropButton, NULL, &dropButtonRect);


	if (show_menu && !block) {

		for (size_t i = 0; i < List.size(); i++)
		{
			if (List.at(i)->Block()) {
				SDL_SetRenderDrawColor(renderer, Colors.element_blocked.r, Colors.element_blocked.g, Colors.element_blocked.b, Colors.element_blocked.a);
			}
			else {
				if (List.at(i)->Hover())
					SDL_SetRenderDrawColor(renderer, Colors.element_list_hover.r, Colors.element_list_hover.g, Colors.element_list_hover.b, Colors.element_list_hover.a);
				else
					SDL_SetRenderDrawColor(renderer, Colors.element_background.r, Colors.element_background.g, Colors.element_background.b, Colors.element_background.a);
			}
			SDL_RenderFillRect(renderer, &renderRect);
			renderLabel(List[i]->text, &renderRect, LEFT_ALIGN);
			renderRect.y += renderRect.h;
		}
	}
	else {
		SDL_Rect clearRect = { renderRect.x, renderRect.y, renderRect.w, renderRect.h * List.size() };
		SDL_SetRenderDrawColor(renderer, Colors.background.r, Colors.background.g, Colors.background.b, Colors.background.a);
		SDL_RenderFillRect(renderer, &clearRect);
	}


	SDL_RenderPresent(renderer);
}


DropDownItem* DropDownList::add(string text, int flag)
{
	DropDownItem* newItem = new DropDownItem;
	newItem->text = text;
	newItem->flag = flag;

	List.push_back(newItem);

	return newItem;
}

void DropDownList::open(bool value)
{
	show_menu = value;
}

bool DropDownList::open()
{
	return show_menu;
}

void DropDownList::setValue(string value)
{
	mainLabel = value;
}

string DropDownList::getValue()
{
	return mainLabel;
}

int DropDownList::getFlag()
{
	return flag_select;
}

vector<DropDownItem*> DropDownList::getItems()
{
	return List;
}

void DropDownList::clear()
{
	mainLabel = "";
}

DropDownList * DropDownList::deleteItems()
{
	List.clear();
	return this;
}

int DropDownList::checkItemHover(int _x, int _y)
{
	if (block || !display || !show_menu)
		return false;

	SDL_Point point = { _x, _y };

	SDL_Rect itemRect = *itemSizes;

	if (type == LEFT_SIDE) {
		itemRect.x = sizes->x + sizes->w;
		itemRect.y = sizes->y;
	}
	else if (type == DOWN_SIDE) {
		itemRect.x = sizes->x;
		itemRect.y = sizes->y + sizes->h;
	}

	int flag = 0;

	for (int i = 0; i < List.size(); i++)
		List.at(i)->Hover(false);

	for (int i = 0; i < List.size(); i++) {
		bool hov = SDL_PointInRect(&point, &itemRect);
		itemRect.y += itemRect.h;

		if (hov) {
			if (!List.at(i)->Block()) {
				flag = List.at(i)->flag;
				List.at(i)->Hover(true);
			}
		}
	}
	flag_select = flag;
	return flag;
}
