#include "stdafx.h"
#include "IntList.h"

IntList::IntList()
{
	printf("Am creat un obiect de tip lista\n");
	this->Count = 0;
}

bool IntList::Add(int x)
{
	if (this->Count == 1000)
	{
		return false;
	}
	else
	{
		this->Count++;
		this->Elemente[this->GetCount()] = x;
	}
	return true;
}

int IntList::Get(int x)
{
	if (x > this->Count)
		return -1;
	else
		return this->Elemente[x+1]; //numaram de la 0
}

int IntList::GetCount()
{
	return this->Count;
}

bool IntList::Delete(int index)
{
	if (this->GetCount() < index)
		return false;
	else
	if (index>1000)
		return false;
	else
	{
		for (int i = index; i <= this->GetCount(); i++)
		{
			this->Elemente[i] = this->Elemente[i + 1];
		}
		this->Count--;
		return true;
	}
}

bool IntList::Insert(int index, int element)
{
	if (index<1)
		return false;
	
	if (index > 1000)
		return false;
	
	if (index > this->GetCount())
		return false;
	

		this->Elemente[index] = element;
	
	return true;
}

void IntList::Clear()
{
	for (int i = 0; i < this->GetCount(); i++)
		this->Elemente[i] = 0;

	this->Count = 0;
}

int IntList::IndexOf(int valoare, int startPosition)
{
	for (int i = startPosition; i <= this->GetCount(); i++)
		if (this->Elemente[i] == valoare)
			return i;

		return -1;	
}

void IntList::Sort()
{
	for (int i = 1; i <= this->GetCount();i++)
	for (int j = i; j <= this->GetCount(); j++)
	{
		if (this->Elemente[i]>this->Elemente[j])
		{
			int aux;
			aux = this->Elemente[i];
			this->Elemente[i] = this->Elemente[j];
			this->Elemente[j] = aux;
		}
	}
}

void IntList::RemoveDuplicates()
{
	this->Sort();

	for (int i = 0; i <= this->GetCount();i++)
		if (this->Get(i) == this->Get(i + 1))
		{
			int k = i + 1;
			bool bucla = true;
			while (bucla)
			{
				this->Delete(k);
				if (this->Get(i) != this->Get(k))
					bucla = false;
			}
		}
}
void IntList::Reverse()
{
	for (int i = 1; i <= this->GetCount(); i++)
	for (int j = i; j <= this->GetCount(); j++)
	{
		if (this->Elemente[i]<this->Elemente[j])
		{
			int aux;
			aux = this->Elemente[i];
			this->Elemente[i] = this->Elemente[j];
			this->Elemente[j] = aux;
		}
	}

}

void IntList::Intersection(IntList* withList, IntList * resultList)
{
	resultList->Clear();

	for (int i = 0; i < this->GetCount(); i++)
	{
		if ((withList->IndexOf(this->Get(i), 0)) != -1)
		{
			resultList->Add(this->Get(i));
		}
	}
}

void IntList::AfisareLista()
{
	printf("Afisare Lista:\n");
	for(int i = 0; i < this->GetCount(); i++)
	{
		printf("%d ", this->Get(i));
	}
	printf("\n");
}


void  IntList::Reunion(IntList* withList, IntList * resultList)
{
	resultList->Clear();

	this->RemoveDuplicates();
	withList->RemoveDuplicates();

	for (int i = 0; i < this->GetCount(); i++)
	{
		resultList->Add(this->Get(i));
	}

	for (int i = 0; i < withList->GetCount(); i++)
	{
		if ((this->IndexOf(withList->Get(i), 0)) == -1)
		{
			resultList->Add((withList->Get(i)));
		}
	}
}