#pragma once
class BigNumber {

private:
	char Number[256];
	int  CharactersCount;

public:

	BigNumber(); // Constructor implicit
	BigNumber(int value);
	BigNumber(const char * number); // Constructor de copiere

	bool Set(int value);
	bool Set(const char * number);
	

	BigNumber operator+ (const BigNumber & number);
	BigNumber operator* (const BigNumber & number);
	BigNumber operator- (const BigNumber & number);
	BigNumber operator/ (const BigNumber & number);


	friend bool operator == (const BigNumber & n1, const BigNumber & n2);//
	friend bool operator != (const BigNumber & n1, const BigNumber & n2);//
	friend bool operator <  (const BigNumber & n1, const BigNumber & n2); //
	friend bool operator >  (const BigNumber & n1, const BigNumber & n2);// 
	friend bool operator >= (const BigNumber & n1, const BigNumber & n2); //
	friend bool operator <= (const BigNumber & n1, const BigNumber & n2); //
	friend char * reverse(const BigNumber & number);	//
	friend void afisareNumar(const BigNumber & nr);		//
	char operator[] (int index); // returneaza caracterul de pe pozitia index sau \0 in rest
	BigNumber operator() (int start, int end); // returneaza subnumarul de la caracterul start pana la caracterul index sau "0" daca start/index nu sunt valide.
	operator const int();
};

