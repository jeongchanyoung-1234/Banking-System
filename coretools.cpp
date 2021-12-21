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

	cout << "[���°���]" << endl << "����ID: ";
	cin >> accountId;
	cout << "�� ��: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> accountBalance;

	Customer::customerInfo[Customer::num_customers++].SetInfo(accountId, name, accountBalance);

	cout << "���� ������ �Ϸ�Ǿ����ϴ�.\n" << endl;
}

void deposit(void)
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
	case 0: cout << "�Ա��� �Ϸ�Ǿ����ϴ�.\n\n"; break;
	case 1: cout << "�������� �ʴ� ID�Դϴ�.\n\n"; break;
	}
}

void withdraw(void)
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
	case 0: cout << "����� �Ϸ�Ǿ����ϴ�.\n\n"; break;
	case 1: cout << "�������� �ʴ� ID�Դϴ�.\n\n"; break;
	case 2: cout << "�ܾ��� �����մϴ�.\n\n"; break;
	}
}
