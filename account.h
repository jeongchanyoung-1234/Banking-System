#pragma once
#include <iostream>
#include <cstring>
#include "String.h"
#define DEPOSIT_ADD_INTEREST(interest)	money + (int)(Account::GetBalance() * ((double)(interest) / 100.0))

using std::cin;
using std::cout;
using std::endl;

/*
�̸�: Account
����: �⺻ Ŭ����
*/
class Account
{
private:
	int id;
	String name;
	int balance;
public:
	Account(const int, const String, const int);
	Account(const Account&);
	Account& operator=(const Account&);

	int GetId(void) const;
	String GetName(void) const;
	int GetBalance(void) const;
	virtual int AddBalance(int);
	int SubBalance(int);
	virtual void ShowAccountInfo(void) const;
};

/*
�̸�: NormalAccount
����: ���� Ŭ����
*/
class NormalAccount: public Account
{
private:
	int interestRatio;
public:
	NormalAccount(const int, const String, const int, const int);

	int GetInterestRatio(void) const;
	virtual int AddBalance(int);
	virtual void ShowAccountInfo(void) const;
};

/*
�̸�: HighCreditAccount
����: ���� Ŭ����
*/
class HighCreditAccount: public NormalAccount
{
private:
	char credit;
public:
	HighCreditAccount(const int, const String, const int, const int, const char);

	int GetCredit(void) const;
	virtual int AddBalance(int);
	virtual void ShowAccountInfo(void) const;
};