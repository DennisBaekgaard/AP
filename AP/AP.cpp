// AP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CleverCollection.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	unique_ptr<CleverCollection<int>> myCol(new CleverCollection<int>);
	
	char something; 
	for (int i = 0; i < 9; i++)
		myCol->Add(i);

	myCol->Dump();

	
	cout << "Adding new entried" << endl;

	for (int i = 0; i < 6; i++)
		myCol->Add(i);
	
	myCol->Dump();


	cout << "Tried";
	cin >> something;

	return 0;
}

