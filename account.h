#pragma once
#include "String.h"

/*
이름: Account
유형: 기본 클래스
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
이름: NormalAccount
유형: 유도 클래스
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
이름: HighCreditAccount
유형: 유도 클래스
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