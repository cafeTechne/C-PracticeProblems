// LaGuardia-LoBianco_CH7_Problem_27.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

//Gino LaGuardia-LoBianco, CH7, Problem 27:

//This program encodes the text in a data file using a character array named key that 
//contains 26 characters. This key is read from the keyboard; the firest letter
// contains the character that is to replace the letter a in the data file,
// the second letter contains the letter that is to replace the letter b in the data file,
// Assume that all punctuation is to be replaced by spaces.
// check to be sure that the key does not map two different characters 
//to the same one during the encoding.

int main()
{	//declare variables
	ifstream fin; //input from file variable
	ofstream fout; //output to file variable
	char input, a, b, c;
	char v[26]; //array with 26 values
	char inputFileArray[50];
	bool found = false; //boolean flag for ensuring mapping is 1:1

	cout << "We will encrypt the alphabet starting from the letter 'a'." << endl
		<< "Please type in the first letter to encode the letter 'a' into: " << endl;
	cin >> input;
	v[0] = input;

	for (auto i = 0; i < 26; i++) //standard outer for loop
	{
		cout << "What is your next letter encoded to?";
		cin >> input;

		if (v[i] == input) // if the value of the i'th index of array v is equal to input,
		{				   // then set the flag to true
			found = true;
		}
		if (!(v[i] == input)) // if the value of the i'th index of array v is NOT equal to input,
		{					 // then set the flag to false
			found = false;
		}
		if (found == false) //if flag is set to false, then store the user's input as the
		{					//value of the i'th index of array v
			v[i] = input;
		}
	}

	fin.open("tobeencrypted.txt"); //opens file to be "encrypted"
	fout.open("encrypted.txt"); //opens file that output is sent to

	if (fin.fail())
	{
		cout << "Failed to load file!" << endl;
		exit;
	}

	for (int i = 0; i < 50; i++)  //runs a loop to check each char in the input file against each letter
	{							  //then replaces them with the corresponding array value
		fin >> a;				  //i couldn't think of a more elegant solution.
		if (a == 'a')
		{
			a = v[0];
			fout << a;
		}
		if (a == 'b')
		{
			a = v[1];
			fout << a;
		}
		if (a == 'c')
		{
			a = v[2];
			fout << a;
		}
		if (a == 'd')
		{
			a = v[3];
			fout << a;
		}
		if (a == 'e')
		{
			a = v[4];
			fout << a;
		}
		if (a == 'f')
		{
			a = v[5];
			fout << a;
		}
		if (a == 'g')
		{
			a = v[6];
			fout << a;
		}
		if (a == 'h')
		{
			a = v[7];
			fout << a;
		}
		if (a == 'i')
		{
			a = v[8];
			fout << a;
		}
		if (a == 'j')
		{
			a = v[9];
			fout << a;
		}
		if (a == 'k')
		{
			a = v[10];
			fout << a;
		}
		if (a == 'l')
		{
			a = v[11];
			fout << a;
		}
		if (a == 'm')
		{
			a = v[12];
			fout << a;
		}
		if (a == 'n')
		{
			a = v[13];
			fout << a;
		}
		if (a == 'o')
		{
			a = v[14];
			fout << a;
		}
		if (a == 'p')
		{
			a = v[15];
			fout << a;
		}
		if (a == 'q')
		{
			a = v[16];
			fout << a;
		}
		if (a == 'r')
		{
			a = v[17];
			fout << a;
		}
		if (a == 's')
		{
			a = v[18];
			fout << a;
		}
		if (a == 't')
		{
			a = v[19];
			fout << a;
		}
		if (a == 'u')
		{
			a = v[20];
			fout << a;
		}
		if (a == 'v')
		{
			a = v[21];
			fout << a;
		}
		if (a == 'w')
		{
			a = v[22];
			fout << a;
		}
		if (a == 'x')
		{
			a = v[23];
			fout << a;
		}
		if (a == 'y')
		{
			a = v[24];
			fout << a;
		}
		if (a == 'z')
		{
			a = v[25];
			fout << a;
		}

	}
	
	
    return 0;
}

