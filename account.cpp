#include "account.h"



// Account
Account::Account(const int id, const char* name, const int balance)
	:id(id), balance(balance)
{
	this -> name = new char[strlen(name) + 1];
	strcpy(this -> name, name);
};

Account::Account(const Account& copy)
	:id(copy.id), balance(copy.balance)
{
	name = new char[strlen(copy.name) + 1];
	strcpy(name, copy.name);
}

int Account::GetId(void) const
{
	return id;
}
char* Account::GetName(void) const
{
	return name;
}
int Account::GetBalance(void) const
{
	return balance;
}

int Account::AddBalance(int money)
{
	balance += money;
	return 0;
}

int Account::SubBalance(int money)
{
	if (balance < money)
	{
		return 2;
	}
	balance -= money;
	return 0;
}

void Account::ShowAccountInfo(void) const
{
	cout << "계좌ID: " << id << endl;
	cout << "이 름: " << name << endl;
	cout << "잔액: " << balance << endl;
}

Account::~Account()
{
	delete[] name;
}

// NormalAccount
NormalAccount::NormalAccount(const int id, const char* name, const int balance, const int interest)
	:Account(id, name, balance), interestRatio(interest)
{};

int NormalAccount::GetInterestRatio(void) const
{
	return interestRatio;
};

int NormalAccount::AddBalance(int money)
{
	int res = Account::AddBalance(DEPOSIT_ADD_INTEREST(interestRatio));
	return res;
}

void NormalAccount::ShowAccountInfo(void) const
{
	Account::ShowAccountInfo();
	cout << "이자율: " << interestRatio << "%" << endl;
};

NormalAccount::~NormalAccount()
{};

// HighCreditAccount
HighCreditAccount::HighCreditAccount(const int id, const char* name, const int balance, const int interest, const char credit)
	: NormalAccount(id, name, balance, interest), credit(credit)
{};

int HighCreditAccount::GetCredit(void) const
{
	return credit;
}

int HighCreditAccount::AddBalance(int money)
{
	int creditInterest;
	switch (credit)
	{
	case 'A': creditInterest = 7; break;
	case 'B': creditInterest = 4; break;
	case 'C': creditInterest = 2; break;
	}

	int newInterestRatio = NormalAccount::GetInterestRatio() + creditInterest;
	int res = Account::AddBalance(DEPOSIT_ADD_INTEREST(newInterestRatio));
	return res;
}

void HighCreditAccount::ShowAccountInfo(void) const
{
	NormalAccount::ShowAccountInfo();
	cout << "신용도: " << credit << endl;
}

HighCreditAccount::~HighCreditAccount()
{};