// HW Chatper 10 CSC215 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

void backwardString(char* charPtr);

using namespace std;

int main()
{
	const int SIZE = 180;
	char line[SIZE] = {};
	cout << "User, please type in a block of text: " << endl;
	cin.getline(line, SIZE);

	backwardString(line);
	
	
	int variable;
	cout << "user test" << endl;
	cin >> variable;

    return 0;
}

void backwardString(char* charPtr)
{
	int count = 0;
	const int SIZE = 180;
	char arr[SIZE] = {};
	char c, c2;
	string s, s2;
	int variable = 0;
	
	while (c = charPtr[count] && *charPtr != '\0')
	{
		c = charPtr[count];
		s.push_back(c);
		++count;
	}
	cout << "Your string is : " << s << endl;
	count = 0;
	while (c = charPtr[count] && *charPtr != '\0')
	{
	
		c2 = s.back();
		s2.push_back(c2);
		s.pop_back();
		++count;
	}

	
	cout << "Your string reversed is : " << s2 << endl;

}