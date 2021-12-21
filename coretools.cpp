#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "customer.h"

using std::cout;
using std::cin;
using std::endl;

void open_account(void)
{
	int accountId;
	char name[20];
	int accountBalance;

	cout << "[계좌개설]" << endl << "계좌ID: ";
	cin >> accountId;
	cout << "이 름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> accountBalance;

	Customer::customerInfo[Customer::num_customers++].SetInfo(accountId, name, accountBalance);

	cout << "계좌 개설이 완료되었습니다.\n" << endl;
}

void deposit(void)
{
	int id, amount, flg = 1;

	cout << "[입    금]" << endl << "계좌ID: ";
	cin >> id;
	while (1)
	{
		cout << "입금액: ";
		cin >> amount;
		if (amount <= 0) cout << "입금액이 0 이하입니다." << endl;
		else break;
	}

	for (int i = 0; i < Customer::num_customers; i++)
	{
		if (Customer::customerInfo[i].GetId() == id)
		{
			flg = Customer::customerInfo[i].AddBalance(amount);
			break;
		}
	}

	switch (flg)
	{
	case 0: cout << "입금이 완료되었습니다.\n\n"; break;
	case 1: cout << "존재하지 않는 ID입니다.\n\n"; break;
	}
}

void withdraw(void)
{
	int id, amount, flg = 1;

	cout << "[출    금]" << endl << "계좌ID: ";
	cin >> id;
	while (1)
	{
		cout << "출금액: ";
		cin >> amount;
		if (amount <= 0) cout << "출금액이 0 이하입니다." << endl;
		else break;
	}

	for (int i = 0; i < Customer::num_customers; i++)
	{
		if (Customer::customerInfo[i].GetId() == id)
		{
			flg = Customer::customerInfo[i].AddBalance(-amount);
			break;
		}
	}
	switch (flg)
	{
	case 0: cout << "출금이 완료되었습니다.\n\n"; break;
	case 1: cout << "존재하지 않는 ID입니다.\n\n"; break;
	case 2: cout << "잔액이 부족합니다.\n\n"; break;
	}
}
