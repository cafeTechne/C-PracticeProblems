// EuclideanAlgorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//This is another exercise from the Google Problem set here:
// https://developers.google.com/edu/c++/getting-started

int main()
{
	bool solved=false;
	unsigned int a=0, b=0, c=0;
	cout << "This program finds the GCD using the Euclidean Algorithm: " << endl;

	cout << "User, please define your first variable!" << endl;
	cin >> a;

	cout << "User, please define your second variable!" << endl;
	cin >> b;

	if (a < b) 
	{
		c = a;
		a = b;
		b = a;
	}
	while (solved == false)
	{
		c = a%b;
		if (c == 0) {
			cout << b << " is the GCD!" << endl;
			solved = true;
			return 0;
			}
		a = b;
		b = c;	
	}

    return 0;
}

