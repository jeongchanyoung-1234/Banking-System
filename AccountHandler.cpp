#include "AccountHandler.h"
#include "String.h"
#include "Exception.h"

using std::cout;
using std::cin;
using std::endl;

AccountHandler::AccountHandler(int len)
	:accounts(len), NumAccount(0)
{}

int AccountHandler::ChooseOption(void) const
{
	/*
	입력: NULL
	출력: 정수
	기능: 함수 라우팅을 위한 선택지를 정수 형태로 반환
	*/

	int option;

	cout << "-----Menu-----" << endl;
	cout << "(1) 계좌개설" << endl;
	cout << "(2) 입 금" << endl;
	cout << "(3) 출 금" << endl;
	cout << "(4) 계좌정보 전체 출력" << endl;
	cout << "(5) 프로그램 종료\n" << endl;

	cout << "[MESSAGE] 기능을 선택하세요: "; cin >> option; cout << endl;

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
	String name;
	int balance;
	int interest;
	int type;

	cout << "[계좌종류 선택]" << endl;
	cout << "(1) 보통예금계좌" << endl;
	cout << "(2) 신용신뢰계좌" << endl << endl;

	while (1)
	{
		try
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
			throw
				AccountTypeError(type);
		}
		catch (AccountException& expn)
		{
			expn.what();
		}
	}

	while (1)
	{
		try
		{
			cout << "계좌ID: "; cin >> id;
			if (CheckId(id) >= 0)
				throw IdExistException(id);
			cout << "이 름: "; cin >> name;
			cout << "입금액: "; cin >> balance;
			if (balance < 0)
				throw LessThanZeroException(balance);
			cout << "이자율: "; cin >> interest;
			break;
		}
		catch (AccountException& expn)
		{
			expn.what();
		}
	}

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
	cout << endl << "[MESSAGE] 계좌 개설이 완료되었습니다.\n" << endl;
}

void AccountHandler::Deposit(void)
{
	/*
	입력: NULL
	출력: NULL
	기능: 입력된 계좌로 이자를 더하며 입금
	*/
	int id, amount, idx;

	cout << "[입    금]" << endl; 
	while (1)
	{
		try
		{
			cout << "계좌ID: "; cin >> id;
			idx = CheckId(id);
			if (idx < 0)
				throw IdDoNotExistException(id);
			break;
		}
		catch (IdDoNotExistException& expn)
		{
			expn.what();
		}
	}

	while (1)
	{
		try
		{
			cout << "입금액: "; cin >> amount;
			if (amount <= 0)
				throw LessThanZeroException(amount);

			accounts[idx]->AddBalance(amount);
			break;
		}
		catch (AccountException& expn)
		{
			expn.what();
		}
	}

	cout << "[MESSAGE] 입금이 완료되었습니다." << endl;
	accounts[idx]->ShowAccountInfo();
	cout << endl;
}

void AccountHandler::Withdraw(void)
{
	/*
	입력: NULL
	출력: NULL
	기능: 예치된 계좌로부터 출금
	*/
	int id, amount, idx;

	cout << "[출    금]" << endl;
	while (1)
	{
		try
		{
			cout << "계좌ID: "; cin >> id;
			idx = CheckId(id);
			if (idx < 0)
				throw IdDoNotExistException(id);
			break;
		}
		catch (IdDoNotExistException& expn)
		{
			expn.what();
		}
	}

	while (1)
	{
		try
		{
			cout << "출금액: "; cin >> amount;
			if (amount <= 0)
				throw LessThanZeroException(amount);

			int balance = accounts[idx]->GetBalance();
			if (balance < amount)
				throw LackOfBalacneException(balance, amount);

			accounts[idx]->AddBalance(-amount);
			break;
		}
		catch (AccountException& expn)
		{
			expn.what();
		}
	}

	cout << "[MESSAGE] 출금이 완료되었습니다." << endl;
	accounts[idx]->ShowAccountInfo();
	cout << endl;
};

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
		accounts[i]->ShowAccountInfo();
		cout << endl;
	}
};

int AccountHandler::CheckId(int id) const
{
	for (int i = 0; i < NumAccount; i++)
	{
		if (accounts[i]->GetId() == id)
			return i;
	}
	return -1;
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < NumAccount; i++)
		delete accounts[i];
}