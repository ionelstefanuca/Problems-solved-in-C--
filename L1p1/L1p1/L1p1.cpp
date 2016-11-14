#include "stdafx.h"
#include<iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int v[1000];
	char nr[100];
	const char *cFileName="fisier.txt";
	int contorNrCitite = 0;

	FILE *FH = NULL;
	errno_t err = fopen_s(&FH, cFileName, "r");
	if (err)
	{
		cout << "Eroare la deschiderea fisierului" << endl;
		exit(0);
	}

	
	while (fgets(nr, 100, FH) != NULL)
	{
		v[contorNrCitite] = atoi(nr);
		contorNrCitite++;
	}

	for (int i = 0; i < contorNrCitite;i++)
	for (int j = i; j < contorNrCitite; j++)
	{
		if (v[i]>v[j])
		{
			int aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}
	}

	for (int i = 0; i < contorNrCitite; i++)
	{
		cout << "v[" << i << "]= " << v[i]<<endl;
	}


	return 0;
}

