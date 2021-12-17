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

	cout << "[���°���]" << endl << "����ID: ";
	cin >> customer.accountId;

	cout << "�� ��: ";
	cin >> customer.name;

	cout << "�Աݾ�: ";
	cin >> customer.accountBalance;

	customerInfo[num_customers++] = customer;

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
	case 0: cout << "����� �Ϸ�Ǿ����ϴ�.\n\n"; break;
	case 1: cout << "�������� �ʴ� ID�Դϴ�.\n\n"; break;
	case 2: cout << "�ܾ��� �����մϴ�.\n\n"; break;
	}
}

void list_customer(void)
{
	for (int i = 0; i < num_customers; i++)
	{
		cout << "����ID: " << customerInfo[i].accountId << endl;
		cout << "�� ��: " << customerInfo[i].name << endl;
		cout << "�ܾ�: " << customerInfo[i].accountBalance << endl << endl;
	}
}
