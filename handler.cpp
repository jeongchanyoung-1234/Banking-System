#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "customer.h"
#include "handler.h"

using std::cout;
using std::cin;
using std::endl;

AccountHandler::AccountHandler()
	:NumCustomer(0)
{
	customers = new Customer[10];
}

int AccountHandler::ChooseOption(void) const
{
	int option;

	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료\n" << endl;

	cin >> option;
	cout << "선택: " << option << endl << endl;

	return option;
}

void AccountHandler::OpenAccount(void)
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

	customers[NumCustomer++].SetInfo(accountId, name, accountBalance);

	cout << "계좌 개설이 완료되었습니다.\n" << endl;
}

void AccountHandler::Deposit(void)
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

	for (int i = 0; i < NumCustomer; i++)
	{
		if (customers[i].GetId() == id)
		{
			flg = customers[i].AddBalance(amount);
			break;
		}
	}

	switch (flg)
	{
	case 0: cout << "입금이 완료되었습니다.\n\n"; break;
	case 1: cout << "존재하지 않는 ID입니다.\n\n"; break;
	}
}

void AccountHandler::Withdraw(void)
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

	for (int i = 0; i < NumCustomer; i++)
	{
		if (customers[i].GetId() == id)
		{
			flg = customers[i].AddBalance(-amount);
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

void AccountHandler::ShowAllInfo(void) const
{
	for (int i = 0; i < NumCustomer; i++)
		customers[i].ShowCustomerInfo();
}

AccountHandler::~AccountHandler()
{
	delete[] customers;
}