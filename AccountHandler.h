#pragma once
#include "BoundCheckArray.h"

typedef Account* ACC_PTR;

/*
�̸�: AccountHandler
����: ��� Ŭ����
*/
class AccountHandler
{
private:
	BoundCheckArray<ACC_PTR> accounts;
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