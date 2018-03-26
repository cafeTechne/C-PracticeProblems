// LaGuardia-LoBianco_CH8_Problem_16.cpp : Defines the entry point for the console application.
//

// LaGuardia-LoBianco_CH8_Problem_11.cpp : Defines the entry point for the console application.
//


/**********************************************************************************
Gino La Guardia-LoBianco, CH8, Problem 11.									  *
This program takes the data from the file POWER1.TXT,                             *
which has data from a powerplants output in Mega Watts over a period               *
of 10 weeks. Each row of data contains 7 floating-point numbers that represent    *
1 week's data.																	  *
*
This program computes and prints the average power otuput over the entire period  *
It also prints the number of days with greater-than-average power output          

It also writes a function to compute the average of a specified row of a
two-dimensional array that has NROWS rows and NCOLS columns. The parameteres should
be the floating-point array and the desired row. Assume that the corresponding function
prototype is

double row_ave(double x[]NCOLS] , int row);*
***********************************************************************************/
#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

const int NROWS = 10;
const int NCOLS = 7;

double row_ave(double x[NROWS][NCOLS], int row);
int main()
{	//declare and initialize variables & arrays (set to value of global const's above)
	int columnCount = 0, numberAboveAverageCounter = 0;
	auto userTextInput= 0;
	double runningSum = 0.0, fileInputOld = 0.0, inputVariable = 0.0;
	double a1[NROWS][NCOLS];

	ifstream fileInput; //initializes fstream object for reading in the file data
	fileInput.open("POWER1.TXT"); //opens the file

	if (fileInput.fail()) //checks for errors opening the file
	{
		cout << " File Input Failed!" << endl; //error message
		return -1; //C-style fail bit
	}
	for (; columnCount <= 9; ++columnCount) //feeds in data into the 2 dimensional  
	{									 //array in these nested loops.
		for (int j = 0; j <= 6; j++)
		{
			fileInput >> inputVariable;
			a1[columnCount][j] = inputVariable;
			runningSum = runningSum + a1[columnCount][j];
			fileInputOld = a1[columnCount][j];
		}
	}

	double averagePowerOutput = (runningSum / 70.0);
	cout << "Your average is " << averagePowerOutput << " MW." << endl;

	for (columnCount = 0; columnCount <= 9; ++columnCount) //2nd nested for loop checks values against average
	{													// increments counter for all days above 
		for (int j = 0; j <= 6; j++)
		{
			if ((a1[columnCount][j]) < averagePowerOutput)
			{
				++numberAboveAverageCounter;
			}
		}
	}

	cout << "The number of days with greater-than average power output is: "
		<< numberAboveAverageCounter << endl;

	cout << " What row do you want to know the particular average of?"
		<< endl;
	cin >> userTextInput;
	
	double randomVariable = 0.0;
	randomVariable = row_ave(a1, userTextInput);

	cout << "The average of the " << userTextInput << " row is "
		<< randomVariable << endl;
	return 0;
}

double row_ave(double x[][NCOLS], int row)
{
	auto Variable = 0, Variable1 = 0; //used auto because it increases readability
	auto rowAverage = 0.0;            //no reason to think about the type--it's given

	for (int j = 0; j <= NCOLS-1; j++)  
	{
		Variable1 = Variable1 + x[row][j];  //readapted the loop from before into this function
	}
	double intToDoubleConversionVariable = NCOLS;
	rowAverage = (Variable1/intToDoubleConversionVariable);
	return rowAverage;
}
