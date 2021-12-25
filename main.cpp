/*
Banking System v0.9
�ۼ���: ������
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
			cout << "�̿����ּż� �����մϴ�." << endl;
			return 0;
		default: 
			cout << "�߸��� �����Դϴ�." << endl;
		}
	}

	return 0;
}