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

				cout << count_element << endl;

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
				

				if (count_ready + 1 == count_element) {

					Labels.at(1)->setText("All classes has filled");
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
					char* count_text = new char[5];
					_itoa(count_ready + 2, count_text, 10);
					string countText(count_text);

					Labels.at(1)->setText("Enter " + countText + "-th element");
					Labels.at(1)->render();

				}
				
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

					DropDownLists.at(2)->add("Base class: " + value, 10 + count_ready);
					DropDownLists.at(2)->render();
					break;

				case DROP_ID_CLASS:
					ptrBaseClass.push_back(new ID_String(value.c_str()));
					type_ptrBaseClasses.push_back(STRING_ID);

					DropDownLists.at(2)->add("Identificator class: " + value, 10 + count_ready);
					DropDownLists.at(2)->render();
					break;

				case DROP_DEC_CLASS:
					ptrBaseClass.push_back(new DEC_String(value.c_str()));
					type_ptrBaseClasses.push_back(STRING_DEC);

					DropDownLists.at(2)->add("Decimal class: " + value, 10 + count_ready);
					DropDownLists.at(2)->render();
					break;

				default: break;

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

					DropDownLists.at(3)->hide();
					DropDownLists.at(4)->hide();

					DropDownLists.at(2)->render();
					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();
					
					break;
				}
				case TEST_STRING_GET_LENGTH: {
					int indexFirst = DropDownLists.at(3)->getFlag() - 10;
					// TO DO Добавить вывод в интерфейс
					cout << ptrBaseClass.at(indexFirst)->getLength();

					DropDownLists.at(3)->hide();
					DropDownLists.at(4)->hide();

					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();
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

					DropDownLists.at(3)->hide();
					DropDownLists.at(4)->hide();

					DropDownLists.at(2)->render();
					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();

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

					DropDownLists.at(3)->hide();
					DropDownLists.at(4)->hide();

					DropDownLists.at(2)->render();
					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();

					break;
				}
				case TEST_IDENTIFICATION_OPERATOR_SUBSTRACTION: {

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

					DropDownLists.at(3)->hide();
					DropDownLists.at(4)->hide();

					DropDownLists.at(2)->render();
					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();
					break;
				}
				

				case TEST_DECIMAL_IS_UNSIGNED_INT: {

					int indexFirst = DropDownLists.at(3)->getFlag() - 10;

					/// ОСНОВНОЕ ПРИСВАИВАНИЕ
					bool isUnInt = ((DEC_String *)(ptrBaseClass.at(indexFirst)))->isUnsignedInt();
					
					if (isUnInt) {
						cout << "YES" << endl;
					}
					else {
						cout << "NO" << endl;
					}
					///

					DropDownLists.at(2)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {
						string newElement(ptrBaseClass.at(i)->getString());
						DropDownLists.at(2)->add(newElement, 10 + i);
					}

					DropDownLists.at(3)->hide();
					DropDownLists.at(4)->hide();

					DropDownLists.at(2)->render();
					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();
					break;
				}
				case TEST_DECIMAL_SUBTRACTION: {
					int indexFirst = DropDownLists.at(3)->getFlag() - 10;
					int indexSecond = DropDownLists.at(4)->getFlag() - 10;

					/// ОСНОВНОЕ ПРИСВАИВАНИЕ
					DEC_String* first = (DEC_String*)(ptrBaseClass.at(indexFirst));
					DEC_String* second = (DEC_String*)(ptrBaseClass.at(indexSecond));

					int result = *first - *second;

					cout << "Результат вычитания равен: " << result << endl;
					///

					DropDownLists.at(2)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {
						string newElement(ptrBaseClass.at(i)->getString());
						DropDownLists.at(2)->add(newElement, 10 + i);
					}

					DropDownLists.at(3)->hide();
					DropDownLists.at(4)->hide();

					DropDownLists.at(2)->render();
					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();
					break;
				}
				default: break;
				}

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

					nowOperation = TEST_STRING_EQUAL;

					DropDownLists.at(3)->show();
					DropDownLists.at(4)->show();

					short count = 0;
					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++)
						if (type_ptrBaseClasses.at(i) == STRING_BASE)
							count++;

					if (count < 2) {
						// ошибка 
						cout << "Слишком мало объектов базового класса (необходимо не меньше 2)" << endl;
						return;
					}

					DropDownLists.at(3)->deleteItems()->clear();
					DropDownLists.at(4)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {
						string newElement(ptrBaseClass.at(i)->getString());

						if (type_ptrBaseClasses.at(i) == STRING_BASE){
							DropDownLists.at(3)->add(newElement, 10 + i);
							DropDownLists.at(4)->add(newElement, 10 + i);						
						}
						else {
							DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);						
							DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);				
						}
					}


					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();
					break;
				}

				case TEST_STRING_GET_LENGTH: {

					nowOperation = TEST_STRING_GET_LENGTH;

					DropDownLists.at(3)->show();

					short count = 0;
					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++)
						if (type_ptrBaseClasses.at(i) == STRING_BASE)
							count++;

					if (count < 1) {
						// ошибка 
						cout << "Слишком мало объектов базового класса (необходимо не меньше 1)" << endl;
						return;
					}

					DropDownLists.at(3)->deleteItems()->clear();
					DropDownLists.at(4)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {
						string newElement(ptrBaseClass.at(i)->getString());

						if (type_ptrBaseClasses.at(i) == STRING_BASE) {
							DropDownLists.at(3)->add(newElement, 10 + i);
							DropDownLists.at(4)->add(newElement, 10 + i);
						}
						else {
							DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);
							DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);
						}
					}

					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();
					break;
				}
				

				case TEST_IDENTIFICATION_OPERATOR_TO_LOWER_CASE: {

					nowOperation = TEST_IDENTIFICATION_OPERATOR_TO_LOWER_CASE;

					DropDownLists.at(3)->show();
					//DropDownLists.at(4)->show();

					short count = 0;
					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++)
						if (type_ptrBaseClasses.at(i) == STRING_ID)
							count++;

					if (count < 1) {
						// ошибка 
						cout << "Слишком мало объектов базового класса (необходимо не меньше 1)" << endl;
						return;
					}


					DropDownLists.at(3)->deleteItems()->clear();
					DropDownLists.at(4)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {
						string newElement(ptrBaseClass.at(i)->getString());

						if (type_ptrBaseClasses.at(i) == STRING_ID) {
							DropDownLists.at(3)->add(newElement, 10 + i);
							DropDownLists.at(4)->add(newElement, 10 + i);
						}
						else {
							DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);
							DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);
						}
					}

					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();

					break;
				}

				case TEST_IDENTIFICATION_OPERATOR_EQUAL: {
					nowOperation = TEST_IDENTIFICATION_OPERATOR_EQUAL;

					DropDownLists.at(3)->show();
					DropDownLists.at(4)->show();

					short count = 0;
					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++)
						if (type_ptrBaseClasses.at(i) == STRING_ID)
							count++;

					if (count < 2) {
						// ошибка 
						cout << "Слишком мало объектов базового класса (необходимо не меньше 2)" << endl;
						return;
					}


					DropDownLists.at(3)->deleteItems()->clear();
					DropDownLists.at(4)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {
						if (type_ptrBaseClasses.at(i) == STRING_ID)
						{
							string newElement(ptrBaseClass.at(i)->getString());

							if (type_ptrBaseClasses.at(i) == STRING_ID) {
								DropDownLists.at(3)->add(newElement, 10 + i);
								DropDownLists.at(4)->add(newElement, 10 + i);
							}
							else {
								DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);
								DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);
							}
						}
					}

					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();

					break;
				}

				case TEST_IDENTIFICATION_OPERATOR_SUBSTRACTION: {

					nowOperation = TEST_IDENTIFICATION_OPERATOR_SUBSTRACTION;

					DropDownLists.at(3)->show();
					DropDownLists.at(4)->show();

					short count = 0;
					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++)
						if (type_ptrBaseClasses.at(i) == STRING_ID)
							count++;

					if (count < 2) {
						// ошибка 
						cout << "Слишком мало объектов базового класса (необходимо не меньше 2)" << endl;
						return;
					}


					DropDownLists.at(3)->deleteItems()->clear();
					DropDownLists.at(4)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {
						if (type_ptrBaseClasses.at(i) == STRING_ID)
						{
							string newElement(ptrBaseClass.at(i)->getString());

							if (type_ptrBaseClasses.at(i) == STRING_ID) {
								DropDownLists.at(3)->add(newElement, 10 + i);
								DropDownLists.at(4)->add(newElement, 10 + i);
							}
							else {
								DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);
								DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);
							}
						}
					}

					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();

					break;
				}


				case TEST_DECIMAL_IS_UNSIGNED_INT: {

					nowOperation = TEST_DECIMAL_IS_UNSIGNED_INT;

					DropDownLists.at(3)->show();

					short count = 0;
					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++)
						if (type_ptrBaseClasses.at(i) == STRING_DEC)
							count++;

					if (count < 1) {
						// ошибка 
						cout << "Слишком мало объектов базового класса (необходимо не меньше 1)" << endl;
						return;
					}

					DropDownLists.at(3)->deleteItems()->clear();
					DropDownLists.at(4)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {
						if (type_ptrBaseClasses.at(i) == STRING_DEC)
						{
							string newElement(ptrBaseClass.at(i)->getString());

							if (type_ptrBaseClasses.at(i) == STRING_DEC) {
								DropDownLists.at(3)->add(newElement, 10 + i);
								DropDownLists.at(4)->add(newElement, 10 + i);
							}
							else {
								DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);
								DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);
							}
						}
					}

					DropDownLists.at(3)->render();
					DropDownLists.at(4)->render();

					break;
				}
					
				case TEST_DECIMAL_SUBTRACTION: {

					nowOperation = TEST_DECIMAL_SUBTRACTION;

					DropDownLists.at(3)->show();
					DropDownLists.at(4)->show();

					short count = 0;
					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++)
						if (type_ptrBaseClasses.at(i) == STRING_DEC)
							count++;

					if (count < 2) {
						// ошибка 
						cout << "Слишком мало объектов базового класса (необходимо не меньше 2)" << endl;
						return;
					}

					DropDownLists.at(3)->deleteItems()->clear();
					DropDownLists.at(4)->deleteItems()->clear();

					for (size_t i = 0; i < type_ptrBaseClasses.size(); i++) {
						if (type_ptrBaseClasses.at(i) == STRING_DEC)
						{
							string newElement(ptrBaseClass.at(i)->getString());

							if (type_ptrBaseClasses.at(i) == STRING_DEC) {
								DropDownLists.at(3)->add(newElement, 10 + i);
								DropDownLists.at(4)->add(newElement, 10 + i);
							}
							else {
								DropDownLists.at(3)->add(newElement, 10 + i)->Block(true);
								DropDownLists.at(4)->add(newElement, 10 + i)->Block(true);
							}
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
					DropDownLists.at(j)->open(false);
					DropDownLists.at(j)->render();
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

			cout << flag << endl;
					
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