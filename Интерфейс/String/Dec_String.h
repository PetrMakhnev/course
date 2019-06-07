#pragma once
#include "string.h"

class DEC_String : public String {
private:
	static unsigned int calls;
public:
	DEC_String() : String() {};
	DEC_String(const DEC_String& obj);
	DEC_String(char* _str);
	DEC_String(const char* _str);
	~DEC_String();

public:
	bool isCorrect(char* str);
	bool isUnsignedInt();
	int operator- (DEC_String& obj);
};