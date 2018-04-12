// HW 16-1 CSC215 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template<class T>
T minimum(T a, T b)
{
	if (a < b) return a;
	if (b < a) return b;
	if (b == a) return b;
}

template<class T>
T maximum(T a, T b)
{
	if (a > b) return a;
	if (b > a) return b;
	if (b == a) return b;
}

int main()
{
	cout << minimum(3.0, 5.5) << endl;
	cout << minimum(3, 5) << endl;
	cout << maximum(3.0, 5.5) << endl;
	cout << maximum(9, 99) << endl;

    return 0;
}

