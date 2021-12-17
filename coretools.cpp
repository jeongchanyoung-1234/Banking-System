#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "customer.h"

using std::cout;
using std::cin;
using std::endl;

extern int num_customers;
extern Customer customerInfo[100];

void open_account(void)
{
	Customer customer;

	cout << "[계좌개설]" << endl << "계좌ID: ";
	cin >> customer.accountId;

	cout << "이 름: ";
	cin >> customer.name;

	cout << "입금액: ";
	cin >> customer.accountBalance;

	customerInfo[num_customers++] = customer;

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

	for (int i = 0; i < num_customers; i++)
	{
		if (customerInfo[i].accountId == id)
		{
			customerInfo[i].accountBalance += amount;
			flg = 1;
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

	for (int i = 0; i < num_customers; i++)
	{
		if (customerInfo[i].accountId == id)
		{
			if (customerInfo[i].accountBalance >= amount)
			{
				customerInfo[i].accountBalance -= amount;
				flg = 0;
				break;
			}
			flg = 2;
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

void list_customer(void)
{
	for (int i = 0; i < num_customers; i++)
	{
		cout << "계좌ID: " << customerInfo[i].accountId << endl;
		cout << "이 름: " << customerInfo[i].name << endl;
		cout << "잔액: " << customerInfo[i].accountBalance << endl << endl;
	}
}
