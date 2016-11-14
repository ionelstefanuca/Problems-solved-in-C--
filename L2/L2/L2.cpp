// L2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IntList.h"
#include<stdlib.h>

int _tmain(int argc, _TCHAR* argv[])
{
	IntList lista1;
	IntList lista2;
	IntList lista3;


	lista1.Add(1994);
	if (lista1.Insert(1, 1995))
		printf("am inserat\n");

	for (int i = 0; i < 200; i++)
		lista1.Add(rand()%100);

	lista1.AfisareLista();
	
	//lista1.Delete(1);
	//lista1.Clear();
	lista1.AfisareLista();
	printf("\nindexOf(64,0)= %d\n", lista1.IndexOf(64, 1));


	lista1.Sort();
	lista1.AfisareLista();

	lista1.RemoveDuplicates();
	lista1.AfisareLista();

	lista1.Reverse();
	lista1.AfisareLista();







	for (int i = 0; i < 200; i++)
		lista2.Add(rand() % 100);

	lista1.Intersection(&lista2, &lista3);
	printf("\n\nLista3 <<intersectie>>:\n");
	lista3.AfisareLista();


	printf("\n\nLista3 <<reuniune>>:\n");
	lista1.Reunion(&lista2, &lista3);
	lista3.AfisareLista();



	return 0;
}

