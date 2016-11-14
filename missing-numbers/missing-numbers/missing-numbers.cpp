// missing-numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//Se dau n-1 numere distincte de la 1 la n, sa se dea un algoritm cat mai eficient care sa determine numarul lipsa.
void nrLipsa()
{
	int vec[] = {1,9,2,8,7,5,4,6,3}; //lipseste 10
	int nr = 10;
	int suma = 0;
	for (int i = 1; i < nr-1; i++)
	{
		suma ^= vec[i-1]^i;
	}
	printf("Numarul lipsa este %d\n", suma);
}

//Se da un sir de n+1 numere de la 1 la n in care unul se repeta, iar restul sunt distincte. 
//Sa se dea un algoritm cat mai eficient care sa determine numarul ce se repeta.

void nrRepeta()
{
	int vec[] = { 1, 9, 2, 8, 7, 5, 4, 6, 3,10,2}; // sunt 11 nr si 2 se repeta
	int nr = 11;
	int suma = 0;
	for (int i = 0; i < nr-1; i++)
	{
		suma ^= (i + 1) ^ vec[i];
	}
	suma ^= vec[nr - 1];

	printf("Numarul care se repeta este %d\n", suma);
}



struct Lista
{
	int valoare;
	Lista * next;
};



int _tmain(int argc, _TCHAR* argv[])
{
	//nrLipsa();
	//nrRepeta();

//Se da o lista inlantuita prin primul ei element. Se cere un algoritm cat mai eficient care sa determine daca lista are sau nu ciclu.
	Lista * c1 = new Lista;
	c1->valoare = 1;

	Lista * c2 = new Lista;
	c2->valoare = 2;

	Lista * c3 = new Lista;
	c3->valoare = 3;

	Lista * c4 = new Lista;
	c4->valoare = 4;

	Lista * c5 = new Lista;
	c5->valoare = 5;

	Lista * c6 = new Lista;
	c6->valoare = 6;

	Lista * c7 = new Lista;
	c7->valoare = 7;

	Lista * c8 = new Lista;
	c8->valoare = 8;

	Lista * c9 = new Lista;
	c9->valoare = 9;

	Lista * c10 = new Lista;
	c10->valoare = 10;

	c1->next = c2;
	c2->next = c3;
	c3->next = c4;
	c4->next = c5;
	c5->next = c6;
	c6->next = c7;
	c7->next = c8;
	c8->next = c9; 
	c9->next = c10;
	c10->next = c2;


	Lista * iter1;
	Lista * iter2;
	iter1 = iter2 = c1;

	int cont = 0;

	do{
		iter1 = iter1->next;
		iter2 = iter2->next->next;
	} while (iter1 != iter2);

// sa se determine lungimea ciclului
	do
	{
		iter1 = iter1->next;
		cont++;

	} while (iter1 != iter2);
	printf("Lungimea ciclului este de: %d\n", cont);
	




	return 0;
}

