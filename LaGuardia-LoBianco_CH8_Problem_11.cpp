// LaGuardia-LoBianco_CH8_Problem_11.cpp : Defines the entry point for the console application.
//


/**********************************************************************************
   Gino La Guardia-LoBianco, CH8, Problem 11.									  *
This program takes the data from the file POWER1.TXT,                             *
which has data from a powerplants output in megawatts over a period               *
of 10 weeks. Each row of data contains 7 floating-point numbers that represent    *
1 week's data.																	  *	
																				  *	
This program computes and prints the average power otuput over the entire period  *
It also prints the number of days with greater-than-average power output          *
***********************************************************************************/
#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

const int NROWS=10;
const int NCOLS=7;

int main()
{	//declare and initialize variables & arrays (set to value of global const's above)
	int columnCount = 0, numberAboveAverageCounter=0; 
	double a1[NROWS][NCOLS], runningSum = 0.0, fileInputOld = 0.0, inputVariable = 0.0;
	ifstream fileInput; //initializes fstream object for reading in the file data
	fileInput.open("POWER1.TXT"); //opens the file

	if (fileInput.fail()) //checks for errors opening the file
	{
		cout << " File Input Failed!" << endl; //error message
		return -1; //C-style fail bit
	}
	for (;columnCount<=9; ++columnCount) //feeds in data into the 2 dimensional  
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
	
	for (columnCount=0; columnCount <= 9; ++columnCount) //2nd nested for loop checks values against average
	{													// increments counter for all days above 
		for (int j = 0; j <= 6; j++)					
		{
			if((a1[columnCount][j]) < averagePowerOutput)
			{
				++numberAboveAverageCounter;
			}
		}
	}
	
	cout << "The number of days with greater-than average power output is: "
		<< numberAboveAverageCounter << endl;

    return 0;
}

