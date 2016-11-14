#pragma once
#include<string>
#include<vector>
#include<map>
#include<set>
using namespace std;

class ProcesareText
{
private:
	vector<string> vecProp;
	map<string, int> cuvinte;
	set<string> setCuv;

	char * fisier;
public:
	ProcesareText( char* fisier);
	bool validareText();
	void extragePropozitiile();
	void afisareVecProp();
	void extrageCuvinte();
	void afisareListaCuvinte();
	void setContainar();
	void afisareSet();

};

