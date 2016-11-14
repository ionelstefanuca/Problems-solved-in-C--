// l5p1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Forma.h"
#include"Triunghi.h"
#include"Cerc.h"
#include "Dreptunghi.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Forma *vector[3];
	Cerc c(2);
	Triunghi t(1,1,3,3,2,6);
	Dreptunghi d(10, 5);

	vector[0] = &c;
	vector[1] = &t;
	vector[2] = &d;

	printf("Aria figurii %s este %lf\n", vector[0]->GetName(),vector[0]->ComputeArea());
	printf("Aria figurii %s este %lf\n", vector[1]->GetName(), vector[1]->ComputeArea());
	printf("Aria figurii %s este %lf\n", vector[2]->GetName(), vector[2]->ComputeArea());

	return 0;
}

