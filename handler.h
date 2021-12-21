#pragma once
#include "customer.h"

class AccountHandler
{
private:
	Customer* customers;
	int NumCustomer;
public:
	AccountHandler();
	int ChooseOption(void) const;
	void OpenAccount(void);
	void Deposit(void);
	void Withdraw(void);
	void ShowAllInfo(void) const;
	~AccountHandler();
};