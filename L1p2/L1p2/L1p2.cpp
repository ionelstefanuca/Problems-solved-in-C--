// L1p2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>
#include<math.h>

int Matrix[6][5];

void Circle(int* ptr, int cx, int cy, int ray) {
	int contor = 0;
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 5; j++)
		{
			double cal = sqrt(pow(double(i - cx), 2) + pow(double(j - cy), 2));
			
			int rez=0;
			if (cal <= 2 && cal >= 1.4)
				rez = 2;

			if (rez == 2)
			{
				*(ptr + contor) = 1;
			}
			contor++;
		}
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	Circle(&Matrix[0][0], 2, 2, 2);

	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", Matrix[i][j]);
		}
		printf("\n");
	}


	return 0;
}

