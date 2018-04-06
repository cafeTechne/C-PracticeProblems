// CW 10-1 CSC215 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <cctype>
#include <iostream>
#include <cstring>

using namespace std;

void capitalize(char *charPtr)
{
	bool flag = true;
	int count = 0;
	char c;
	c = charPtr[count];

	
	while (c = charPtr[count] && *charPtr != '\0')
	{
			if (!(isupper(c)) && !(isspace(c)) && flag == true)
			{
				c = charPtr[count];
				c = toupper(c);
				charPtr[count] = c;
				flag = false;
			}			
			if ((ispunct(charPtr[count])))
			{
				flag = true;
			}
			else flag = false;
			count++;
			if (isspace(c))
			{
				flag = true;
			}
	}
}

int main()
{
	const int SIZE = 140;	//array size
	char line[SIZE];	//to hold a line of input
	int count = 0;		//loop counter variable
	char* charPtr = nullptr;
	charPtr = line;

	cout << "User, enter three sentences--each ending with punctuation please!" << endl;
	cin.getline(line, SIZE);
	capitalize(line);
	
	cout << endl << line << endl;
	cout << endl << "String length of the sentences is :" << strlen(line) << endl;
	cout << "sentences reversed are :" << strrev(line) << endl;

	cout << "User, enter three sentences--each ending with a period!" << endl;
	cin.getline(line, SIZE);
	capitalize(line);
	cout << endl << line << endl;
	cout << endl << "String length of the sentences is :" << strlen(line) << endl;
	cout << "sentences reversed are :" << strrev(line) << endl;

	return 0;
}