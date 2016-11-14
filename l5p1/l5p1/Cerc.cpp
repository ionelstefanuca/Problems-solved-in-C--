#include"stdafx.h"
#include"Cerc.h"

Cerc::Cerc(int raza)
{
	this->Raza = raza;
}

const char* Cerc::GetName()
{
	return "Cerc";
}

double Cerc::ComputeArea()
{
	return this->Raza*this->Raza*3.14;
}