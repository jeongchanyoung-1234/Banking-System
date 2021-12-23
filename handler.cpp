#include "handler.h"

AccountHandler::AccountHandler()
	:NumAccount(0)
{
	accounts = new Account*[10];
}

int AccountHandler::ChooseOption(void) const
{
	/*
	�Է�: NULL
	���: ����
	���: �Լ� ������� ���� �������� ���� ���·� ��ȯ
	*/

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
	/*
	�Է�: NULL
	���: NULL
	���: �з�(�������, �ŷڰ���)�� ���� ���� ����
	*/

	int id;
	char name[20];
	int balance;
	int interest;
	int type;

	cout << "[�������� ����]" << endl;
	cout << "(1) ���뿹�ݰ���" << endl;
	cout << "(2) �ſ�ŷڰ���" << endl << endl;

	while (1)
	{
		cout << "���� :"; cin >> type; cout << endl;
		if (type == ACCOUNT_TYPE::NORMAL)
		{
			cout << "[���뿹�ݰ��� ����]" << endl;
			break;
		}
		else if (type == ACCOUNT_TYPE::HIGH_CREDIT)
		{
			cout << "[�ſ�ŷڰ��� ����]" << endl;
			break;
		}
		cout << "�߸��� �����Դϴ�." << endl;
	}
	cout << "����ID: "; cin >> id;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << "������: "; cin >> interest;

	if (type == ACCOUNT_TYPE::HIGH_CREDIT)
	{
		char credit;
		cout << "�ſ���(A, B, C): "; cin >> credit;

		accounts[NumAccount++] = new HighCreditAccount(id, name, balance, interest, credit);
	}
	else
	{
		accounts[NumAccount++] = new NormalAccount(id, name, balance, interest);
	}
	cout << endl << "���� ������ �Ϸ�Ǿ����ϴ�.\n" << endl;
}

void AccountHandler::Deposit(void)
{
	/*
	�Է�: NULL
	���: NULL
	���: �Էµ� ���·� ���ڸ� ���ϸ� �Ա�
	*/
	int id, amount, flg = 1;

	cout << "[��    ��]" << endl; 
	cout << "����ID: "; cin >> id;
	while (1)
	{
		cout << "�Աݾ�: "; cin >> amount;
		if (amount <= 0) cout << "�Աݾ��� 0 �����Դϴ�." << endl;
		else break;
	}

	for (int i = 0; i < NumAccount; i++)
	{
		if (accounts[i] -> GetId() == id)
		{
			flg = accounts[i] -> AddBalance(amount);
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
	/*
	�Է�: NULL
	���: NULL
	���: ��ġ�� ���·κ��� ���
	*/
	int id, amount, flg = 1;

	cout << "[��    ��]" << endl;
	cout << "����ID: "; cin >> id;
	while (1)
	{
		cout << "��ݾ�: "; cin >> amount;
		if (amount <= 0) cout << "��ݾ��� 0 �����Դϴ�." << endl;
		else break;
	}

	for (int i = 0; i < NumAccount; i++)
	{
		if (accounts[i] -> GetId() == id)
		{
			flg = accounts[i] -> SubBalance(amount);
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
	/*
	�Է�: NULL
	���: NULL
	���: ���� ����� ��� ���������� �����ð� ������ ���
	*/
	for (int i = 0; i < NumAccount; i++)
	{
		cout << "====" << i + 1 << "====" << endl;
		accounts[i] -> ShowAccountInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler()
{
	delete[] accounts;
}