#pragma once
template<class T>

class ArrayIterator
{
private:
	int Current=0; // mai adaugati si alte date si functii necesare pentru iterator
	int Final;
	T **Lista;

public:
	ArrayIterator();
	ArrayIterator(T **lista,int Final);
	ArrayIterator& operator ++ (int);
	ArrayIterator& operator -- (int);
//	bool operator= (ArrayIterator<T> &);
	bool operator!=(ArrayIterator<T> &);
	T* GetElement();
};

template<class T>
ArrayIterator<T>::ArrayIterator(){}


template<class T>
 ArrayIterator<T>::ArrayIterator(T **L,int Final)
{
	Lista = L;
	this->Current = 0;
	this->Final = Final;
}

template<class T> 
T* ArrayIterator<T>::GetElement()
{
	return *(Lista + Current);
}

template<class T>
ArrayIterator<T>& ArrayIterator<T>::operator++ (int){
	if ((Current - Final) == 1)
		throw "Eroare nr. 1\n";
	else
		Current++;
	return *this;
}

template<class T>
ArrayIterator<T>& ArrayIterator<T>::operator-- (int){
	if (Current == 0)
		throw "Eroare nr. 2\n";
	else
		Current--;
	return *this;
}


//bool operator!=(ArrayIterator<T> &);
template<class T>
bool  ArrayIterator<T>::operator != (ArrayIterator<T> &it2)
{
	if (this->Current != it2.Final)
	{
		return true;
	}
	else
		return false;
}