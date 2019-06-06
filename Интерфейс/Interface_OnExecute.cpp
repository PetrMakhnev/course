#include "app.h"

int Interface::onExecute()
{
	init();

/*
	SDL_Rect rect1 = { 320, 100, 130, 25 };
	Button_* newButton1 = new Button_(
		renderer,
		&rect1,
		"Count element",
		BUTTON_INITIALIZE_COUNT_ELEMENT,
		"Fonts/verdana.ttf", 12
	);
	Buttons.push_back(newButton1);


	SDL_Rect rect = { 320, 160, 130, 20 };
	Input_* newInput = new Input_(renderer, &rect, INPUT_COUNT_ELEMENT, "Fonts/verdana.ttf", 12);
	Inputs.push_back(newInput);


	SDL_Rect coord = { 320, 140, 0, 20 };
	Label* label = new Label(renderer, &coord, BY_LEFT, "Count of Elements", "Fonts/verdana.ttf", 11);

	Labels.push_back(label);


	SDL_Rect rect2 = { 320, 190, 130, 25 };
	Button_* newButton2 = new Button_(
		renderer,
		&rect2,
		"OK",
		BUTTON_INITIALIZE_COUNT_ELEMENT,
		"Fonts/verdana.ttf", 12
	);
	Buttons.push_back(newButton2);




	SDL_Rect mainList = { 320, 260, 130, 25 };
	SDL_Rect item = { -1, -1, 130, 25 };

	ItemList_* itemList = new ItemList_(renderer, &mainList, &item, "Menu", "Fonts/verdana.ttf", 12);

	itemList->add("operator =", TEST_BITSTRING_OPERATOR_EQUATE);
	itemList->add("operator ==", TEST_BITSTRING_OPERATOR_EQUAL);
	itemList->add("operator -", TEST_BITSTRING_OPERATOR_INDEX);

	ItemLists.push_back(itemList);


	SDL_Rect mainList1 = { 320, 350, 130, 25 };
	SDL_Rect item1 = { -1, -1, 130, 25 };

	ItemList_* itemList1 = new ItemList_(renderer, &mainList1, &item1, "Menu", "Fonts/verdana.ttf", 12);

	itemList1->add("operator =", TEST_BITSTRING_OPERATOR_EQUATE);
	itemList1->add("operator ==", TEST_BITSTRING_OPERATOR_EQUAL);
	itemList1->add("operator -", TEST_BITSTRING_OPERATOR_INDEX);

	ItemLists.push_back(itemList1);


	*/

	SDL_Rect coord = { 320, 80, 0, 20 };
	Label* label = new Label(renderer, &coord, BY_LEFT, "Count of Elements", "Fonts/verdana.ttf", 11);

	Labels.push_back(label);

	SDL_Rect mainList = { 320, 100, 160, 20 };
	SDL_Rect item = { -1, -1, 30, 20 };
	DropDownList* DropDownList1 = new DropDownList(renderer, &mainList, &item, LEFT_SIDE, "Fonts/verdana.ttf", 12);

	for (size_t i = 1; i < 11; i++){
		char* num = new char[10];
		_itoa(i, num, 10);
		DropDownList1->add(num, i + 9);
	}


	DropDownLists.push_back(DropDownList1);


	SDL_Rect rect1 = { 320, 130, 160, 20 };
	Button_* newButton1 = new Button_(
		renderer,
		&rect1,
		"OK",
		BUTTON_OK_COUNT_ELEMENT,
		"Fonts/verdana.ttf", 12
	);
	Buttons.push_back(newButton1);






	


	SDL_Rect coord3 = { 320, 200, 0, 20 };
	Label* label3 = new Label(renderer, &coord3, BY_LEFT, "Count of items not set", "Fonts/verdana.ttf", 11);

	Labels.push_back(label3);

	SDL_Rect coord1 = { 320, 220, 0, 20 };
	Label* label1 = new Label(renderer, &coord1, BY_LEFT, "Type", "Fonts/verdana.ttf", 11);
	Labels.push_back(label1);

	SDL_Rect mainList1 = { 320, 240, 160, 20 };
	SDL_Rect item1 = { -1, -1, 160, 20 };
	DropDownList* DropDownList2 = new DropDownList(renderer, &mainList1, &item1, LEFT_SIDE, "Fonts/verdana.ttf", 12);


	DropDownList2->add("Base class", DROP_BASE_CLASS);
	DropDownList2->add("Identification class", DROP_ID_CLASS);
	DropDownList2->add("Dec string class", DROP_DEC_CLASS);

	DropDownList2->blocked();

	DropDownLists.push_back(DropDownList2);

	SDL_Rect coord2 = { 320, 260, 0, 20 };
	Label* label2 = new Label(renderer, &coord2, BY_LEFT, "Value", "Fonts/verdana.ttf", 11);
	Labels.push_back(label2);

	SDL_Rect rect = { 320, 280, 160, 20 };
	Input_* newInput = new Input_(renderer, &rect, INPUT_COUNT_ELEMENT, "Fonts/verdana.ttf", 12);
	newInput->blocked();
	Inputs.push_back(newInput);


	SDL_Rect rect2 = { 320, 310, 160, 20 };
	Button_* newButton2 = new Button_(
		renderer,
		&rect2,
		"OK",
		BUTTON_OK_SET_START_VALUE,
		"Fonts/verdana.ttf", 12
	);
	newButton2->blocked();
	Buttons.push_back(newButton2);



	// Выпадающий список со всеми классами //
	SDL_Rect mainList2 = { 600, 10, 200, 20 };
	SDL_Rect item2 = { -1, -1, 200, 20 };
	DropDownList* DropDownList3 = new DropDownList(renderer, &mainList2, &item2, LEFT_SIDE, "Fonts/verdana.ttf", 12);

	DropDownLists.push_back(DropDownList3);







	//##### Выбор операций над классами ######// 


	SDL_Rect itemList_ItemRect = { -1, -1, 160, 20 };
	// Выпадающий список для базового класса //
	{
		SDL_Rect itemListRect1 = { 650, 100, 130, 20 };
		

		ItemList_* itemList1 = new ItemList_(renderer, &itemListRect1, &itemList_ItemRect, "String", "Fonts/verdana.ttf", 12);

		itemList1->add("Operator =", TEST_STRING_EQUAL);
		itemList1->add("Get length", TEST_STRING_GET_LENGTH);

		ItemLists.push_back(itemList1);
	}

	// Выпадающий список для класса идентификатора //
	{
		SDL_Rect itemListRect2 = { 650, 125, 130, 20 };
	

		ItemList_* itemList2 = new ItemList_(renderer, &itemListRect2, &itemList_ItemRect, "Identificator", "Fonts/verdana.ttf", 12);

		itemList2->add("Operator =", TEST_IDENTIFICATION_OPERATOR_EQUAL);
		itemList2->add("To lower case", TEST_IDENTIFICATION_OPERATOR_TO_LOWER_CASE);
		itemList2->add("Substraction", TEST_IDENTIFICATION_OPERATOR_EQUAL);

		ItemLists.push_back(itemList2);
	}

	// Выпадающий список для класса десятичной строки //
	{
		SDL_Rect itemListRect3 = { 650, 150, 130, 20 };
		

		ItemList_* itemList3 = new ItemList_(renderer, &itemListRect3, &itemList_ItemRect, "Decimal", "Fonts/verdana.ttf", 12);

		itemList3->add("It may be Unsigned Int?", TEST_DECIMAL_IS_UNSIGNED_INT);
		itemList3->add("Substraction", TEST_DECIMAL_SUBTRACTION);

		ItemLists.push_back(itemList3);
	}

	// Список для выбора первого операнда //
	{
		SDL_Rect DropDownList_Rect3 = { 550, 300, 160, 20 };
		SDL_Rect item_Rect = { -1, -1, 160, 20 };
		DropDownList* DropDownList4 = new DropDownList(renderer, &DropDownList_Rect3, &item_Rect, DOWN_SIDE, "Fonts/verdana.ttf", 12);

		DropDownLists.push_back(DropDownList4);
	}

	// Список для выбора второго операнда //
	{
		SDL_Rect DropDownList_Rect4 = { 750, 300, 160, 20 };
		SDL_Rect item_Rect = { -1, -1, 160, 20 };
		DropDownList* DropDownList5 = new DropDownList(renderer, &DropDownList_Rect4, &item_Rect, DOWN_SIDE, "Fonts/verdana.ttf", 12);

		DropDownLists.push_back(DropDownList5);
	}

	// Кнопка ввода информации
	{
		SDL_Rect rect3 = { 650, 450, 160, 20 };
		Button_* newButton3 = new Button_(
			renderer,
			&rect3,
			"OK",
			BUTTON_OK_PERFORM_OPERATION,
			"Fonts/verdana.ttf", 12
		);

		Buttons.push_back(newButton3);
	}

	render();
	onEvent();

	

	return 0;
}
