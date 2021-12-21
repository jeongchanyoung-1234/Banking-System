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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����\n" << endl;

	cin >> option;
	cout << "����: " << option << endl << endl;

	return option;
}

void AccountHandler::OpenAccount(void)
{
	int accountId;
	char name[20];
	int accountBalance;

	cout << "[���°���]" << endl << "����ID: ";
	cin >> accountId;
	cout << "�� ��: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> accountBalance;

	customers[NumCustomer++].SetInfo(accountId, name, accountBalance);

	cout << "���� ������ �Ϸ�Ǿ����ϴ�.\n" << endl;
}

void AccountHandler::Deposit(void)
{
	int id, amount, flg = 1;

	cout << "[��    ��]" << endl << "����ID: ";
	cin >> id;
	while (1)
	{
		cout << "�Աݾ�: ";
		cin >> amount;
		if (amount <= 0) cout << "�Աݾ��� 0 �����Դϴ�." << endl;
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
	case 0: cout << "�Ա��� �Ϸ�Ǿ����ϴ�.\n\n"; break;
	case 1: cout << "�������� �ʴ� ID�Դϴ�.\n\n"; break;
	}
}

void AccountHandler::Withdraw(void)
{
	int id, amount, flg = 1;

	cout << "[��    ��]" << endl << "����ID: ";
	cin >> id;
	while (1)
	{
		cout << "��ݾ�: ";
		cin >> amount;
		if (amount <= 0) cout << "��ݾ��� 0 �����Դϴ�." << endl;
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
	case 0: cout << "����� �Ϸ�Ǿ����ϴ�.\n\n"; break;
	case 1: cout << "�������� �ʴ� ID�Դϴ�.\n\n"; break;
	case 2: cout << "�ܾ��� �����մϴ�.\n\n"; break;
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