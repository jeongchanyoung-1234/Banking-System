#include "AccountPtrArray.h"


AccountPtrArray::AccountPtrArray(int len)
	:arrlen(len)
{
	arr = new ACC_PTR[len];
}

ACC_PTR& AccountPtrArray::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "array index out of range" << endl;
		exit(1);
	}
	return arr[idx];
}

ACC_PTR AccountPtrArray::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "array index out of range" << endl;
		exit(1);
	}
	return arr[idx];
}

AccountPtrArray::~AccountPtrArray()
{
	delete[] arr;
}
