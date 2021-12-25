#pragma once
#include <iostream>

using std::ostream;
using std::istream;

/*
이름: String
유형: 자동으로 동적 메모리 할당 및 해제를 담당하는 커스텀 문자열 객체
*/
class String
{
private:
	char* string;
public:
	String();
	String(char* inputString);
	String(const String& copy);

	size_t getLen() const;
	String& operator=(const String& ref);
	String operator+(const String& string);
	String& operator+=(const String& string);
	bool operator==(const String& string);
	friend ostream& operator<<(ostream& os, const String& string);
	friend istream& operator>>(istream& is, String& string);
	~String();
};