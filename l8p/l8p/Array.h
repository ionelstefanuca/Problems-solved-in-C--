#pragma once
#include"ArrayIterator.h"
#include"Compare.h"

template<class T>
class Array
{
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista

public:
	Array(); // Lista nu e alocata, Capacity si Size = 0
	~Array(); // destructor
	Array(int capacity); // Lista e alocata cu 'capacity' elemente
	Array(const Array<T>&); // constructor de copiere

	T& operator[] (int index); // arunca exceptie daca index este out of range

	const Array<T>& operator+=(const T&); // adauga un element de tipul T la sfarsitul listei si returneaza this
	const Array<T>& Insert(int index, const T&); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Insert(int index, const Array<T>); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

	bool operator=(const Array<T> &);

	void Sort(); // sorteaza folosind comparatia intre elementele din T
	void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
	void Sort(Compare *comparator); // sorteaza folosind un obiect de comparatie

	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T&); // cauta un element folosind binary search in Array
	int BinarySearch(const T&, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
	int BinarySearch(const T&, Compare *comparator);//  cauta un element folosind binary search si un comparator

	int Find(const T&); // cauta un element in Array
	int Find(const T&, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
	int Find(const T&, Compare *comparator);//  cauta un element folosind un comparator

	int GetSize();
	int GetCapacity();
	void afisareArrayInt();

	ArrayIterator<T> GetBeginIterator();
	ArrayIterator<T> GetEndIterator();

	
};


template<class T>
Array<T>::Array()
{
	Capacity = -1;
	Size = -1;
	List = NULL;
}

template<class T>
Array<T>::~Array()
{
	delete[] List;
}

template<class T>
Array<T>::Array(int capacity)
{
	this->Capacity = capacity;
	this->Size = 0;
	this->List = new T*[Capacity];
}

template<class T>
const Array<T>& Array<T>::operator+=(const T& element)
{
	int i = Size;
	i++;
	if (i > Capacity)
		throw "Eroare nr1";

	List[Size++] = new T(element);

	return *this;
}

template < class T>
T& Array<T>::operator[] (int index)
{
	if (index<0 && index>Size)
		throw "Eroare nr2";

	return *List[index];
}

template<class T>
Array<T>::Array(const Array<T>& ar)
{
	this->Capacity = ar.Capacity;
	this->List = new T*[Capacity];
	if (ar.List)
	for (int i = 0; i < ar.Size; i++)
	{
		this->List[i] = new T(*ar.List[i]);
	}
	else
		this->List = NULL;
	this->Size = ar.Size;
}

//const Array<T>& Insert(int index, const T&);
template<class T>
const Array<T>& Array<T>::Insert(int index, const T& val)
{
	if (index > Capacity)
		throw "Eroare nr3";
	else
	{
		if (Size < index)
		{
			for (int i = Size; i < index; i++)
				List[i] = new T(NULL);
		}

		List[index] = new T(val);
	}

	return *this;
}

//const Array<T>& Insert(int index, const Array<T>); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
template<class T>
const Array<T>& Array<T>::Insert(int index, const Array<T> array)
{
	if (index<0 || index>Capacity)
	{
		throw "Eroare nr.4";
	}
	else
	if (Capacity < (Size + array.Size))
	{
		throw "Eroare nr.5";
	}
	else
	{
		int m = index;
		for (int i = 0; i < array.Size; i++)
		{
			List[m] = new T(NULL);
			List[m] = array.List[i];
			m++;
			Size++;
		}
	}
	return *this;
}

//const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
template<class T>
const Array<T>& Array<T>::Delete(int index)
{
	if (index<0 || index>Capacity)
	{
		throw "Eroare nr. 5 ";
	}
	else
	{
		// stergem elementul // mutam elementele cu o pozitie// scadem size
		for (int i = index; i < Size - 1; i++)
		{
			List[i] = List[i + 1];
		}
		List[Size] = NULL;
		Size--;
	}

	return *this;
}

template<class T>
int Array<T>::GetCapacity()
{
	return this->Capacity;
}

template<class T>
int Array<T>::GetSize()
{
	return this->Size;
}


template<class T>
bool Array<T>::operator=(const Array<T> &el)
{
	if (el.GetSize() == 0)
	{
		return false;
	}

	this->Capacity = el.Capacity;
	this->List = new T[GetCapacity];
	for (int i = 0; i < el.GetSize(); i++)
	{
		this += el[i];
	}

	return true;
}

template<class T>
void Array<T>::afisareArrayInt()
{
	if (Size == 0)
	{
		printf("Array-ul este null\n");
	}
	else
	{
		printf("Elementele array-ului sunt:\n");
		for (int i = 0; i < Size; i++)
		{
			printf("array[%d]=%d\n", i, *List[i]);
		}
	}
}

template<class T>
void Array<T>::Sort()
{
	for (int i = 0; i < GetSize();i++)
	for (int j = 0; j < GetSize(); j++)
	{
		if (*List[i] <*List[j])
		{
			T variabila = *List[j];
			*List[j] = *List[i];
			*List[i] = variabila;
		}
	}
}

//void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
template<class T>
void Array<T>::Sort(int(*compare)(const T&e1, const T&e2))
{
	for (int i = 0; i < GetSize();i++)
	for (int j = 0; j < GetSize(); j++)
	{
		if (compare(*List[i], *List[j]) == 1)
		{
			T variabila = *List[j];
			*List[j] = *List[i];
			*List[i] = variabila;
		}
	}
}

//	void Sort(Compare *comparator); // sorteaza folosind un obiect de comparatie
template<class T>
void Array<T>::Sort(Compare *comparator)
{
	for (int i = 0; i < GetSize(); i++)
	for (int j = 0; j < GetSize(); j++)
	{
		if (comparator->CompareElements((void*)*List[i], (void*)*List[j]) == 1)
		{
			T variabila = *List[j];
			*List[j] = *List[i];
			*List[i] = variabila;
		}
	}
}

//int BinarySearch(const T&); // cauta un element folosind binary search in Array
template <class T>
int Array<T>::BinarySearch(const T& var)
{
	int p = 0;
	int q = Size - 1;
	int m = (p + q) / 2;

	while ((*List[m] != var) && (p < q))
	{
		if (var < *List[m])
			q = m - 1;
		else
			p = m + 1;
		m = (p + q) / 2;
	}

	if (*List[m] == var)
		return m;
	else
		return -1;
}

template<class T>
int Array<T>::BinarySearch(const T& var, int(*compare)(const T&, const T&))
{
	int p = 0;
	int q = Size - 1;
	int m = (p + q) / 2;

	while (compare (*List[m] , var) !=0 && (p < q))
	{
		if (compare(var , *List[m])==1)
			q = m - 1;
		else
			p = m + 1;
		m = (p + q) / 2;
	}

	if (compare(*List[m] ,var)==0)
		return m;
	else
		return -1;
}

//int BinarySearch(const T&, Compare *comparator);//  cauta un element folosind binary search si un comparator
template<class T>
int Array<T>::BinarySearch(const T& var, Compare *comparator)
{
	int p = 0;
	int q = Size - 1;
	int m = (p + q) / 2;

	while (comparator->CompareElements((void*)*List[m], (void*) var) != 0 && (p < q))
	{
		if (comparator->CompareElements((void*)var, (void*)*List[m]) == 1)
			q = m - 1;
		else
			p = m + 1;
		m = (p + q) / 2;
	}

	if (comparator->CompareElements((void*)*List[m], (void*)var) == 0)
		return m;
	else
		return -1;
}

//int Find(const T&); // cauta un element in Array
template<class T>
int Array<T>::Find(const T& element)
{
	for (int i = 0; i < GetSize(); i++)
	{
		if (*List[i] == element)
			return i;
	}
	return -1;
}


//int Find(const T&, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
template<class T>
int Array<T>::Find(const T& element, int(*compare)(const T&, const T&))
{
	for (int i = 0; i < GetSize(); i++)
	{
		if (compare(*List[i], element) == 0)
			return i;
	}
	return -1;
}


//int Find(const T&, Compare *comparator);//  cauta un element folosind un comparator
template<class T>
int Array<T>::Find(const T &el, Compare *compare)
{
	for (int i = 0; i < GetSize(); i++)
	{
		if (compare->CompareElements((void*)*List[i], (void*)el) == 0)
			return i;
	}
	return -1;
}

template<class T>
ArrayIterator<T> Array<T>::GetBeginIterator()
{
	T **el = List;
	ArrayIterator<T> it(el,GetSize());
	return it;
}

template<class T>
ArrayIterator<T> Array<T>::GetEndIterator()
{
	T **el = List;
	el += GetSize()-1;
	ArrayIterator<T> it(el,GetSize());

	return it;
}