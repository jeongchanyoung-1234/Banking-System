#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "customer.h"
#include "coretools.h"

using std::cout;
using std::cin;
using std::endl;

int num_customers = 0; // 전체 고객의 수
Customer customerInfo[10]; // 고객 데이터를 관리하는 배열

enum { OPEN = 1, DEPOSIT, WITHDRAW, LIST, QUIT };

int main(void)
{
	int option;
	int flg;

	while (1)
	{
		cout << "-----Menu-----" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입 금" << endl;
		cout << "3. 출 금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료\n" << endl;
		
		cin >> option;
		cout << "선택: " << option << endl << endl;

		switch (option)
		{
		case OPEN: 
			open_account(); 
			break;
		case DEPOSIT: 
			deposit(); 
			break;
		case WITHDRAW: 
			withdraw(); 
			break;
		case LIST: 
			for (int i = 0; i < num_customers; i++)
				customerInfo[i].ShowCustomerInfo();
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