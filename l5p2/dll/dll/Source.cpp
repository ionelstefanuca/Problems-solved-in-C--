#include"Header.h"
#include<stdio.h>

extern "C"
{
	DECLDIR int Compute(int a, int b)
	{
		if (b == 0)
		{
			printf("Deimpartitul este 0. Eroare la impartire\n");
			return 0;
		}

		return a /b;
	}

	DECLDIR const char* GetName()
	{
		return "Impartire";
	}

}
