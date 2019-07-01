#include "app.h"

// mouse events
void Interface::mouseMotion(SDL_Event* event) {
	int x, y;
	SDL_GetMouseState(&x, &y);


	for (int i = 0; i < ItemLists.size(); i++) {
		if (ItemLists.at(i)->checkItemHover(x, y))
			ItemLists.at(i)->render();
		
	}
	
	for (int i = 0; i < DropDownLists.size(); i++) {
		if (DropDownLists.at(i)->checkItemHover(x, y))
			DropDownLists.at(i)->render();
	}
}

void Interface::mouseButtonDown(SDL_Event* event)
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	for (int i = 0; i < Buttons.size(); i++) {
		if (Buttons.at(i)->checkHover(x, y)) {
			Buttons.at(i)->Click(true);
			Buttons.at(i)->render();

			switch (i)
			{

			case BUTTON_OK_COUNT_ELEMENT: {
				string data = DropDownLists.at(0)->getValue();

				if (data == "")
					break;

				TextFields.at(0)->add("Количество классов: " + data);
				TextFields.at(0)->renderText();

				count_element = atoi(data.c_str());
				DropDownLists.at(0)->blocked();
				DropDownLists.at(0)->render();
				Buttons.at(0)->blocked();
				Buttons.at(0)->render();
				Buttons.at(1)->unlock();
				Buttons.at(1)->render();

				DropDownLists.at(1)->unlock();
				DropDownLists.at(1)->render();

				Inputs.at(0)->unlock();
				Inputs.at(0)->render();

				

				TextFields.at(0)->add("Ввод 1-го элемента");
				TextFields.at(0)->renderText();

				Labels.at(1)->setText("Enter 1-st element");
				Labels.at(1)->render();

				break;
			}

			case BUTTON_OK_SET_START_VALUE: {
				if (ready_fill_classes)
					break;

				string value = Inputs.at(0)->getValue();

				if (value == "")
					break;
				
				
				int type = DropDownLists.at(1)->getFlag();
				

				DropDownLists.at(1)->clear();
				DropDownLists.at(1)->render();
				Inputs.at(0)->clear();
				Inputs.at(0)->render();


				switch (type)
				{

				case DROP_BASE_CLASS:  
					ptrBaseClass.push_back(new String(value.c_str()));
					type_ptrBaseClasses.push_back(STRING_BASE);

					DropDownLists.at(2)->add(value, 10 + count_ready);
					DropDownLists.at(2)->render();

					TextFields.at(0)->add("Тип класса: Базовый класс");
					TextFields.at(0)->renderText();
					break;

				case DROP_ID_CLASS:
					ptrBaseClass.push_back(new ID_String(value.c_str()));
					type_ptrBaseClasses.push_back(STRING_ID);

					DropDownLists.at(2)->add(value, 10 + count_ready);
					DropDownLists.at(2)->render();

					TextFields.at(0)->add("Тип класса: Класс идентификатора");
					TextFields.at(0)->renderText();

					break;

				case DROP_BIN_CLASS:
					ptrBaseClass.push_back(new BIN_String(value.c_str()));
					type_ptrBaseClasses.push_back(STRING_BIN);

					DropDownLists.at(2)->add(value, 10 + count_ready);
					DropDownLists.at(2)->render();

					TextFields.at(0)->add("Тип класса: Бинарная строка");
					TextFields.at(0)->renderText();
					break;

				default: break;

				}


				if (count_ready + 1 == count_element) {

					TextFields.at(0)->add("Значение класса: " + value);
					TextFields.at(0)->renderText();

					TextFields.at(0)->add("Все классы заполнены!");
					TextFields.at(0)->renderText();

					Labels.at(1)->setText("All classes has filled!");
					Labels.at(1)->render();

					ready_fill_classes = true;
					DropDownLists.at(1)->blocked();
					DropDownLists.at(1)->render();
					Inputs.at(0)->blocked();
					Inputs.at(0)->render();
					Buttons.at(1)->blocked();
					Buttons.at(1)->render();
				}
				else {

					TextFields.at(0)->add("Значение класса: " + value);
					TextFields.at(0)->renderText();

					char* count_text = new char[5];
					_itoa(count_ready + 2, count_text, 10);
					string countText(count_text);

					TextFields.at(0)->add("Ввод " + countText + "-го элемента");
					TextFields.at(0)->renderText();

					Labels.at(1)->setText("Enter " + countText + "-th element");
					Labels.at(1)->render();

				}

				
				count_ready++;
				break;
			}

			case BUTTON_OK_PERFORM_OPERATION: {
				
				
				switch (nowOperation)
				{

				case TEST_STRING_EQUAL: {

					int indexFirst = DropDownLists.at(3)->getFlag() - 10;
					int indexSecond = DropDownLists.at(4)->getFlag() - 10;

					/// ОСНОВНОЕ ПРИСВАИВАНИЕ
					*ptrBaseClass.at(indexFirst) = *ptrBaseClass.at(indexSecond);
					///

					

					DropDownLists.at(2)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {
						string newElement(ptrBaseClass.at(i)->getString());
						DropDownLists.at(2)->add(newElement, 10 + i);
					}

					Labels.at(4)->show(false);
					Labels.at(5)->show(false);
					Labels.at(4)->render();
					Labels.at(5)->render();

					Buttons.at(2)->hide();
					Buttons.at(2)->render();

					DropDownLists.at(3)->hide();
					DropDownLists.at(4)->hide();

					DropDownLists.at(2)->render();
					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();
					
					nowOperation = NULLELE;

					break;
				}
				case TEST_STRING_GET_LENGTH: {
					int indexFirst = DropDownLists.at(3)->getFlag() - 10;
					

					int length = ptrBaseClass.at(indexFirst)->getLength();
					char* length_str = new char[10];
					_itoa(length, length_str, 10);
					string len_num(length_str);
					string len_str = "Длина строки равна: " + len_num;

					TextFields.at(0)->add(len_str);
					TextFields.at(0)->renderText();
					
					Buttons.at(2)->hide();
					Buttons.at(2)->render();

					Labels.at(4)->show(false);
					Labels.at(5)->show(false);
					Labels.at(4)->render();
					Labels.at(5)->render();

					DropDownLists.at(3)->hide();
					DropDownLists.at(4)->hide();

					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();

					nowOperation = NULLELE;

					break;
				}
				
				case TEST_IDENTIFICATION_OPERATOR_TO_LOWER_CASE: {
					int indexFirst = DropDownLists.at(3)->getFlag() - 10;

					/// ОСНОВНАЯ ФУНКЦИЯ
					((ID_String*)ptrBaseClass.at(indexFirst))->toLowerCase();
					///

					DropDownLists.at(2)->deleteItems()->clear();
					DropDownLists.at(3)->deleteItems()->clear();
					DropDownLists.at(4)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {
						string newElement(ptrBaseClass.at(i)->getString());
						DropDownLists.at(2)->add(newElement, 10 + i);
					}

					Labels.at(4)->show(false);
					Labels.at(5)->show(false);
					Labels.at(4)->render();
					Labels.at(5)->render();

					Buttons.at(2)->hide();
					Buttons.at(2)->render();

					DropDownLists.at(3)->hide();
					DropDownLists.at(4)->hide();

					DropDownLists.at(2)->render();
					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();

					nowOperation = NULLELE;

					break;
				}
				case TEST_IDENTIFICATION_OPERATOR_EQUAL: {

					int indexFirst = DropDownLists.at(3)->getFlag() - 10;
					int indexSecond = DropDownLists.at(4)->getFlag() - 10;

					/// ОСНОВНОЕ ПРИСВАИВАНИЕ
					*ptrBaseClass.at(indexFirst) = *ptrBaseClass.at(indexSecond);
					///

					DropDownLists.at(2)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {
						string newElement(ptrBaseClass.at(i)->getString());
						DropDownLists.at(2)->add(newElement, 10 + i);
					}

					Labels.at(4)->show(false);
					Labels.at(5)->show(false);
					Labels.at(4)->render();
					Labels.at(5)->render();

					Buttons.at(2)->hide();
					Buttons.at(2)->render();

					DropDownLists.at(3)->hide();
					DropDownLists.at(4)->hide();

					DropDownLists.at(2)->render();
					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();

					nowOperation = NULLELE;

					break;
				}
				case TEST_IDENTIFICATION_OPERATOR_SUBTRACTION: {

					int indexFirst = DropDownLists.at(3)->getFlag() - 10;
					int indexSecond = DropDownLists.at(4)->getFlag() - 10;

					/// ОСНОВНОЕ ПРИСВАИВАНИЕ
					ptrBaseClass.push_back(new ID_String());
					type_ptrBaseClasses.push_back(STRING_ID);

					ID_String* first = (ID_String*)(ptrBaseClass.at(indexFirst));
					ID_String* second = (ID_String*)(ptrBaseClass.at(indexSecond));

					*ptrBaseClass.at(ptrBaseClass.size() - 1) = *first - *second;
					///

					DropDownLists.at(2)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {
						string newElement(ptrBaseClass.at(i)->getString());
						DropDownLists.at(2)->add(newElement, 10 + i);
					}

					Labels.at(4)->show(false);
					Labels.at(5)->show(false);
					Labels.at(4)->render();
					Labels.at(5)->render();

					Buttons.at(2)->hide();
					Buttons.at(2)->render();

					DropDownLists.at(3)->hide();
					DropDownLists.at(4)->hide();

					DropDownLists.at(2)->render();
					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();

					nowOperation = NULLELE;

					break;
				}
				case TEST_IDENTIFICATION_INDEX_OF: {

					int indexFirst = DropDownLists.at(3)->getFlag() - 10;


					char symbol = Inputs.at(1)->getValue().at(0);

					ID_String* first = (ID_String*)(ptrBaseClass.at(indexFirst));

					int place = 0;
					/// ОСНОВНОЕ ПРИСВАИВАНИЕ
					char* strs = new char[2];
					strs[0] = symbol;
					strs[1] = '\0';

					string symbolStr(strs);
					delete[] strs;
					string value = first->getString();

					char* num = new char[5];

					place = first->indexOf(symbol);
					_itoa(place, num, 10);
					string number(num);
					if (place != -1)
						TextFields.at(0)->add("Символ " + symbolStr + " найден в строке " + value + " на " + number + "-тои месте");
					else 
						TextFields.at(0)->add("Символ " + symbolStr + " НЕ найден в строке " + value);
					
					TextFields.at(0)->renderText();
					///

					Labels.at(6)->show(false);
					Labels.at(4)->show(false);
					Labels.at(6)->render();
					Labels.at(4)->render();

					Buttons.at(2)->hide();
					Buttons.at(2)->render();

					Inputs.at(1)->clear();
					Inputs.at(1)->hide();
					Inputs.at(1)->render();

					DropDownLists.at(3)->hide();
					DropDownLists.at(3)->render();
					

					nowOperation = NULLELE;
					break;
				}

				case TEST_BINARY_REVERSE: {

					int indexFirst = DropDownLists.at(3)->getFlag() - 10;

					/// ОСНОВНОЕ ПРИСВАИВАНИЕ
					((BIN_String*)(ptrBaseClass.at(indexFirst)))->invert();

					string text = ((BIN_String*)(ptrBaseClass.at(indexFirst)))->getString();
					TextFields.at(0)->add("Результат инвертирования равен: " + text);
					TextFields.at(0)->renderText();

					
					///

					DropDownLists.at(2)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {
						string newElement(ptrBaseClass.at(i)->getString());
						DropDownLists.at(2)->add(newElement, 10 + i);
					}

					Labels.at(4)->show(false);
					Labels.at(5)->show(false);
					Labels.at(4)->render();
					Labels.at(5)->render();

					Buttons.at(2)->hide();
					Buttons.at(2)->render();

					DropDownLists.at(3)->hide();

					DropDownLists.at(2)->render();
					DropDownLists.at(3)->render();


					nowOperation = NULLELE;

					break;
				}
				case TEST_BINARY_SUBTRACTION: {
					int indexFirst = DropDownLists.at(3)->getFlag() - 10;
					int indexSecond = DropDownLists.at(4)->getFlag() - 10;

					/// ОСНОВНОЕ ПРИСВАИВАНИЕ
					BIN_String* first = (BIN_String*)(ptrBaseClass.at(indexFirst));
					BIN_String* second = (BIN_String*)(ptrBaseClass.at(indexSecond));
					BIN_String result;
					result = *first - *second;

					string text = result.getString();
					TextFields.at(0)->add("Результат вычитания равен: " + text);
					TextFields.at(0)->renderText();
					
					///

					DropDownLists.at(2)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {
						string newElement(ptrBaseClass.at(i)->getString());
						DropDownLists.at(2)->add(newElement, 10 + i);
					}

					Labels.at(4)->show(false);
					Labels.at(5)->show(false);
					Labels.at(4)->render();
					Labels.at(5)->render();

					Buttons.at(2)->hide();
					Buttons.at(2)->render();

					DropDownLists.at(3)->hide();
					DropDownLists.at(4)->hide();

					DropDownLists.at(2)->render();
					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();

					nowOperation = NULLELE;

					break;
				}
				default: break;
				}

				break;
			}

			case BUTTON_QUIT: {
				quit();
				break;
			}
			default: break;
			}
		}
	}
}

