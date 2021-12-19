#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "customer.h"

using std::cin;
using std::cout;
using std::endl;

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
void Customer::AddBalance(int money)
{
	accountBalance += money;
}
void Customer::ShowCustomerInfo(void) const
{
	cout << "����ID: " << accountId << endl;
	cout << "�� ��: " << name << endl;
	cout << "�ܾ�: " << accountBalance << endl << endl;
}

// deconstructor
Customer::~Customer()
{
	delete[] name;
}