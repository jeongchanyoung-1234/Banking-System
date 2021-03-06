#include <iostream>
#include <cstring>
#include "Account.h"
#define DEPOSIT_ADD_INTEREST(interest)	money + (int)(Account::GetBalance() * ((double)(interest) / 100.0))

using std::cin;
using std::cout;
using std::endl;


Account::Account(const int id, const String name, const int balance)
	:id(id), name(name), balance(balance)
{}

Account::Account(const Account& copy)
	:id(copy.id), name(copy.name), balance(copy.balance)
{}

Account& Account::operator=(const Account& ref)
{
	id = ref.id;
	name = ref.name;
	balance = ref.balance;

	return *this;
}

int Account::GetId(void) const
{
	return id;
}
String Account::GetName(void) const
{
	return name;
}
int Account::GetBalance(void) const
{
	return balance;
}

void Account::AddBalance(int money)
{
	balance += money;
}

void Account::ShowAccountInfo(void) const
{
	cout << "????ID: " << id << endl;
	cout << "?? ??: " << name << endl;
	cout << "?ܾ?: " << balance << endl;
}

// NormalAccount
NormalAccount::NormalAccount(const int id, const String name, const int balance, const int interest)
	:Account(id, name, balance), interestRatio(interest)
{}

int NormalAccount::GetInterestRatio(void) const
{
	return interestRatio;
}

void NormalAccount::AddBalance(int money)
{
	Account::AddBalance(DEPOSIT_ADD_INTEREST(interestRatio));
}

void NormalAccount::ShowAccountInfo(void) const
{
	Account::ShowAccountInfo();
	cout << "??????: " << interestRatio << "%" << endl;
}

// HighCreditAccount
HighCreditAccount::HighCreditAccount(const int id, const String name, const int balance, const int interest, const char credit)
	: NormalAccount(id, name, balance, interest), credit(credit)
{}

int HighCreditAccount::GetCredit(void) const
{
	return credit;
}

void HighCreditAccount::AddBalance(int money)
{
	int creditInterest;
	switch (credit)
	{
	case 'A': creditInterest = 7; break;
	case 'B': creditInterest = 4; break;
	case 'C': creditInterest = 2; break;
	}

	int newInterestRatio = NormalAccount::GetInterestRatio() + creditInterest;
	Account::AddBalance(DEPOSIT_ADD_INTEREST(newInterestRatio));
}

void HighCreditAccount::ShowAccountInfo(void) const
{
	NormalAccount::ShowAccountInfo();
	cout << "?ſ뵵: " << credit << endl;
}