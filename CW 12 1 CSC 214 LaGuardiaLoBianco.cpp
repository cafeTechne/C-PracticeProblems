// CW 12-1 CSC215 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main()
{

	double i, j, k;
	string userDefinedFileName, dummyVariable;
	ifstream input;
	ofstream output;


	cout << "User please enter the name of a file that contains numbers" << endl;
	cin >> userDefinedFileName;


	input.open(userDefinedFileName);
	if (!input)
	{
		cout << "File open failure!";
		cout << "User, can you read this?" << endl;
		cin >> dummyVariable;
		exit(-1);
	}

	output.open("output.txt");
	while (!(input.eof())) //assignment help
	{
		input >> i;
		j = sqrt(i);
		output << j << endl;
	}

	cout << "User, can you read this?" << endl;
	cin >> dummyVariable;


	return 0;
}