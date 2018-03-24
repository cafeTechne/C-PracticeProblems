// HW Chapter 10 Problem 8 CSC215 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


/*
Gino
Challenge: Sum of Digits in a String

() Write a program that asks for the user to enter a series of single digit numbers with nothing separating them.
() 1`Read the input as a C-string or a string object.

()The program should display the sum of all the single-digit numbers in the string.
For example, if the user enters 2 5 1 4, th eprogram should display 12, which is the sum of 2, 5, 1, and 4.

()The program should also display the highest and lowest digit in the string.

*/

using namespace std;

int main()
{

	int count = 0;
	const int SIZE = 180;
	char arr[SIZE] = {};
	char c, c2;
	int i, i1, i2, i3;
	
	int  sum = 0;
	int lowestNumber = 0;
	int highestNumber = 0;


	cout << " User, enter some numbers for me to add: " << endl;
	cin >> arr;
	

	for (count=0; count < strlen(arr); count++)
	{
		sum += (arr[count] - '0');
	}

	for (count = 0; count < strlen(arr); count++)
	{
		for (int count = 0; count < strlen(arr); count++)
		{
			if ((arr[count] - '0')> highestNumber)
				highestNumber = (arr[count] - '0');
		}
		
		for (int count = 0; count < strlen(arr); count++)
		{
			if ((arr[count] - '0')< lowestNumber)
				lowestNumber = (arr[count] - '0');
		}
	}

	cout << "Your sum is : " << sum << endl;
	cout << "Your lowest number is " << lowestNumber << endl;
	cout << "Your highest number is " << highestNumber << endl;

	cout << "Was this correct?" << endl;
	int dummy;
	cin >> dummy;

	return 0;

}
