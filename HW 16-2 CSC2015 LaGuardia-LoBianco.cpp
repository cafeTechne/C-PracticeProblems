// HW 16-2 CSC2015 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//stl binary search 

/*
modify programming challenge 1 in chapter 8 (change account) so it 
uses a vector instead of an array. Aso, modify the program so it uses
the STL binary_search algorithm to locate valid account numbers
*/

int main()
{
	vector<int> v = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
	8080152, 4562555, 5552012, 5050552, 7825877, 1250255, 1005231, 6545231, 3852085,
	7576651, 7881200, 4581002};

	int input;

	cout << "User, enter an account number for authorization: " << endl;
	cin >> input;

	sort(v.begin(), v.end());

	
		//if (v[i] == input) 
		if (std::binary_search(v.begin(), v.end(), input))
		{
			cout << " That number is authorized. " << endl;
		}
		else cout << " That number is not authorized!" << endl;

    return 0;
}

