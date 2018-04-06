// Chapter_9_HW_p546_10_LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

/*
Gino
Chapter 9, problem 10, page 546.
Challenge: Write a program that accepts an int array and the array's size as arguments.
the function should create a copy of the array, except that the element values should be reversed
in the copy. The function should return a pointer to the new array. Demonstrate the function
in a complete program.

*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int* reverseCopyArray(int *array, const int SIZE);

int main()
{
	const int SIZE = 5;
	int array1[SIZE] = { 1, 2, 3, 4, 5 };

	int* array2 = reverseCopyArray(array1, SIZE);

    return 0;
}

int* reverseCopyArray(int *array1, const int SIZE)
{
	int accumulator = 0;
	int array2[5] = { 0,0,0,0,0 };
	int *arrayPtr = new int[SIZE];

	for (int i = 0; i < SIZE; ++i)
	{
		accumulator = array1[SIZE - (i+1)];
		cout << "value stored in the i'th element array1 : " << array1[i] << endl;
		array2[i] = accumulator;		
		cout << "new value stored in the i'th element of array2 : " << array2[i] << endl;
	}
	return arrayPtr;
	delete[] arrayPtr;
}