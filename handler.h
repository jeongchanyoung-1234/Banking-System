#pragma once
#include "account.h"

/*
�̸�: AccountHandler
����: ��� Ŭ����
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