// l7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"ProcesareText.h"

int _tmain(int argc, _TCHAR* argv[])
{
	ProcesareText ob("fisier.txt");
	if (ob.validareText())
	{
		printf("Textul este valid\n");
		//ob.extragePropozitiile();
		//ob.afisareVecProp();

		//printf("\n\n");
	//	ob.extrageCuvinte();
		//ob.afisareListaCuvinte();

		ob.setContainar();
		ob.afisareSet();
	}

	return 0;
}

