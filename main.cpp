/*
Banking System v0.6
작성자: 정찬영
*/
#include "handler.h"

int main(void)
{
	int option;
	AccountHandler handler;

	while (1)
	{
		option = handler.ChooseOption();

		switch (option)
		{
		case OPEN: 
			handler.OpenAccount();
			break;
		case DEPOSIT: 
			handler.Deposit();
			break;
		case WITHDRAW: 
			handler.Withdraw();
			break;
		case LIST: 
			handler.ShowAllInfo();
			break;
		case QUIT:
			cout << "이용해주셔서 감사합니다." << endl;
			return 0;
		default: 
			cout << "잘못된 접근입니다." << endl;
		}
	}

	return 0;
}