#include "itemList_.h"

void ItemList_::render()
{
	if (!display) 
		return;
	
	// sizes — размеры главного объекта
	// itemSizes — размеры одного эдемента списка

	SDL_Rect renderRect = *itemSizes;
	renderRect.x = sizes->x + sizes->w + 2;
	renderRect.y = sizes->y - 1;

	// Отрисовка обводки
	{
		SDL_Rect border = *sizes;
		border.x--;
		border.y--;
		border.w += 2;
		border.h += 2;

		
		SDL_SetRenderDrawColor(renderer, Colors.element_border.r, Colors.element_border.g, Colors.element_border.b, Colors.element_border.a);

		SDL_RenderFillRect(renderer, &border);
	}

	if (block)
		SDL_SetRenderDrawColor(renderer, Colors.element_blocked.r, Colors.element_blocked.g, Colors.element_blocked.b, Colors.element_blocked.a);
	else 
		SDL_SetRenderDrawColor(renderer, Colors.element_background.r, Colors.element_background.g, Colors.element_background.b, Colors.element_background.a);

	SDL_RenderFillRect(renderer, sizes);


	renderLabel(mainLabel, sizes, CENTERED_ALIGN);



	if (show_menu && !block) {
		
		for (int i = 0; i < List.size(); i++) 
		{
			if (List.at(i)->Hover())
				SDL_SetRenderDrawColor(renderer, Colors.element_list_hover.r, Colors.element_list_hover.g, Colors.element_list_hover.b, Colors.element_list_hover.a);
			else
				SDL_SetRenderDrawColor(renderer, Colors.element_background.r, Colors.element_background.g, Colors.element_background.b, Colors.element_background.a);

			SDL_RenderFillRect(renderer, &renderRect);
			renderLabel(List[i]->text, &renderRect, LEFT_ALIGN);
			renderRect.y += renderRect.h;
		}
	}
	else{
		SDL_Rect clearRect = { renderRect.x, renderRect.y, renderRect.w, renderRect.h * List.size() };
		SDL_SetRenderDrawColor(renderer, Colors.background.r , Colors.background.g, Colors.background.b, Colors.background.a);
		SDL_RenderFillRect(renderer, &clearRect);
	}


	SDL_RenderPresent(renderer);
}


void ItemList_::add(string text, int flag)
{
	Item* newItem = new Item;
	newItem->text = text;
	newItem->flag = flag;

	List.push_back(newItem);
}

void ItemList_::open(bool value)
{
	show_menu = value;
}

bool ItemList_::open()
{
	return show_menu;
}

int ItemList_::checkItemHover(int _x, int _y)
{
	if (block || !display || !show_menu)
		return false;

	SDL_Point point = { _x, _y };

	SDL_Rect itemRect = *itemSizes;
	itemRect.x = sizes->x + sizes->w;
	itemRect.y = sizes->y;


	int flag = 0;
	for (int i = 0; i < List.size(); i++) {
		bool hov = SDL_PointInRect(&point, &itemRect);
		itemRect.y += itemRect.h;

		List.at(i)->Hover(false);

		if (hov) {
			flag = List.at(i)->flag;
			List.at(i)->Hover(true);
			//return true;
		}
	}
	return flag;
}
