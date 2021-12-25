#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "String.h"

using std::cin;
using std::cout;
using std::endl;



String::String()
{
	string = NULL;
}
String::String(char* inputString)
{
	string = new char[strlen(inputString) + 1];
	strcpy(string, inputString);
}
String::String(const String& copy)
{
	string = new char[strlen(copy.string) + 1];
	strcpy(string, copy.string);
}

size_t String::getLen() const
{
	return strlen(string);
}
String& String::operator=(const String& ref)
{
	if (string != NULL)
		delete[] string;
	string = new char[strlen(ref.string) + 1];
	strcpy(string, ref.string);
	return *this;
}

String String::operator+(const String& string)
{
	size_t thisLen = strlen(this->string);
	size_t totalLen = thisLen + strlen(string.string) + 1;
	char* newString = new char[totalLen];
	for (int i = 0; i < totalLen; i++)
	{
		if (i < thisLen)
		{
			newString[i] = (this->string)[i];
		}
		else
		{
			newString[i] = (string.string)[i - thisLen];
		}
	}
	newString[totalLen - 1] = '\0';
	String retObj(newString);
	delete[] newString;

	return retObj;
}
String& String::operator+=(const String& string)
{
	(*this) = operator+(string);
	return *this;
}
bool String::operator==(const String& string)
{
	return (strcmp(this->string, string.string) == 0) ? true : false;
}

String::~String()
{
	delete[] string;
}

ostream& operator<<(ostream& os, const String& ref)
{
	cout << ref.string;
	return os;
}

istream& operator>>(istream& is, String& ref)
{
	if (ref.string != NULL)
		delete[] ref.string;
	char input[100];
	cin >> input;
	ref = String(input);
	return is;
}
