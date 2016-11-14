#include "stdafx.h"
#include "BigNumber.h"
#include<stdlib.h>
#include<stdio.h>
#include <string.h>

BigNumber::BigNumber(){}

BigNumber::BigNumber(int val)
{
	int val1 = val;
	int carCount = 0;
	while (val1 != 0)
	{
		val1 = val1 / 10;
		carCount++;
	}

	_itoa_s(val, this->Number, carCount);
	this->CharactersCount = carCount;
}

BigNumber::BigNumber(const char * nr)
{
	strncpy_s(this->Number, nr, strlen(nr));
	this->CharactersCount = strlen(nr);

}

bool BigNumber::Set(int n)
{
	int val1 = n;
	int carCount = 0;
	while (val1 != 0)
	{
		val1 = val1 / 10;
		carCount++;
	}

	_itoa_s(n, this->Number, carCount);
	this->CharactersCount = carCount;
	
	return true;
}

bool BigNumber::Set(const char * nr)
{
	for (unsigned int i = 0; i < strlen(nr); i++)
	{
		if (nr[i]<'0' || nr[i]>'9' + 1)
		{
			return false;
		}
	}

	strncpy_s(this->Number, nr, strlen(nr));
	this->CharactersCount = strlen(nr);
	return true;
}

BigNumber BigNumber::operator+ (const BigNumber & number){
	char nr1[256];
	char nr2[256];
	char suma[256];
	strcpy_s(nr1, reverse(number));
	strncpy_s(nr2, reverse(*this), strlen(reverse(*this)));

	int maxim = this->CharactersCount > number.CharactersCount ? CharactersCount : number.CharactersCount;


	int c1=0;
	int c2=0;
	int carry=0;

	for (int i = 0; i < maxim; i++)
	{
		c1 = nr1[i];
		if (c1>='0'&&c1<='9')
			c1 = c1 - 48;
		else
			c1 = 0;

		c2 = nr2[i];
		if (c2 >= '0'&&c2 <= '9')
			c2 = c2 - 48;
		else
			c2 = 0;

		int c3 = c1 + c2;
		if (c3 > 9)
		{
			suma[i] = 48 + (c3 + carry )% 10;
			carry = 1;
		}
		else
		{
			suma[i] = 48 + (c3 + carry)%10;
			carry = 0;
			if ((c3 + carry) == 10)
				carry = 1;
		}
	}

	if (carry == 1)
	{

		suma[maxim] = '1';
		suma[maxim + carry] = '\0';
	}
	else
	suma[maxim + carry] = '\0';


	strncpy_s(suma, reverse(suma), 256);
	//printf("%s\n%s\n%s\n",nr1,nr2,suma);

	BigNumber p(suma);
	return p;
}


char* reverse(const BigNumber & number)
{
	char v[256];

	for (int i = 0; i < number.CharactersCount; i++)
		v[i] = number.Number[number.CharactersCount - i-1 ];
	v[number.CharactersCount] = '\0';

	return v;
}

void afisareNumar(const BigNumber & nr)
{
	printf("NrCifre: %d\nNumarul: %s\n",nr.CharactersCount,nr.Number);
}

bool operator <  (const BigNumber & n1, const BigNumber & n2)
{
	if (n1.CharactersCount != n2.CharactersCount)
	{
		if (n1.CharactersCount < n2.CharactersCount)
			return true;
		else
			return false;
	}

			else
			{
				for (int i = 0; i < n1.CharactersCount;i++)
				if (n1.Number[i] != n2.Number[i])
				{
					if (n1.Number[i] < n2.Number[i])
						return true;
					else
						return false;
				}
			}

	return true;
}

bool operator== (const BigNumber & nr1, const BigNumber &nr2)
{
	if (nr1.CharactersCount != nr2.CharactersCount)
		return false;
	else
	{
		for (int i = 0; i < nr1.CharactersCount;i++)
		if (nr1.Number[i] != nr2.Number[i])
			return false;
	}
	return true;
}

bool operator!= (const BigNumber &n1, const BigNumber &n2)
{
	if (n1.CharactersCount != n2.CharactersCount)
		return true;
	else
	{
		for (int i = 0; i < n1.CharactersCount; i++)
		if (n1.Number[i] != n2.Number[i])
			return true;
	}

	return false;
}

bool operator>(const BigNumber &nr1, const BigNumber &nr2)
{
	if (nr1.CharactersCount > nr2.CharactersCount)
		return true;

	if (nr1.CharactersCount < nr2.CharactersCount)
		return false;

	if (nr1.CharactersCount == nr2.CharactersCount)
	{
		for (int i = 0; i < nr1.CharactersCount; i++)
		{
			if (nr1.Number[i] < nr2.Number[i])
				return false;
		}
	}
	return true;
}

bool operator >= (const BigNumber &nr1, const BigNumber &nr2)
{
	if (nr1.CharactersCount>nr2.CharactersCount)
		return true;

	if (nr1.CharactersCount<nr2.CharactersCount)
		return false;

	if (nr1.CharactersCount == nr2.CharactersCount)
	{
		for (int i = 0; i < nr1.CharactersCount;i++)
		if (nr1.Number[i] < nr2.Number[i])
			return false;
	}
	return true;
}

bool operator<=(const BigNumber &nr1, const BigNumber &nr2)
{
	if (nr1.CharactersCount<nr2.CharactersCount)
		return true;

	if (nr1.CharactersCount>nr2.CharactersCount)
		return false;

	if (nr1.CharactersCount == nr2.CharactersCount)
	{
		for (int i = 0; i < nr1.CharactersCount; i++)
		if (nr1.Number[i] > nr2.Number[i])
			return false;
	}
	return true;
}

char BigNumber::operator[](int index)
{
	if (this->CharactersCount > index)
	{
		return this->Number[index];
	}
	return '\0';
}

BigNumber BigNumber::operator() (int start, int end)
{
	if (start >= 0 && end <= this->CharactersCount)
	{
		char v[256];
		strncpy_s(v, this->Number + start-1,end-1);
		
		strcpy_s(this->Number, v);
		this->CharactersCount = end - start + 1;
	}

	return *this;
}

BigNumber::operator const int()
{
	return atoi(this->Number);
}