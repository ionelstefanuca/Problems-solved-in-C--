#pragma once
#include<vector>
#include<deque>
#include<stack>
#include<queue>
using namespace std;

class ProcesareFisier
{
private:
	vector<const char*> vec;
	deque<const char*> deq;
	vector<const char*> rvec;



public:
	ProcesareFisier(char* numeFisier);
	ProcesareFisier(){}

	const char * celMaiLungCuv();
	int maiMultDe4Vocale();
	void stergeCuvinteleMaiMariCa(unsigned int nrCaractere);
	void afisareVector();
	void creazaDeque();
	void afisareDeque();
	void creazaReverseVector();
	void afisareReverseVector();
	priority_queue<const char*, vector<const char*>, ProcesareFisier> rCoadaCuPrioritati(); // returneaza o coada sortata alfabetic


	bool operator()(const char* t1, const char* t2)
	{
		int minim = strlen(t1);
		if (strlen(t2) < minim)
			minim = strlen(t2);

		for (int i = 0; i < minim; i++)
		{
			if (t1[i] >= t2[i])
			{
				;
			}
			else
				return false;
		}
		return true;
	}


};

