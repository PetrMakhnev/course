#include "String.h"

unsigned int String::calls = 0;

String::String()
{
	str = new char;
	str = '\0';
	length = 0;

	cout << "Базовый класс. Сработал конструктор без параметров" << endl;

}

String::String(const String& obj)
{
	char* _str = new char[obj.length + 1];
	length = 0;

	if (_str != nullptr) {
		for (size_t i = 0; i < obj.length; i++)
			_str[i] = obj.str[i];

		_str[obj.length] = '\0';

		str = _str;
		length = obj.length;
	}
	else {
		str = new char;
		str = '\0';
	}
	
	calls++;

	

	cout << "Базовый класс. Конструктор копирования сработал в " << calls << "-раз" << endl;
}

String::String(char* new_str)
{
	bool flag = false;
	if (new_str[0] == '+')
		flag = true;

	int length_new_str = strlen(new_str) - flag;

	char* _str = new char[length_new_str + 1];
	length = 0;

	if (_str != nullptr) {
		for (size_t i = flag; i < length_new_str; i++)
			_str[i] = new_str[i];

		_str[length_new_str] = '\0';

		str = _str;
		length = length_new_str;
	}
	else {
		str = new char;
		str = '\0';
	}

	cout << "Базовый класс. Сработал конструктор с СИ-строкой" << endl;
}

String::String(const char* new_str)
{
	bool flag = false;
	if (new_str[0] == '+')
		flag = true;

	int length_new_str = strlen(new_str) - flag;

	char* _str = new char[length_new_str + 1];
	length = 0;

	if (_str != nullptr) {
		for (size_t i = flag; i < length_new_str + flag; i++)
			_str[i - flag] = new_str[i];

		_str[length_new_str] = '\0';

		str = _str;
		length = length_new_str;
	}
	else {
		str = new char;
		str = '\0';
	}

	cout << "Базовый класс. Сработал конструктор с константной СИ-строкой" << endl;
}

String::String(const char symbol)
{
	char* _str = new char;
	*_str = symbol;
	str = _str;
	length = strlen(_str);

	cout << "Базовый класс. Сработал конструктор с одним символом" << endl;
}

String::~String()
{
	if (str != nullptr)
		delete[] str;

	cout << "Базовый класс. Сработал деструктор" << endl;
}

unsigned int String::getLength()
{
	cout << "Сработала функция получения длины" << endl;
	return length;
}

void String::operator=(String& obj)
{
	char* _str = new char[obj.length + 1];
	length = 0;
		
	if (_str != nullptr) {
		for (size_t i = 0; i < obj.length; i++)
			_str[i] = obj.str[i];

		_str[obj.length] = '\0';

		str = _str;
		length = obj.length;
	}
	else {
		str = new char;
		str = '\0';
	}

	cout << "Сработала перегрузка операции '='" << endl;
}

char* String::getString()
{
	return str;
}
