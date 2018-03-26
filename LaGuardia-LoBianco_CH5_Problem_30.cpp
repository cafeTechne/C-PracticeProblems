// LaGuardia-LoBianco_CH5_Problem_30.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> //needed for cerr
#include <fstream> //needed for ifstream
#include <string> //needed for string

using namespace std;

//Gino LaGuardia-LoBianco, CH5, Problem 30
//This program determines the number of days that had temperatures in the following categories for January 1991:
//a. Below 0, b. 0-32, c. 33-50, d. 51-60, e.61-70, f.Over 70. Note that the range of temperatures in one day may
//fall in several of the categories.


int main()
{
	ifstream inputFile("JAN91.TXT");							//This initializes the file and declares an object inputFile of class ifstream.
	int below0(0), below32(0), below50(0), below60(0), below70(0), above70(0);    //Declare and initialize variables
	double lowTemperature(0), highTemperature(0), placeHolderVariable(0), line(0);
	if (inputFile.fail())
	{
		cerr << "File input error!" << endl;
		exit(-1);										//This logs an error bit and exits the program if the file fails to load.
	}
	while (!inputFile.eof())																	//This while loop goes until it hits the end of the file.
	{
		inputFile >> line >> highTemperature >> lowTemperature;
		for (int i = 0; i <= 28; i++)
		{
			inputFile >> placeHolderVariable;
		}
		if (((highTemperature > 70)) ||  ((lowTemperature > 70)))                 //This tests whether one of the two values satisfies a condition for a given day, then counts how many days fall in what range (days can fall in multiple ranges).
		++above70;
		if (((highTemperature < 70) && (highTemperature >= 61)) || ((lowTemperature < 70) && (lowTemperature >= 61)))
		++below70;
		if (((highTemperature < 60) && (highTemperature >= 51)) || ((lowTemperature < 60) && (lowTemperature >= 51)))
		++below60;
		if (((highTemperature <= 50) && (highTemperature >= 33)) || ((lowTemperature <= 50) && (lowTemperature) >= 33))
		++below50;
		if (((highTemperature <= 32) && (highTemperature >= 0)) || ((lowTemperature <= 32) && (lowTemperature >= 0)))
		++below32;
		if ((highTemperature < 0) || (lowTemperature < 0))
			++below0;
	}
	cout << "Days with Temperature below 0 = " << below0 << endl << "Days with Temperature between 0-32 = " << below32 << endl << "Days with Temperature between 33 and 50 = " << below50 << endl << "Days with Temperature between 51 and 60 = " << below60 << endl << "Days with Temperature between 61 and 70 = " << below70 << endl << "Days with Temperature above 70 = " << above70 << endl;
	
	//This outputs and then returns out of the main function.
	 
    return 0;
}

