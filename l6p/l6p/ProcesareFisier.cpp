#include "stdafx.h"
#include "ProcesareFisier.h"

ProcesareFisier::ProcesareFisier(char * fisier)
{
	FILE *FH = NULL;
	errno_t err = fopen_s(&FH, fisier, "r");
	if (err)
	{
		printf("Eroare la deschiderea fisierului");
	}
	else
	{
		char fraza[500];
		while (fgets(fraza, 500, FH) != NULL)
		{
			int i1 = 0, i2 = 0, inceput = 0;;
			for (unsigned int i = i1; i < strlen(fraza); i++)
			{
				if ((fraza[i] == ' ' || fraza[i] == '.' || fraza[i] == ')' || fraza[i] == '(' || fraza[i] == '>' || fraza[i] == '<' || fraza[i] == '\n' || fraza[i] == '*')&&inceput!=0)
				{

					char * ccc = (char*)malloc(i2 - i1);

					for (int n = 0; n < i2 - i1; n++)
					{
						ccc[n] = fraza[n + i1];
					}

					ccc[i2 - i1] = '\0';

					this->vec.push_back(ccc);

					i2++;
					i1 = i2;
					inceput = 0;

				}
				else
				{
					i2++;
					inceput++;

				}
			}
		}

		fclose(FH);
	}

}





const char* ProcesareFisier::celMaiLungCuv()
{
	vector<const char*>::iterator it = this->vec.begin();
	unsigned int max = 0, pozitie = 0;
	int i = 0;
	
	while (it < this->vec.end())
	{
		if (strlen(*it)>max)
		{
			max = strlen(*it);
			pozitie = i;
		}
		i++;
		it++;
	}

	return this->vec.at(pozitie);
}

int ProcesareFisier::maiMultDe4Vocale()
{
	int nr = 0;

	vector<const char*>::iterator i;
	for (i = this->vec.begin(); i != this->vec.end(); i++)
	{
		if (strlen(*i) > 4)
		{
				const char * copie = *i;
				int nrVocale = 0;

				for (unsigned int j = 0; j < strlen(copie); j++)
				{
					if (copie[j] == 'a' || copie[j] == 'e' || copie[j] == 'i' || copie[j] == 'o' || copie[j] == 'u')
					{
						nrVocale++;
						if (nrVocale>4)
						{
							nr++;
							break;
						}
					}
				}
		}
	}
	return nr;
}

void ProcesareFisier::stergeCuvinteleMaiMariCa(unsigned int nrCaractere)
{
	int i = vec.size()-1;

	while (i>=0)
	{
		if (strlen(vec.at(i)) > nrCaractere)
			vec.erase(vec.begin() + i);
		i--;
	}
}

void ProcesareFisier::afisareVector()
{
	vector<const char*>::iterator it = vec.begin();
	printf("\n\nElementele vectorului sunt:\n");
	while (it != vec.end())
	{
		printf("[%s] ", *it);
		it++;
	}
	printf("\n\n");
}

void ProcesareFisier::creazaDeque()
{
	vector<const char*>::iterator it=vec.begin();
	while (it != vec.end())
	{
		const char* cuv = (const char*)malloc(strlen(*it));
		cuv = *it;
		if (cuv[0] == 'a' || cuv[0] == 'e' || cuv[0] == 'i' || cuv[0] == 'o' || cuv[0] == 'u')
		{
			//nimic
		}
		else
		{
			deq.push_front(cuv);
		}
		it++;
	}
}

void ProcesareFisier::afisareDeque()
{
	printf("Afisare Deque:\n");
	deque<const char*>::iterator it = deq.begin();
	while (it != deq.end())
	{
		printf("[%s] ",*it);
		it++;
	}
}

void ProcesareFisier::creazaReverseVector()
{
	stack<const char*> stiva;
	vector<const char*>::iterator it = vec.begin();
	while (it != vec.end())
	{
		const char* copie = (const char*)malloc(strlen(*it));
		copie = *it;

		stiva.push(copie);

		it++;
	}

	while (!stiva.empty())
	{
		rvec.push_back(stiva.top());
		stiva.pop();
	}
}

void ProcesareFisier::afisareReverseVector()
{
	vector<const char*>::iterator it = rvec.begin();
	printf("Afisare reverse vector:\n");
	while (it != rvec.end())
	{
		printf("[%s] ", *it);
		it++;
	}
}


priority_queue<const char*, vector<const char*>, ProcesareFisier> ProcesareFisier::rCoadaCuPrioritati()
{
	priority_queue<const char*, vector<const char*>, ProcesareFisier> ceva;
	vector<const char*>::iterator it = vec.begin();

	while (it != vec.end())
	{
		const char* copie = (const char*)malloc(strlen(*it));
		copie = *it;


		ceva.push(copie);
		it++;
	}
	
	/*
	while (!ceva.empty())
	{
		printf("%s\n", ceva.top());
		ceva.pop();
	}
	*/

	return ceva;
}

