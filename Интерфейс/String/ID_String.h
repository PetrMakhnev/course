#pragma once
#include "string.h"

class ID_String : public String{
private:
	static unsigned int calls;

public:
	ID_String() : String(){};
	ID_String(const ID_String& obj);
	ID_String(char* _str);
	ID_String(const char* _str);
	~ID_String();

public:
	bool isCorrect(char* str);
	void toLowerCase();
	void print();
	int indexOf(char symbol);
	ID_String& operator- (const ID_String& obj);

};