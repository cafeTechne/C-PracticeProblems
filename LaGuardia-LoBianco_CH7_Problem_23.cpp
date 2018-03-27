// LaGuardia-LoBianco_CH7_Problem_23.cpp : Defines the entry point for the console application.
//

/* Gino LaGuardia-LoBianco, Chapter 7, Problem 23:


This program reads a data file and determines the number of occuerrences of each of the characters in the file
Then, it prints the characters and the number of times that they occured. If a character does not occur, do not print it.
(Hint: Use an array to store the occurences of the characters based on their ASCII codes.)
*/

#include "stdafx.h"
#include <iostream> //cout
#include <fstream> //needed for ifstream
#include <vector> //needed for vector
#include <algorithm> //needed for sort

using namespace std;

int main()
{   //declare variables
	ifstream fin;
	fin.open("crypto.txt"); //opens file
	char input;
	vector <char> v;  //instantiate vector v of type char

	if (fin.fail())  //error checking
	{
		cout << "Failed reading";
		return -1;  //records fail bit
	}
	else
	{
		while (fin >> input) //this loop takes input and feeds it into the array
		{					 //i read on stack exchange that !x.eof() is no bueno.
			v.push_back(input); //pushes data into vector
		}
		
		sort(v.begin(), v.end()); //sorts vector
		auto currentValue = v[0]; // stores the value of the 0th indice of vector v into variable
		int counter = 1; //initializes the counter to one

		for (auto m = 1; m < v.size(); m++) //starts at 1 because counter is already at 1 from starting at index of 0.
		{
			if (v[m] == currentValue) //if there are multiples of a number, then increment the counter
			{
				counter++;
			}
			else //otherwise
			{
				cout << v[m - 1] << " " << counter << endl; //output to display the last value of the array 
				counter = 1;								//started m@1, whereas the array starts at 0, so the final value
				currentValue = v[m];						// is m-1.
			}
		}

		//cout << v[v.size()-1] << " " << counter << endl;
	}
	return 0;
}
