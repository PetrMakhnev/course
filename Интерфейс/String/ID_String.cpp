#include "ID_String.h"

unsigned int ID_String::calls = 0;

// Конструтор класса, принимающий на вход СИ-строку
ID_String::ID_String(char* _str) : String(_str)
{
	if (!isCorrect((char*)_str)) {
		str = new char;
		str = '\0';
		length = 0;
	}

	cout << "Производный класс 'Строка-идентификатор'. Сработал конструктор с СИ-строкой" << endl;
}

// Конструктор как и предыдущий только принимает вот такое -> "строка"
ID_String::ID_String(const char* _str) : String(_str)
{
	if (!isCorrect((char*)_str)) {
		str = new char;
		str = '\0';
		length = 0;
	}

	cout << "Производный класс 'Строка-идентификатор'. Сработал конструктор с константной СИ-строкой" << endl;
}

ID_String::~ID_String()
{
	cout << "Производный класс 'Строка-идентификатор'. Сработал деструктор" << endl;
}

// Конструктор копирования
ID_String::ID_String(const ID_String& obj) : String(obj)
{
	if (!isCorrect((char*)obj.str)) {
		str = new char;
		str = '\0';
		length = 0;
	}

	calls++;

	cout << "Производный класс 'Строка-идентификатор'. Конструктор копирования сработал " << calls << "-раз" << endl;
}

bool ID_String::isCorrect(char* _str)
{
	cout << "Производный класс 'Строка-идентификатор'. Сработала функция проверки корректности строки" << endl;

	// Если первый символ это буква или подчеркивание
	if ((isalpha(_str[0]) || _str[0] == '_') && _str != nullptr) {
		// Идем по всем символам строки
		for (size_t i = 1; i < length; i++) {
			// В том случае, если мы натыкаемся на некорректный символ выходим
			if (!isalpha(_str[i]) && !isdigit(_str[i]) && _str[i] != '_')
			{
				if (str != nullptr) {
					str = new char;
					str = '\0';
					length = 0;
				}
				return false;
			}
		}
		return true;
	}
	return false;
}

void ID_String::toLowerCase()
{
	if (str != nullptr) {
		for (size_t i = 0; i < length; i++)
			if (isalpha(str[i]))
				str[i] = (char)tolower(str[i]);
	}
	else {
		str = new char;
		str = '\0';
	}
	cout << "Производный класс 'Строка-идентификатор'. Сработала функция приведения строки в нижний регистр" << endl;
}

int ID_String::indexOf(char symbol)
{
	for (size_t i = 0; i < length; i++)
		if (str[i] == symbol)
			return i;

	return -1;
}

ID_String& ID_String::operator-(const ID_String& obj)
{
	cout << "Производный класс 'Строка-идентификатор'. Сработала перегрузка оператора '-'" << endl;

	ID_String* backString = nullptr;

	if (str != nullptr) {

		char* _str = new char[length];

		if (_str != nullptr) {

			bool flag = true;
			unsigned int newLength = 0;

			for (size_t i = 0; i < length; i++) {
				for (size_t j = 0; j < obj.length; j++)
					if (str[i] == obj.str[j])
						flag = false;

				if (flag) {
					_str[newLength] = str[i];
					newLength++;
				}
				else
					flag = true;
			}

			

			if (newLength != 0) {
				_str[newLength] = '\0';
				backString = new ID_String(_str);
				delete[] _str;
			}
			else {
				delete[] _str;
				_str = nullptr;
				backString = new ID_String;
			}
			return *backString;
		}
	}
	else {
		backString = new ID_String((char *)'\0');
		return *backString;
	}
}