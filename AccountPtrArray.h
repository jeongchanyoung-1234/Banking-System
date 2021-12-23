#pragma once
#include <iostream>
#include "Account.h"


using std::cout;
using std::cin;
using std::endl;

typedef Account* ACC_PTR;

/*
�̸�: AccountPtrArray
����: �����
*/
class AccountPtrArray
{
private:
	ACC_PTR* arr;
	int arrlen;

	AccountPtrArray(const AccountPtrArray& copy) {};
	void operator=(const AccountPtrArray& ref) {};
public:
	AccountPtrArray(int len);
	ACC_PTR& operator[](int idx);
	ACC_PTR operator[](int idx) const;
	~AccountPtrArray();
};