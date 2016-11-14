#include"stdafx.h"
#include"Dreptunghi.h"

Dreptunghi::Dreptunghi(int lungime, int latime){
	this->Lungime = lungime;
	this->Latime = latime;
}

const char * Dreptunghi::GetName()
{
	return "Dreptunghi";
}

double Dreptunghi::ComputeArea()
{
	return Lungime*Latime/2;
}