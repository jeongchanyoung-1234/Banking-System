#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "customer.h"
#include "coretools.h"

using std::cout;
using std::cin;
using std::endl;

int num_customers = 0; // ��ü ���� ��
Customer customerInfo[10]; // �� �����͸� �����ϴ� �迭

enum { OPEN = 1, DEPOSIT, WITHDRAW, LIST, QUIT };

int main(void)
{
	int option;
	int flg;

	while (1)
	{
		cout << "-----Menu-----" << endl;
		cout << "1. ���°���" << endl;
		cout << "2. �� ��" << endl;
		cout << "3. �� ��" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����\n" << endl;
		
		cin >> option;
		cout << "����: " << option << endl << endl;

		switch (option)
		{
		case OPEN: 
			open_account(); 
			break;
		case DEPOSIT: 
			deposit(); 
			break;
		case WITHDRAW: 
			withdraw(); 
			break;
		case LIST: 
			for (int i = 0; i < num_customers; i++)
				customerInfo[i].ShowCustomerInfo();
			break;
		case QUIT:
			cout << "�̿����ּż� �����մϴ�." << endl;
			return 0;
		default: 
			cout << "�߸��� �����Դϴ�." << endl;
		}
	}

	return 0;
}