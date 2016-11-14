// incarcaDLL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<Windows.h>
using namespace std;

typedef  const char *(*GetName)();
typedef int(*Compute)(int, int);

int _tmain(int argc, _TCHAR* argv[])
{

	GetName _getName;
	Compute _compute;

	char lib[50];

	while (1)
	{
		cout << "Introdu 0 pentru a iesi din program sau\n";
			cout << "Introdu numele librariii pe care doresti sa o incarci dinamic: "<<endl;
			cin >> lib;

			if (strcmp(lib, "0") == 0)
			{
				printf("\nAi iesit din program\n");
				return 0;
			}


			HINSTANCE hLibrarie = LoadLibraryA(lib);

			if (hLibrarie)
			{
				_getName = (GetName)GetProcAddress(hLibrarie, "GetName");
				_compute = (Compute)GetProcAddress(hLibrarie,"Compute");

				if (_getName)
				if (_compute)
				{
					int nr1, nr2;
					cout << "Introdu nr1= ";
					cin >> nr1;
					cout << "Introdu nr2= ";
					cin >> nr2;
					cout << "Rezultatul functiei " << _getName() << "( " << nr1 << " , " << nr2 << " ) este: " << _compute(nr1, nr2) << endl;
			
				}
				else
					cout << "Functia \"Compute\" nu este definita in fisierul .dll";
				else
					cout << "Functia \"GetName\" nu este definita in fisierul .dll";
			}
			else
			{
				cout << "Nu am putut incarca libraria " << lib << endl;
			}

			cout<<"______________________________________________________________________" << endl << endl<<endl<<endl;


			FreeLibrary(hLibrarie);
	}



	return 0;
}

