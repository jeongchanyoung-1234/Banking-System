#pragma once
#include <iostream>
#include "Account.h"

using std::cout;
using std::endl;

/*
이름: BoundCheckArray
유형: 저장소
*/
template <class T>
class BoundCheckArray
{
private:
	T* arr;
	int arrlen;

	BoundCheckArray(const BoundCheckArray& copy) {};
	void operator=(const BoundCheckArray& ref) {};
public:
	BoundCheckArray(int len);
	T& operator[](int idx);
	T operator[](int idx) const;
	~BoundCheckArray();
};

template <class T>
BoundCheckArray<T>::BoundCheckArray(int len)
	:arrlen(len)
{
	arr = new T[len];
}

template <class T>
T& BoundCheckArray<T>::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "array index out of range" << endl;
		exit(1);
	}
	return arr[idx];
}

template <class T>
T BoundCheckArray<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "array index out of range" << endl;
		exit(1);
	}
	return arr[idx];
}

template <class T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete[] arr;
}
