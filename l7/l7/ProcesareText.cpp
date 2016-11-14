#include "stdafx.h"
#include<fstream>
#include<iostream>
#include "ProcesareText.h"


ProcesareText::ProcesareText(char* fisier) {
	this->fisier = fisier;
}

bool ProcesareText::validareText()
{
	bool esteValid = true;
	int dimensiunea = 0;
	fstream file;
	file.open(this->fisier, std::fstream::in);
	if (file.is_open())
	{
		file.seekg(0, file.end);
		dimensiunea = (int)file.tellg();
		file.seekg(0, file.beg);

		char * vector = new char[dimensiunea];

		file.read(vector, dimensiunea);
		vector[dimensiunea] = '\0';


		int inceputP = -1;
		int sfarsitP = 0;

		for (int i = 0; i < dimensiunea; i++)
		{

			if (inceputP == -1 && ((vector[i] <= 'z' && vector[i] >= 'a') || (vector[i] <= 'Z' && vector[i] >= 'A')
				|| (vector[i] <= '9' && vector[i] >= '0')))
				inceputP = i;

			sfarsitP = i;
			if (vector[i] == '.' || vector[i] == '?' || vector[i] == '!')
			{
				char prop[1000];
				strncpy_s(prop, vector + inceputP, sfarsitP - inceputP + 1);
				
				for (unsigned int t = 0; t < strlen(prop)-1; t++) /// verificam daca propozitia este corecta
				{
					if ((prop[t] == ',' && prop[t + 1] == ',') || (prop[t] >= '#' && prop[t]<',') || (prop[t] == '-') && ((prop[t + 1] == ' ') || (prop[t + 1] == ',') || (prop[t - 1] == ' ') || (prop[t - 1] == ',') || (prop[t + 1] == '?') || (prop[t + 1] == '.') || (prop[t + 1] == '!') || (prop[t + 1] == '-')))
						{
							printf("Propozitia '%s' nu respecta formatul\n", prop);
							esteValid = false;
							break;
						}
				}

					int m = i;
					while (m < dimensiunea && (!('a' <= vector[m] && vector[m] <= 'z')) && (!('A' <= vector[m] && vector[m] <= 'Z')) && (!('0' <= vector[m] && vector[m] <= '9')) )
					{
						m = ++i;

						if ((vector[m - 1] = '.'&& vector[m] == '.') || (vector[m - 1] = '!'&& vector[m] == '!') || (vector[m - 1] = '?'&& vector[m] == '?'))
						{
							printf("Spatiul dintre propozitii nu este formatat corect\n");
							esteValid = false;
						}
					}
					i--;

					inceputP = -1;
					sfarsitP = 0;
			}
			else
				if (inceputP != -1 && ((sfarsitP + 1) == dimensiunea)) /// cand nu exist punct la sf ultimei propozitii
				{
					char prop[1000];
					strncpy_s(prop, vector + inceputP, sfarsitP - inceputP + 1);
					printf("Propozitia '%s' nu respecta regulile\n", prop);
					esteValid = false;
				}
		}
		file.close();

	}

	return esteValid ;
}


void ProcesareText::extragePropozitiile()
{
	int dimensiunea = 0;
	fstream file;
	file.open(fisier, std::fstream::in);
	if (file.is_open())
	{
		file.seekg(0, file.end);
		dimensiunea = (int)file.tellg();
		file.seekg(0, file.beg);

		char * vector = new char[dimensiunea];

		file.read(vector, dimensiunea);
		vector[dimensiunea] = '\0';


		int inceputP = -1;
		int sfarsitP = 0;

		for (int i = 0; i < dimensiunea; i++)
		{
			if (inceputP == -1 && ((vector[i] <= 'z' && vector[i] >= 'a') || (vector[i] <= 'Z' && vector[i] >= 'A')
				|| (vector[i] <= '9' && vector[i] >= '0')))
				inceputP = i;

			sfarsitP = i;
			if (vector[i] == '.' || vector[i] == '?' || vector[i] == '!')
			{
				char prop[1000];
				strncpy_s(prop, vector + inceputP, sfarsitP - inceputP + 1);
				string propStr = prop;
				this->vecProp.push_back(propStr);

				int m = i;
				while (m < dimensiunea && (!('a' <= vector[m] && vector[m] <= 'z')) && (!('A' <= vector[m] && vector[m] <= 'Z')) && (!('0' <= vector[m] && vector[m] <= '9')))
				{
					m = ++i;
				}
				i--;

				inceputP = -1;
				sfarsitP = 0;
			}

		}
		file.close();

	}
}

void ProcesareText::afisareVecProp()
{
	vector<string>::iterator it = vecProp.begin();

	cout <<endl<< "Propozitiile din fisier sunt: " << endl;
	while (it != vecProp.end())
	{
		cout << *it << endl;
		it++;
	}
	cout << endl;
}

void ProcesareText::extrageCuvinte()
{
	fstream file;
	file.open(fisier, std::fstream::in);
	string cuv;
	if (file.is_open())
	{
		while (!file.eof())
		{
			string cuv;
			file >> cuv;

			int contor=0;
			for (unsigned int i = 0; i < cuv.length(); i++)
			{
				if ((cuv[i] >= 'a' && cuv[i] <= 'z') || (cuv[i] >= 'A'&&cuv[i] <= 'Z') || cuv[i] == '-' || (cuv[i] >= '0'&& cuv[i] <= '9'))
				{
					contor++;
				}
			}
			cuv = cuv.substr(0, contor);
			if (cuvinte[cuv] == 0)
			{
				this->cuvinte[cuv] = 1;
			}
			else
			{
				map<string, int>::iterator it;
				it = cuvinte.find(cuv);
				int x = it->second;
				x++;
				this->cuvinte[cuv] = x;
			}
		}

	}
	file.close();
}

void ProcesareText::afisareListaCuvinte()
{
	map<string, int>::iterator it = cuvinte.begin();

	cout << "Afisare lista cuvinte " << endl;
	while (it != cuvinte.end())
	{
		cout << "Cuvantul '" << it->first << "' apare de " << it->second << " ori in text" << endl;
		it++;
	}
}

void ProcesareText::setContainar()
{
	fstream file;
	file.open(fisier, std::fstream::in);
	string cuv;
	if (file.is_open())
	{
		while (!file.eof())
		{
			string cuv;
			file >> cuv;

			int contor = 0;
			for (unsigned int i = 0; i < cuv.length(); i++)
			{
				if ((cuv[i] >= 'a' && cuv[i] <= 'z') || (cuv[i] >= 'A'&&cuv[i] <= 'Z') || cuv[i] == '-' || (cuv[i] >= '0'&& cuv[i] <= '9'))
				{
					contor++;
				}
			}
			cuv = cuv.substr(0, contor);
			setCuv.insert(cuv);
		}

	}
	file.close();
}


void ProcesareText::afisareSet()
{
	cout << "Afisare cuvinte din containarul Set:" << endl;
	set<string>::iterator it = setCuv.begin();
	while (it != setCuv.end())
	{
		cout << *it << endl;
		it++;
	}
}