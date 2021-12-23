#include "handler.h"

AccountHandler::AccountHandler()
	:NumAccount(0)
{
	accounts = new Account*[10];
}

int AccountHandler::ChooseOption(void) const
{
	/*
	입력: NULL
	출력: 정수
	기능: 함수 라우팅을 위한 선택지를 정수 형태로 반환
	*/

	int option;

	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료\n" << endl;

	cin >> option;
	cout << "선택: " << option << endl << endl;

	return option;
}

void AccountHandler::OpenAccount(void)
{
	/*
	입력: NULL
	출력: NULL
	기능: 분류(보통계좌, 신뢰계좌)에 따라 계좌 개설
	*/

	int id;
	char name[20];
	int balance;
	int interest;
	int type;

	cout << "[계좌종류 선택]" << endl;
	cout << "(1) 보통예금계좌" << endl;
	cout << "(2) 신용신뢰계좌" << endl << endl;

	while (1)
	{
		cout << "선택 :"; cin >> type; cout << endl;
		if (type == ACCOUNT_TYPE::NORMAL)
		{
			cout << "[보통예금계좌 개설]" << endl;
			break;
		}
		else if (type == ACCOUNT_TYPE::HIGH_CREDIT)
		{
			cout << "[신용신뢰계좌 개설]" << endl;
			break;
		}
		cout << "잘못된 유형입니다." << endl;
	}
	cout << "계좌ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << "이자율: "; cin >> interest;

	if (type == ACCOUNT_TYPE::HIGH_CREDIT)
	{
		char credit;
		cout << "신용등급(A, B, C): "; cin >> credit;

		accounts[NumAccount++] = new HighCreditAccount(id, name, balance, interest, credit);
	}
	else
	{
		accounts[NumAccount++] = new NormalAccount(id, name, balance, interest);
	}
	cout << endl << "계좌 개설이 완료되었습니다.\n" << endl;
}

void AccountHandler::Deposit(void)
{
	/*
	입력: NULL
	출력: NULL
	기능: 입력된 계좌로 이자를 더하며 입금
	*/
	int id, amount, flg = 1;

	cout << "[입    금]" << endl; 
	cout << "계좌ID: "; cin >> id;
	while (1)
	{
		cout << "입금액: "; cin >> amount;
		if (amount <= 0) cout << "입금액이 0 이하입니다." << endl;
		else break;
	}

	for (int i = 0; i < NumAccount; i++)
	{
		if (accounts[i] -> GetId() == id)
		{
			flg = accounts[i] -> AddBalance(amount);
			break;
		}
	}

	switch (flg)
	{
	case 0: cout << "입금이 완료되었습니다.\n\n"; break;
	case 1: cout << "존재하지 않는 ID입니다.\n\n"; break;
	}
}

void AccountHandler::Withdraw(void)
{
	/*
	입력: NULL
	출력: NULL
	기능: 예치된 계좌로부터 출금
	*/
	int id, amount, flg = 1;

	cout << "[출    금]" << endl;
	cout << "계좌ID: "; cin >> id;
	while (1)
	{
		cout << "출금액: "; cin >> amount;
		if (amount <= 0) cout << "출금액이 0 이하입니다." << endl;
		else break;
	}

	for (int i = 0; i < NumAccount; i++)
	{
		if (accounts[i] -> GetId() == id)
		{
			flg = accounts[i] -> SubBalance(amount);
			break;
		}
	}
	switch (flg)
	{
	case 0: cout << "출금이 완료되었습니다.\n\n"; break;
	case 1: cout << "존재하지 않는 ID입니다.\n\n"; break;
	case 2: cout << "잔액이 부족합니다.\n\n"; break;
	}
}

void AccountHandler::ShowAllInfo(void) const
{
	/*
	입력: NULL
	출력: NULL
	기능: 현재 저장된 모든 계좌정보를 생성시간 순으로 출력
	*/
	for (int i = 0; i < NumAccount; i++)
	{
		cout << "====" << i + 1 << "====" << endl;
		accounts[i] -> ShowAccountInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler()
{
	delete[] accounts;
}