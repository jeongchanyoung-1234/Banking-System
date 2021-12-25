#include "AccountHandler.h"
#include "String.h"
#include "Exception.h"

using std::cout;
using std::cin;
using std::endl;

AccountHandler::AccountHandler(int len)
	:accounts(len), NumAccount(0)
{}

int AccountHandler::ChooseOption(void) const
{
	/*
	�Է�: NULL
	���: ����
	���: �Լ� ������� ���� �������� ���� ���·� ��ȯ
	*/

	int option;

	cout << "-----Menu-----" << endl;
	cout << "(1) ���°���" << endl;
	cout << "(2) �� ��" << endl;
	cout << "(3) �� ��" << endl;
	cout << "(4) �������� ��ü ���" << endl;
	cout << "(5) ���α׷� ����\n" << endl;

	cout << "[MESSAGE] ����� �����ϼ���: "; cin >> option; cout << endl;

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
	String name;
	int balance;
	int interest;
	int type;

	cout << "[�������� ����]" << endl;
	cout << "(1) ���뿹�ݰ���" << endl;
	cout << "(2) �ſ�ŷڰ���" << endl << endl;

	while (1)
	{
		try
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
			throw
				AccountTypeError(type);
		}
		catch (AccountException& expn)
		{
			expn.what();
		}
	}

	while (1)
	{
		try
		{
			cout << "����ID: "; cin >> id;
			if (CheckId(id) >= 0)
				throw IdExistException(id);
			cout << "�� ��: "; cin >> name;
			cout << "�Աݾ�: "; cin >> balance;
			if (balance < 0)
				throw LessThanZeroException(balance);
			cout << "������: "; cin >> interest;
			break;
		}
		catch (AccountException& expn)
		{
			expn.what();
		}
	}

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
	cout << endl << "[MESSAGE] ���� ������ �Ϸ�Ǿ����ϴ�.\n" << endl;
}

void AccountHandler::Deposit(void)
{
	/*
	�Է�: NULL
	���: NULL
	���: �Էµ� ���·� ���ڸ� ���ϸ� �Ա�
	*/
	int id, amount, idx;

	cout << "[��    ��]" << endl; 
	while (1)
	{
		try
		{
			cout << "����ID: "; cin >> id;
			idx = CheckId(id);
			if (idx < 0)
				throw IdDoNotExistException(id);
			break;
		}
		catch (IdDoNotExistException& expn)
		{
			expn.what();
		}
	}

	while (1)
	{
		try
		{
			cout << "�Աݾ�: "; cin >> amount;
			if (amount <= 0)
				throw LessThanZeroException(amount);

			accounts[idx]->AddBalance(amount);
			break;
		}
		catch (AccountException& expn)
		{
			expn.what();
		}
	}

	cout << "[MESSAGE] �Ա��� �Ϸ�Ǿ����ϴ�." << endl;
	accounts[idx]->ShowAccountInfo();
	cout << endl;
}

void AccountHandler::Withdraw(void)
{
	/*
	�Է�: NULL
	���: NULL
	���: ��ġ�� ���·κ��� ���
	*/
	int id, amount, idx;

	cout << "[��    ��]" << endl;
	while (1)
	{
		try
		{
			cout << "����ID: "; cin >> id;
			idx = CheckId(id);
			if (idx < 0)
				throw IdDoNotExistException(id);
			break;
		}
		catch (IdDoNotExistException& expn)
		{
			expn.what();
		}
	}

	while (1)
	{
		try
		{
			cout << "��ݾ�: "; cin >> amount;
			if (amount <= 0)
				throw LessThanZeroException(amount);

			int balance = accounts[idx]->GetBalance();
			if (balance < amount)
				throw LackOfBalacneException(balance, amount);

			accounts[idx]->AddBalance(-amount);
			break;
		}
		catch (AccountException& expn)
		{
			expn.what();
		}
	}

	cout << "[MESSAGE] ����� �Ϸ�Ǿ����ϴ�." << endl;
	accounts[idx]->ShowAccountInfo();
	cout << endl;
};

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
		accounts[i]->ShowAccountInfo();
		cout << endl;
	}
};

int AccountHandler::CheckId(int id) const
{
	for (int i = 0; i < NumAccount; i++)
	{
		if (accounts[i]->GetId() == id)
			return i;
	}
	return -1;
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < NumAccount; i++)
		delete accounts[i];
}