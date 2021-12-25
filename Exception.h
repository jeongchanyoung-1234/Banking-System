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
		cout << "[ERROR] 입력한 금액 " << money << "원이 0보다 작습니다." << endl << endl;
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
		cout << "[ERROR] 입력한 ID " << id << "가 이미 존재합니다." << endl << endl;
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
		cout << "[ERROR] 입력한 ID " << id << "가 존재하지 않습니다." << endl << endl;
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
		cout << "[ERROR] 잔액이 부족합니다 (계좌 잔액: " << balance << ", 출금 요청액: " << amount << ')' << endl << endl;
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
		cout << "[ERROR] " << typ << "은 존재하지 않는 유형입니다." << endl << endl;
	}
};