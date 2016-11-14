#pragma once
class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

class CompareInt : public Compare
{
	int CompareElements(void* e1, void* e2)
	{
		if ((int)e1 == (int)e2)
			return 0;

		if ((int)e1 < (int)e2)
		{
			return 1;
		}
		else
			return -1;
	}
};