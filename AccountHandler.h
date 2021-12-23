#pragma once
#include "AccountPtrArray.h"


/*
이름: AccountHandler
유형: 기능 클래스
*/
class AccountHandler
{
private:
	AccountPtrArray accounts;
	int NumAccount;
	enum ACCOUNT_TYPE {NORMAL = 1, HIGH_CREDIT};
public:
	enum { OPEN = 1, DEPOSIT, WITHDRAW, LIST, QUIT };
public:
	AccountHandler(int);
	int ChooseOption(void) const;
	void OpenAccount(void);
	void Deposit(void);
	void Withdraw(void);
	void ShowAllInfo(void) const;
	~AccountHandler();
};