#pragma once
template<class T>
int myCompareIntCresc(const T& el1, const T& el2)
{
	if (el1 == el2)
		return 0;
	else
	if (el1 < el2)
		return 1;
	else
		return -1;
}


template<class T>
int myCompareIntDesc(const T& el1, const T& el2)
{
	if (el1 == el2)
		return 0;
	else
	if (el1 < el2)
		return -1;
	else
		return 1;
}

