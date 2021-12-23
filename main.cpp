/*
Banking System v0.6
�ۼ���: ������
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
			cout << "�̿����ּż� �����մϴ�." << endl;
			return 0;
		default: 
			cout << "�߸��� �����Դϴ�." << endl;
		}
	}

	return 0;
}