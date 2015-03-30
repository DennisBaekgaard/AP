#pragma once
#include <memory>
#include <iostream>
using namespace std;
template<typename T>class CleverCollection
{
private:
	int size;
	int currentIndex;
	int nextEmpty;
	int lastIndex;
	unique_ptr<T[]> myCollection;
	void ExtendArray();
	

public:
	CleverCollection();
	~CleverCollection();
	void Add(T);
	void Remove(T);
	T First();
	T Last();
	T Next();
	T Prev();
	void Dump();
	void Clear();
};

/*
* Implementation here because of silly compiler linker crap codes.
*/
template<typename T>CleverCollection<T>::CleverCollection() : size{ 10 }, lastIndex{ 10 }, myCollection{ unique_ptr<T[]>(new T[10]) }, currentIndex{ 0 }, nextEmpty{ 0 }
{
	for (int i = 0; i <= size; i++)
		myCollection[i] = 0;
}

template<typename T> void CleverCollection<T>::Add(T object){
	myCollection[nextEmpty] = object;
	nextEmpty++;
	if (nextEmpty == lastIndex)
	{
		ExtendArray();
	}
}

template<typename T> void CleverCollection<T>::ExtendArray(){
	
	cout << "Called extend array" << endl;
	
	unique_ptr<T[]> tmp(new T[size]);

	for (int i = 0; i <= size; i++)
		tmp[i] = myCollection[i];

	myCollection.reset(new T[size*2]);


	for (int i = 0; i <= size; i++)
		myCollection[i] = tmp[i];

	size *= 2;
	lastIndex = size;


	//tmp.release();
}

template<typename T>CleverCollection<T>::~CleverCollection()
{
}

template<typename T> void CleverCollection<T>::Dump(){
	for (int i = 0; i < size; i++)
		cout << "Index: " << i << ":" << myCollection[i] << endl;

	cout << size << endl;
	cout << "Dump complete" << endl;
}