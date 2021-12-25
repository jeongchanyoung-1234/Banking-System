/*
Banking System v0.9
작성자: 정찬영
*/
#include <iostream>
#include "AccountHandler.h"
#define MAX_LEN	10

using std::cout;
using std::endl;

int main(void)
{
	int option;
	AccountHandler handler(MAX_LEN);

	while (1)
	{
		option = handler.ChooseOption();

		switch (option)
		{
		case AccountHandler::OPEN: 
			handler.OpenAccount();
			break;
		case AccountHandler::DEPOSIT: 
			handler.Deposit();
			break;
		case AccountHandler::WITHDRAW:
			handler.Withdraw();
			break;
		case AccountHandler::LIST:
			handler.ShowAllInfo();
			break;
		case AccountHandler::QUIT:
			cout << "이용해주셔서 감사합니다." << endl;
			return 0;
		default: 
			cout << "잘못된 접근입니다." << endl;
		}
	}

	return 0;
}