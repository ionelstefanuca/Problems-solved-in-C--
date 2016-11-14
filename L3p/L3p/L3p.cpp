// L3p.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"BigNumber.h"

int _tmain(int argc, _TCHAR* argv[])
{
	char *n1 = "749566345";
	char *n2 = "74955345";
	BigNumber nr(n1);
	BigNumber nr1(n2);

	BigNumber nr3;

	nr3= nr + nr1;
	afisareNumar(nr3);

	if (nr < nr1)
	{
		printf("\ntrue\n");
	}
	else
		printf("\nfalse\n");

	if (nr1 == nr)
	{
		printf("\nNumerele sunt egale\n");
	}
	else
		printf("\nNumerele nu sunt egale\n");

	if (nr1 != nr)
	{
		printf("\nNumerele nu sunt egale\n");
	}
	else
		printf("\nNumerele sunt egale\n");

	if (nr > nr1)
		printf("Nr1 este mai mare\n");
	else
		printf("Nr2 este mai mare\n");


	if (nr >= nr1)
		printf("Nr1 este mai mare sau egal cu Nr2\n");

	if (nr <= nr1)
		printf("Nr2 este mai mare sau egal cu Nr1\n");


	char c = nr[0];
	printf("\n%c\n", c);

	nr(2, 4);

	afisareNumar(nr);

	int i = nr;
	printf("\n%d\n", i);

	return 0;
}

