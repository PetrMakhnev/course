#pragma once
#include "iostream"
using namespace std;

class String {
protected:
	char* str;
	unsigned int length;
private:
	static unsigned int calls;
public:
	String();
	String(const String& obj);
	String(char* _str);
	String(const char* _str);
	String(const char symbol);
	~String();
public:
	unsigned int getLength();
	void operator= (String& obj);

	char* getString();
};