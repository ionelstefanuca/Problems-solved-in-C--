// l6p.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"ProcesareFisier.h"

int _tmain(int argc, _TCHAR* argv[])
{
	ProcesareFisier fisier("fisier.txt");
	//printf("Cel mai lung cuvant este: %s\n",fisier.celMaiLungCuv());
	//printf("In fisier avem %d cuvinte care au in compozitia lor mai mult de 4 vocale\n", fisier.maiMultDe4Vocale());
	//fisier.creazaDeque();
	//fisier.afisareDeque();

	//fisier.creazaReverseVector();
	//fisier.afisareReverseVector();


	//fisier.afisareVector();
	//fisier.stergeCuvinteleMaiMariCa(4);
	//fisier.afisareVector();


	printf("Elementele din coada cu prioritati sunt:\n");
	priority_queue<const char*, vector<const char*>, ProcesareFisier> rCoadaCuPrioritati = fisier.rCoadaCuPrioritati();
	while (!rCoadaCuPrioritati.empty())
	{
		printf("%s\n", rCoadaCuPrioritati.top());

		rCoadaCuPrioritati.pop();
	}

	return 0;
}

