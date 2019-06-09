#pragma once
#include "string.h"

class BIN_String : public String {
private:
	static unsigned int calls;
public:
	BIN_String() : String() {};
	BIN_String(const BIN_String& obj);
	BIN_String(char* _str);
	BIN_String(const char* _str);
	~BIN_String();

public:
	bool isCorrect(char* str);
	void invert();
	BIN_String& operator- (BIN_String& obj);
};
