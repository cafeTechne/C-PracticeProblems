// Chapter_9_HW_p546_12_LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

/*
Gino 
Chapter 9, p. 546, problem 12
Challenge: Write a function that accepts an int array and the array's size as arguments.
The function should create a new array that is one element larger than the argument array.
The first element of the new array should be set to 0. 
Element 0 of the argument array should be copied to element 1 of the new array,
Element 1 of the argument array should be copied to element 2 of the new array, and so forth. 
The function should return a pointer to the new array.
*/

using namespace std;

int* elementShifter(int *array1, const int SIZE);

int main()
{
//	int dummyVariable;
	const int SIZE = 5;
	int array1[SIZE] = { 1, 2, 3, 4, 5 };

	int* array2 = elementShifter(array1, SIZE);

//	cout << "test" << endl;
//	cin >> dummyVariable;
	return 0;
}

int* elementShifter(int *array1, const int SIZE)
{	
	int *arrayPtr;
	
	arrayPtr = new int[SIZE + 1];
	arrayPtr[0] = 0;
	
	cout << "value of arrayPtr is : " << arrayPtr[0] << " " << endl;
	for (int i = 0; i < SIZE; ++i)
	{
		arrayPtr[i + 1] = array1[i];

		cout << "value of array1 is : " << array1[i] << " " << endl;
		cout << "value of arrayPtr is : " << arrayPtr[i + 1] << " " << endl;
	}

	return arrayPtr;
	delete[] arrayPtr;

}
