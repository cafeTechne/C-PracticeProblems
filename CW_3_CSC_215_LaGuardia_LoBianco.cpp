// CW_3_CSC_215_LaGuardia_LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string> //to use strings
#include <iostream> //for input/output

using namespace std;

const int setSize = 5;

int main()
{

	int set[setSize] = { 10, 30, 54, 76, 8 };
	int *setPtr = nullptr;

	setPtr = set;

	
	for (int k = 0; k < 5; ++k)	 //
	{
		cout << set[k] << endl;
	}
	
	
	for (int k = 0; k < 5; ++k)
	{
		cout << *(setPtr+k) << endl;
	}
	

	for (int k = 0; k < setSize; ++k)   // why is it the case that if I put
	{									// this for loop above the one previous to
	cout << *setPtr << endl;            // to it, the program returns strange values?
	++setPtr;
	}
	
	return 0;
}