void Interface::mouseButtonUp(SDL_Event* event)
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	for (int i = 0; i < Buttons.size(); i++) {
		Buttons.at(i)->Click(false);
		Buttons.at(i)->render();
	}

	for (int i = 0; i < Inputs.size(); i++) {
		if (Inputs.at(i)->checkHover(x, y)) {
			Inputs.at(i)->Focus(true);
			Inputs.at(i)->render();
			Inputs.at(i)->onEvent(event);
		}
	}



	for (int i = 0; i < ItemLists.size(); i++) {
		int flag = ItemLists.at(i)->checkItemHover(x, y);

		if (ItemLists.at(i)->checkHover(x, y)) {

			if (!ItemLists.at(i)->open()) {
				for (int i = 0; i < ItemLists.size(); i++) {
					ItemLists.at(i)->open(false);
					ItemLists.at(i)->render();
				}

				ItemLists.at(i)->open(true);
				ItemLists.at(i)->render();
			}
			else {
				ItemLists.at(i)->open(false);
				ItemLists.at(i)->render();
			}
		}
		else {

			if (flag) {

				for (size_t i = 0; i < ItemLists.size(); i++) {
					ItemLists.at(i)->open(false);
					ItemLists.at(i)->render();
				}

				switch (flag)
				{

				case TEST_STRING_EQUAL: {

					short count = 0;
					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++)
						if (type_ptrBaseClasses.at(i) == STRING_BASE)
							count++;

					if (count < 2) {
						// ошибка 
						TextFields.at(0)->add("Слишком мало объектов базового класса");
						TextFields.at(0)->renderText();
						
						return;
					}

					Buttons.at(2)->show();
					Buttons.at(2)->render();

					DropDownLists.at(3)->show();
					DropDownLists.at(4)->show();

					nowOperation = TEST_STRING_EQUAL;

					Labels.at(4)->show(true);
					Labels.at(5)->show(true);
					Labels.at(4)->render();
					Labels.at(5)->render();

					DropDownLists.at(3)->deleteItems()->clear();
					DropDownLists.at(4)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {
						string newElement(ptrBaseClass.at(i)->getString());

						if (type_ptrBaseClasses.at(i) == STRING_BASE){
							DropDownLists.at(3)->add(newElement, 10 + i);
							DropDownLists.at(4)->add(newElement, 10 + i);
							
						}
						else if (type_ptrBaseClasses.at(i) == STRING_ID){
							DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);
							DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);
							
						}
						else if (type_ptrBaseClasses.at(i) == STRING_BIN) {
							DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);
							DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);
							
						}
					}


					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();
					break;
				}

				case TEST_STRING_GET_LENGTH: {

					short count = 0;
					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++)
						if (type_ptrBaseClasses.at(i) == STRING_BASE)
							count++;

					if (count < 1) {
						// ошибка 
						TextFields.at(0)->add("Слишком мало объектов базового класса");
						TextFields.at(0)->renderText();
						
						return;
					}

					Buttons.at(2)->show();
					Buttons.at(2)->render();

					DropDownLists.at(3)->show();

					nowOperation = TEST_STRING_GET_LENGTH;

					Labels.at(4)->show(true);
					Labels.at(4)->render();

					DropDownLists.at(3)->deleteItems()->clear();
					DropDownLists.at(4)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {
						string newElement(ptrBaseClass.at(i)->getString());

						if (type_ptrBaseClasses.at(i) == STRING_BASE) {
							DropDownLists.at(3)->add(newElement, 10 + i);
							DropDownLists.at(4)->add(newElement, 10 + i);
							
						}
						else if (type_ptrBaseClasses.at(i) == STRING_ID) {
							DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);
							DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);
							
						}
						else if (type_ptrBaseClasses.at(i) == STRING_BIN) {
							DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);
							DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);
							
						}
					}

					DropDownLists.at(3)->render();
					break;
				}
				

				case TEST_IDENTIFICATION_OPERATOR_TO_LOWER_CASE: {

					short count = 0;
					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++)
						if (type_ptrBaseClasses.at(i) == STRING_ID)
							count++;

					if (count < 1) {
						// ошибка 
						TextFields.at(0)->add("Слишком мало объектов класса идентификатора");
						TextFields.at(0)->renderText();
						
						return;
					}

					Buttons.at(2)->show();
					Buttons.at(2)->render();

					DropDownLists.at(3)->show();

					nowOperation = TEST_IDENTIFICATION_OPERATOR_TO_LOWER_CASE;

					Labels.at(4)->show(true);
					Labels.at(4)->render();

					DropDownLists.at(3)->deleteItems()->clear();
					DropDownLists.at(4)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {
						string newElement(ptrBaseClass.at(i)->getString());

						if (type_ptrBaseClasses.at(i) == STRING_BASE) {
							DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);
							DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);
						}
						else if (type_ptrBaseClasses.at(i) == STRING_ID) {
							DropDownLists.at(3)->add(newElement, 10 + i);
							DropDownLists.at(4)->add(newElement, 10 + i);
							
						}
						else if (type_ptrBaseClasses.at(i) == STRING_BIN) {
							DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);
							DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);
							
						}
					}

					DropDownLists.at(3)->render();

					break;
				}

				case TEST_IDENTIFICATION_OPERATOR_EQUAL: {

					short count = 0;
					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++)
						if (type_ptrBaseClasses.at(i) == STRING_ID)
							count++;

					if (count < 2) {
						// ошибка
						TextFields.at(0)->add("Слишком мало объектов класса идентификатора");
						TextFields.at(0)->renderText();
						
						return;
					}

					Buttons.at(2)->show();
					Buttons.at(2)->render();

					nowOperation = TEST_IDENTIFICATION_OPERATOR_EQUAL;

					DropDownLists.at(3)->show();
					DropDownLists.at(4)->show();

					Labels.at(4)->show(true);
					Labels.at(5)->show(true);
					Labels.at(4)->render();
					Labels.at(5)->render();

					DropDownLists.at(3)->deleteItems()->clear();
					DropDownLists.at(4)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {

						string newElement(ptrBaseClass.at(i)->getString());

						if (type_ptrBaseClasses.at(i) == STRING_BASE) {
							DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);
							DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);
								
						}
						else if (type_ptrBaseClasses.at(i) == STRING_ID) {
							DropDownLists.at(3)->add(newElement, 10 + i);
							DropDownLists.at(4)->add(newElement, 10 + i);
								
						}
						else if (type_ptrBaseClasses.at(i) == STRING_BIN) {
							DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);
							DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);
								
						}
					}

					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();

					break;
				}

				case TEST_IDENTIFICATION_OPERATOR_SUBTRACTION: {

					short count = 0;
					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++)
						if (type_ptrBaseClasses.at(i) == STRING_ID)
							count++;

					if (count < 2) {
						// ошибка 
						TextFields.at(0)->add("Слишком мало объектов класса идентификатора");
						TextFields.at(0)->renderText();
						
						return;
					}

					Buttons.at(2)->show();
					Buttons.at(2)->render();

					nowOperation = TEST_IDENTIFICATION_OPERATOR_SUBTRACTION;

					DropDownLists.at(3)->show();
					DropDownLists.at(4)->show();

					Labels.at(4)->show(true);
					Labels.at(5)->show(true);
					Labels.at(4)->render();
					Labels.at(5)->render();

					DropDownLists.at(3)->deleteItems()->clear();
					DropDownLists.at(4)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {
	
						string newElement(ptrBaseClass.at(i)->getString());

						if (type_ptrBaseClasses.at(i) == STRING_BASE) {
							DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);
							DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);
								
						}
						else if (type_ptrBaseClasses.at(i) == STRING_ID) {
							DropDownLists.at(3)->add(newElement, 10 + i);
							DropDownLists.at(4)->add(newElement, 10 + i);
								
						}
						else if (type_ptrBaseClasses.at(i) == STRING_BIN) {
							DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);
							DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);
								
						}
						
					}

					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();

					break;
				}

				case TEST_IDENTIFICATION_INDEX_OF: {

					short count = 0;
					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++)
						if (type_ptrBaseClasses.at(i) == STRING_ID)
							count++;

					if (count < 1) {
						// ошибка 
						TextFields.at(0)->add("Слишком мало объектов класса идентификатора");
						TextFields.at(0)->renderText();

						return;
					}

					Buttons.at(2)->show();
					Buttons.at(2)->render();

					DropDownLists.at(3)->show();

					Labels.at(6)->show(true);
					Labels.at(6)->render();

					Inputs.at(1)->show();
					Inputs.at(1)->render();

					nowOperation = TEST_IDENTIFICATION_INDEX_OF;

					Labels.at(4)->show(true);
					Labels.at(4)->render();

					DropDownLists.at(3)->deleteItems()->clear();
					DropDownLists.at(4)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {
						string newElement(ptrBaseClass.at(i)->getString());

						if (type_ptrBaseClasses.at(i) == STRING_BASE) {
							DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);
							DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);
						}
						else if (type_ptrBaseClasses.at(i) == STRING_ID) {
							DropDownLists.at(3)->add(newElement, 10 + i);
							DropDownLists.at(4)->add(newElement, 10 + i);

						}
						else if (type_ptrBaseClasses.at(i) == STRING_BIN) {
							DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);
							DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);

						}
					}

					DropDownLists.at(3)->render();
					
					break;
				}


				case TEST_BINARY_REVERSE: {

					short count = 0;
					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++)
						if (type_ptrBaseClasses.at(i) == STRING_BIN)
							count++;

					if (count < 1) {
						// ошибка 
						TextFields.at(0)->add("Слишком мало объектов класа десятичного числа");
						TextFields.at(0)->renderText();
						
						return;
					}

					Buttons.at(2)->show();
					Buttons.at(2)->render();

					nowOperation = TEST_BINARY_REVERSE;

					DropDownLists.at(3)->show();

					Labels.at(4)->show(true);
					Labels.at(4)->render();

					DropDownLists.at(3)->deleteItems()->clear();
					DropDownLists.at(4)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {
						
						string newElement(ptrBaseClass.at(i)->getString());

						if (type_ptrBaseClasses.at(i) == STRING_BASE) {
							DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);
							DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);
								
						}
						else if (type_ptrBaseClasses.at(i) == STRING_ID) {
							DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);
							DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);
								
						}
						else if (type_ptrBaseClasses.at(i) == STRING_BIN) {
							DropDownLists.at(3)->add(newElement, 10 + i);
							DropDownLists.at(4)->add(newElement, 10 + i);
								
						}
						
					}

					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();

					break;
				}
					
				case TEST_BINARY_SUBTRACTION: {

					short count = 0;
					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++)
						if (type_ptrBaseClasses.at(i) == STRING_BIN)
							count++;

					if (count < 2) {
						// ошибка 
						TextFields.at(0)->add("Слишком мало объектов класса двоичного числа");
						TextFields.at(0)->renderText();
						
						return;
					}

					Buttons.at(2)->show();
					Buttons.at(2)->render();

					nowOperation = TEST_BINARY_SUBTRACTION;

					DropDownLists.at(3)->show();
					DropDownLists.at(4)->show();

					Labels.at(4)->show(true);
					Labels.at(5)->show(true);
					Labels.at(4)->render();
					Labels.at(5)->render();

					DropDownLists.at(3)->deleteItems()->clear();
					DropDownLists.at(4)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {
						
						string newElement(ptrBaseClass.at(i)->getString());

						if (type_ptrBaseClasses.at(i) == STRING_BASE) {
							DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);
							DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);
								
						}
						else if (type_ptrBaseClasses.at(i) == STRING_ID) {
							DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);
							DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);
								
						}
						else if (type_ptrBaseClasses.at(i) == STRING_BIN) {
							DropDownLists.at(3)->add(newElement, 10 + i);
							DropDownLists.at(4)->add(newElement, 10 + i);
								
						}
					}

					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();

					break;
				}

				default: break;
				}
			}
			else {
				if (ItemLists.at(i)->open()) {
					ItemLists.at(i)->open(false);
					ItemLists.at(i)->render();
				}
			}
		}
	}


	for (int i = 0; i < DropDownLists.size(); i++) 
	{
		int flag = DropDownLists.at(i)->checkItemHover(x, y);

		if (DropDownLists.at(i)->checkHover(x, y)) {

			if (!DropDownLists.at(i)->open()) {

				for (int j = 0; j < DropDownLists.size(); j++) {
					if (DropDownLists.at(j)->open()) {
						DropDownLists.at(j)->open(false);
						DropDownLists.at(j)->render();
					}
				}

				DropDownLists.at(i)->open(true);
			}
			else 
				DropDownLists.at(i)->open(false);
			
			DropDownLists.at(i)->render();
		}
		else if (flag)
		{
			DropDownLists.at(i)->setValue(DropDownLists.at(i)->getItems().at(flag - 10)->text);
			DropDownLists.at(i)->open(false);
			DropDownLists.at(i)->render();

		
					
		}
		else {
			if (DropDownLists.at(i)->open()) {
				DropDownLists.at(i)->open(false);
				DropDownLists.at(i)->render();
			}
		}
	}
}

void Interface::keyDown(SDL_Event* event)
{
	switch (event->key.keysym.sym)
	{

	case SDLK_RETURN:
		cout << "Нажат Enter в APP" << endl;
		break;

	}
}