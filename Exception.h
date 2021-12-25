#include <iostream>

using std::cout;
using std::endl;

class AccountException
{
public:
	virtual void what() = 0;
};

class LessThanZeroException: public AccountException
{
private:
	int money;
public:
	LessThanZeroException(int money) : money(money)
	{}
	void what()
	{
		cout << "[ERROR] �Է��� �ݾ� " << money << "���� 0���� �۽��ϴ�." << endl << endl;
	}
};

class IdExistException : public AccountException
{
private:
	int id;
public:
	IdExistException(int id): id(id)
	{}
	void what()
	{
		cout << "[ERROR] �Է��� ID " << id << "�� �̹� �����մϴ�." << endl << endl;
	}
};
class IdDoNotExistException: public AccountException
{
private:
	int id;
public:
	IdDoNotExistException(int id) : id(id)
	{}
	void what()
	{
		cout << "[ERROR] �Է��� ID " << id << "�� �������� �ʽ��ϴ�." << endl << endl;
	}
};

class LackOfBalacneException: public AccountException
{
private:
	int balance, amount;
public:
	LackOfBalacneException(int balance, int amount):balance(balance), amount(amount)
	{}
	void what()
	{
		cout << "[ERROR] �ܾ��� �����մϴ� (���� �ܾ�: " << balance << ", ��� ��û��: " << amount << ')' << endl << endl;
	}
};

class AccountTypeError : public AccountException
{
private:
	int typ;
public:
	AccountTypeError(int typ): typ(typ)
	{}
	void what()
	{
		cout << "[ERROR] " << typ << "�� �������� �ʴ� �����Դϴ�." << endl << endl;
	}
};