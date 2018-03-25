// CW_9_4_CSC_215_LaGuardia-LoBianco.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>

using namespace std;

void calcMean(const int*, double*, const int);

int main()

{
	const int ArraySize = 5;
	const int Set[ArraySize] = {0, 0, 0, 0, 0};
	int Set1[ArraySize] = { 0, 0, 0, 0, 0 };
	double mean = 0.0, variable = 0;
	double * const meanPtr = &mean;
	
	for (int k = 0; k < ArraySize; ++k)
	{
	cout << "Please enter a test grade: " << endl;
	cin >> variable;
	Set1[k] = variable;
	}
	
	calcMean(Set, meanPtr, ArraySize);
	cout << "your mean, as defined by the pre-given in the const array, Set, is " << *meanPtr << endl;
	calcMean(Set1, meanPtr, ArraySize);
	cout << "your mean, as defined by the user and entered into array Set1, is " << *meanPtr << endl;

	return 0;
}

void calcMean(const int *Set, double *meanPtr, const int ArraySize)

{
	double variable1 = 0;
	double sum = 0;

	for (int k = 0; k < ArraySize; ++k)
	{
		variable1 = Set[k];
		sum = sum + variable1;
	}
	
	*meanPtr = (sum / ArraySize);

}