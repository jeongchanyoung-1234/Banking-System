#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>

/*
이름: Account
유형: 기본 클래스
*/
class Account
{
private:
	int id;
	char* name;
	int balance;
public:
	Account(const int, const char*, const int);
	explicit Account(const Account&);
	int GetId(void) const;
	char* GetName(void) const;
	int GetBalance(void) const;
	virtual int AddBalance(int);
	int SubBalance(int);
	virtual void ShowAccountInfo(void) const;
	virtual ~Account();
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
	NormalAccount(const int, const char*, const int, const int);
	explicit NormalAccount(const NormalAccount&);
	int GetInterestRatio(void) const;
	virtual int AddBalance(int);
	virtual void ShowAccountInfo(void) const;
	~NormalAccount();
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
	HighCreditAccount(const int, const char*, const int, const int, const char);
	explicit HighCreditAccount(const HighCreditAccount&);
	int GetCredit(void) const;
	virtual int AddBalance(int);
	virtual void ShowAccountInfo(void) const;
	~HighCreditAccount();
};