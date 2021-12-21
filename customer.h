#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>

class Customer
{
private:
	int accountId;
	char* name;
	int accountBalance;

public:
	static int num_customers;
	static Customer* customerInfo;

	Customer();
	Customer(const Customer& copy);
	// getter
	int GetId(void) const;
	char* GetName(void) const;
	int GetBalance(void) const;
	// setter
	void SetInfo(int accountId, char* name, int accountBalance);
	// utils
	int AddBalance(int money);
	void ShowCustomerInfo(void) const;
	// deconstructor
	~Customer();
};
