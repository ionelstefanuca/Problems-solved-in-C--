// modificare valori private clasa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Privat
{
private :
	int x;
	int y;
	char z;
	double p;
	int a;

public:
	Privat()
	{
		this->x = 2;
		this->y = 5;
		this->z = 'A';
		this->p = 10.0;
		this->a = 10;
	}

	void afisare()
	{
		printf("x = %d\ny= %d\nz=%c\np=%lf\na=%d\n", this->x,this->y,this->z,this->p,this->a);
	}
};



int _tmain(int argc, _TCHAR* argv[])
{
	Privat p;
	p.afisare();

	printf("\n\n\n");

	int * i = (int*)&p;

	*i = 20;
	i++;
	*i = 50;
	i++;
	*i = 'B';
	i++;
	i++;
	i++;
	i++;
	*i = 500; // modificam int a din clasa //// de ce incrementam de 4 ori pentru a trece de un double? 
	// pt ca avem (reprezentarea in memorie a clasei) 2x double < double p;  < int a , iar cand incrementam i, crestem cu 4 bytes
	p.afisare();

	double * d =(double *) &p;
	d++;
	d++;
	*d = 100.99;
	printf("\n\n\n");
	p.afisare();

	*d = *i;
	*d = 99.99;
	printf("\n\n\n");
	p.afisare();


	char * ch = (char *)&p;

	ch += 8;
	*ch = 'p';
	printf("\n\n\n");
	p.afisare();

	return 0;
}

