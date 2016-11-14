// l8p.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Array.h"
#include"Altele.h"
#include"ArrayIterator.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Array<int> a;

	Array<char *> cuvinte(100);
	cuvinte += "unu";
	cuvinte += "doi";
	cuvinte += "trei";
	cuvinte += "patru";
	cuvinte += "cinci";
	printf("%s\n", cuvinte[2]);
	cuvinte.Delete(2);
	printf("%s\n", cuvinte[2]);
	Array<char *>cuvinteC = cuvinte;

	Array<int> nr(10);
	nr += 0;
	nr += 100;
	nr += 2;
	nr += -10;
	nr += -5;
	nr += 67;
	nr+=200;

	

	//nr.Sort(myCompareIntCresc); /// comparam folosind o functie definita de noi
	//nr.afisareArrayInt();

	CompareInt cmpInt;
	nr.Sort(&cmpInt);
	nr.afisareArrayInt();

	int n2 = nr.BinarySearch(2);
	int n67 = nr.BinarySearch(67,myCompareIntCresc);
	int n100 = nr.BinarySearch(100, &cmpInt);


	int f2 = nr.Find(2);
	int f67 = nr.Find(67, myCompareIntCresc);
	int f100 = nr.Find(100, &cmpInt);


	ArrayIterator<int> it2 = nr.GetEndIterator();
	ArrayIterator<int> it1 = nr.GetBeginIterator();

	int nra1 = *it1.GetElement();
	int nra2 = *it2.GetElement();

	printf("Primul element este %d, iar ultimul este %d\n", nra1, nra2);

	it1++;
	nra1 = *it1.GetElement();
	printf("Primul element este %d, iar ultimul este %d\n", nra1, nra2);

	it1--;
	nra1 = *it1.GetElement();
	printf("Primul element este %d, iar ultimul este %d\n", nra1, nra2);





	ArrayIterator<int> testareWhile = nr.GetBeginIterator();
	printf("\n\nStart Iterator:\n");
	while (testareWhile!=nr.GetEndIterator())
	{
		printf("Numarul este %d\n", *testareWhile.GetElement());

		testareWhile++;
	}
	printf("Iteratorul a ajuns la final\n");


	return 0;
}

