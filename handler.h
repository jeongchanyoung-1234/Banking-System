#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "account.h"

using std::cout;
using std::cin;
using std::endl;

enum { OPEN = 1, DEPOSIT, WITHDRAW, LIST, QUIT };

/*
이름: AccountHandler
유형: 기능 클래스
*/
class AccountHandler
{
private:
	Account** accounts;
	int NumAccount;
	enum ACCOUNT_TYPE {NORMAL = 1, HIGH_CREDIT};
public:
	AccountHandler();
	int ChooseOption(void) const;
	void OpenAccount(void);
	void Deposit(void);
	void Withdraw(void);
	void ShowAllInfo(void) const;
	~AccountHandler();
};