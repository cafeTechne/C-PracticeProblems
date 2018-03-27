// HW Chapter 10 Problem 12 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cctype>

//Password Verifier
/*
Gino
Challenge: Imagine you are developing a software package that 
requires users to enter their own passwords. Your software
requires that users' passwords meet the following criteria:

o The password should be at least six characters long.
o The password should contain at least one uppercase and at
	least on lowercase letter.
o The password should have at least on dight.


Write a program that asks for a password and then verifies that 
it meets the stated criteria. If it doesn't, the program
should display a message telling the user why.

*/

using namespace std;

int main()
{
	int index = 0;
	const int SIZE = 180;
	
	char password[SIZE];
	char variable1[SIZE];
	char c, c1, c2;
	int alphaCounter=0, intCounter = 0, punctCounter = 0, lowerCaseCounter = 0, upperCaseCounter = 0;

	cout << "User what is your password?" << endl;
	cin >> password;

	for (int count = 0; password[count] < strlen(password); count++)
	{
		c = password[count];

		if (isalpha(c)) ++alphaCounter;
		if (isdigit(c)) ++intCounter;
		if (islower(c)) ++lowerCaseCounter;
		if (isupper(c)) ++upperCaseCounter;
	}

	if (strlen(password) < 6) cout << "Your pw does not have enough characters!" << endl;
	if (intCounter < 1) cout << "Your pw needs atleast one digit!" << endl;
	if (lowerCaseCounter < 1) cout << "Your pw needs atleast one lower case letter!" << endl;
	if (upperCaseCounter < 1) cout << "Your pw needs atleast one upper case letter!" << endl;

	cout << " test " << endl;
	
	return 0;
}

