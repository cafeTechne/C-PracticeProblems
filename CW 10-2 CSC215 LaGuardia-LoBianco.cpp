// CW 10-2 CSC215 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cctype>
#include <string>


/*
Gino
Challenge: Write a main function that asks the user for the date in the format mm/dd/yyyy. 
It should print the date in the form August, 28, 2017.
*/

using namespace std;

void dateFormatChange(char* charPtr);

int main()
{
	const int SIZE = 180;
	char arr[SIZE] = {};
	char *charPtr = nullptr;
	
	cout << "User, please enter a date in the format mm/dd/yyyy" << endl;
	cin.getline(arr, SIZE);
	dateFormatChange(arr);

    return 0;
}

void dateFormatChange(char* charPtr)
{

	int count = 0;
	char c, d, e, f, g, h, i, j;
	c = charPtr[count];
	string day, month, year;

	while (c = charPtr[count] && *charPtr != '\0')
	{
		if (!(ispunct(c)))
		{
			c = charPtr[count];
			++count;
			d = charPtr[count];
			
			if (c == '0')
			{
				if (d == '1')
					month = "January";
				if (d == '2') 
					month = "February";
				if (d == '3') 
					month = "March";
				if (d == '4') 
					month = "April";
				if (d == '5') 
					month = "May";
				if (d == '6') 
					month = "June";
				if (d == '7') 
					month = "July";
				if (d == '8') 
					month = "August";
				if (d == '9') 
					month = "September";
			}
			if (c == '1')
			{
				if (d == '0') 
					month = "October";
				if (d == '1') 
					month = "November";
				if (d == '2') 
					month = "December";
			}
		}

		++count;

		if ((ispunct(charPtr[count])))
		{
			++count;
		}

		if (!(ispunct(charPtr[count])))
		{
			e = charPtr[count];
			++count;
			f = charPtr[count];
		
				day.push_back(e);
				day.push_back(f);

				++count;

			if ((ispunct(charPtr[count])))
			{
				++count;
			}

			if (!(ispunct(charPtr[count])))
			{
				g = charPtr[count];
				++count;
				h = charPtr[count];
				++count;
				i = charPtr[count];
				++count;
				j = charPtr[count];
				++count;

				year.push_back(g);
				year.push_back(h);
				year.push_back(i);
				year.push_back(j);

				cout << endl << "The date you specified is " << month << ", " << day << ", " << year << endl;

			}
		}
	}
}