#include "BIN_String.h"

unsigned int BIN_String::calls = 0;


// Конструтор класса, принимающий на вход СИ-строку
BIN_String::BIN_String(char* _str) : String(_str)
{
	if (!isCorrect(_str)) {
		str = new char;
		str = '\0';
		length = 0;
	}

	cout << "Производный класс 'Десятичная строка'. Сработал конструктор с СИ-строкой" << endl;
}

// Конструктор как и предыдущий только принимает вот такое -> "строка"
BIN_String::BIN_String(const char* _str) : String(_str)
{
	if (!isCorrect((char*)_str)) {
		str = new char;
		str = '\0';
		length = 0;
	}

	cout << "Производный класс 'Десятичная строка'. Сработал конструктор с константной СИ-строкой" << endl;
}

BIN_String::~BIN_String()
{
	cout << "Производный класс 'Десятичная строка'. Сработал деструктор" << endl;
}

// Конструктор копирования
BIN_String::BIN_String(const BIN_String& obj) : String(obj.str)
{
	if (!isCorrect(obj.str)) {
		str = new char;
		str = '\0';
		length = 0;
	}

	calls++;

	cout << "Производный класс 'Десятичная строка'. Конструктор копирования сработал " << calls << "-раз" << endl;
}

bool BIN_String::isCorrect(char* str)
{
	cout << "Производный класс 'Десятичная строка'. Сработала функция проверки корректности строки" << endl;

	for (size_t i = 1; i < length; i++)
		if (str[i] != '0' && str[i] != '1')
			return false;
			
	return true;
}

void BIN_String::invert()
{
	if (str != nullptr) {
		char* _str = new char[length + 1];

		for (size_t i = 0; i < length; i++) {
			if (str[i] == '0')
				_str[i] = '1';
			else
				_str[i] = '0';
		}

		_str[length] = '\0';


		delete[] str;
		str = _str;
	}
	else {
		str = new char;
		str = '\0';
	}
}

BIN_String& BIN_String::operator-(BIN_String& obj)
{
	char* _str = new char[length + 1];
	char* result = new char[length + 1];

	if (length > obj.length) {
		
		for (int j = 0; j < length - obj.length; j++)
			_str[j] = '0';
		
		strcpy(_str + length - obj.length, obj.str);

		char symbol;
		bool flag = false;
		for (size_t i = length - 1; i > 0; i--) {
			symbol = _str[i];
			if (str[i] == '1' && symbol == '1') {
				if (flag)
					result[i] = '1';
				else
					result[i] = '0';

				flag = true;
			}
			else if (str[i] == '0' && symbol == '1' || str[i] == '1' && symbol == '0') {
				if (flag) {
					result[i] = '0';
					flag = true;
				}
				else {
					result[i] = '1';
					flag = false;
				}
			}
			else {
				if (flag) {
					result[i] = '1';
					flag = false;
				}
				else {
					result[i] = '0';
					flag = false;
				}

			}
		}

		if (flag) 
			result[0] = '1';
		else 
			result[0] = '0';
		
		result[length] = '\0';
	}
	else if (length < obj.length) {

		for (int j = 0; j < obj.length - length; j++)
			_str[j] = '0';


		strcpy(_str + obj.length - length, str);


		char symbol;
		bool flag = false;
		for (size_t i = obj.length - 1; i > 0; i--) {
			symbol = obj.str[i];
			if (_str[i] == '1' && symbol == '1') {
				if (flag)
					result[i] = '0';
				else
					result[i] = '1';

				flag = true;
			}
			else if (_str[i] == '0' && symbol == '1' || _str[i] == '1' && symbol == '0') {
				if (flag) {
					result[i] = '0';
					flag = true;
				}
				else {
					result[i] = '1';
					flag = false;
				}

			}
		}

		if (flag) {
			result[0] = '1';
			result[length] = '\0';
		}
		else {
			result[0] = '0';
			result[length] = '\0';
		}
	}
	else {

		char symbol;
		bool flag = false;
		for (size_t i = obj.length - 1; i > 0; i--) {
			symbol = obj.str[i];
			if (str[i] == '1' && symbol == '1') {
				if (flag)
					result[i] = '0';
				else
					result[i] = '1';

				flag = true;
			}
			else if (str[i] == '0' && symbol == '1' || str[i] == '1' && symbol == '0') {
				if (flag) {
					result[i] = '0';
					flag = true;
				}
				else {
					result[i] = '1';
					flag = false;
				}

			}
			else {
				if (flag) {
					result[i] = '1';
					flag = false;
				}
				else {
					result[i] = '0';
					flag = false;
				}

			}
		}

		if (flag) {
			result[0] = '1';
			result[length] = '\0';
		}
		else {
			result[0] = '0';
			result[length] = '\0';
		}
	}


	BIN_String * ret = new BIN_String(result);
	return *ret;
}
