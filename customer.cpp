#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "customer.h"

using std::cin;
using std::cout;
using std::endl;

// Constructor
Customer::Customer() {};
Customer::Customer(const Customer& copy)
	:accountId(copy.accountId), accountBalance(copy.accountBalance)
{
	name = new char[strlen(copy.name) + 1];
	strcpy(name, copy.name);
}

// getter
int Customer::GetId(void) const
{
	return accountId;
}
char* Customer::GetName(void) const
{
	return name;
}
int Customer::GetBalance(void) const
{
	return accountBalance;
}

// setter
void Customer::SetInfo(int accountId, char* name, int accountBalance)
{
	int len = strlen(name) + 1;
	this->name = new char[len];

	this->accountId = accountId;
	strcpy(this->name, name);
	this->accountBalance = accountBalance;
}

// utils
int Customer::AddBalance(int money)
{
	if (accountBalance + money < 0)
	{
		return 2;
	}
	accountBalance += money;
	return 0;
}
void Customer::ShowCustomerInfo(void) const
{
	cout << "°èÁÂID: " << accountId << endl;
	cout << "ÀÌ ¸§: " << name << endl;
	cout << "ÀÜ¾×: " << accountBalance << endl << endl;
}

// deconstructor
Customer::~Customer()
{
	delete[] name;
}
