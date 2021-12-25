#pragma once
#include <iostream>

using std::ostream;
using std::istream;

/*
�̸�: String
����: �ڵ����� ���� �޸� �Ҵ� �� ������ ����ϴ� Ŀ���� ���ڿ� ��ü
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