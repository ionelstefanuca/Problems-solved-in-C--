#include "stdafx.h"
#include "Triunghi.h"

const char * Triunghi::GetName()
{
	return "Triunghi";
}

Triunghi::Triunghi(int x1, int y1, int x2, int y2, int x3, int y3)
{
	this->X1 = x1;
	this->X2 = x2;
	this->X3 = x3;
	this->Y1 = y1;
	this->Y2 = y2;
	this->Y3 = y3;
}

double Triunghi::ComputeArea()
{
	return (X1*Y2 + X2*Y3 + Y1*X3 - Y2*X3 - Y3*X1 - Y1*X2);
}