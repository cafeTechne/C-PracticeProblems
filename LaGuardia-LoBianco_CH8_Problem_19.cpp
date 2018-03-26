// LaGuardia-LoBianco_CH8_Problem_19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/****************************************************************
Gino LaGuardia-LoBianco, Chapter 8, Problem 19:

This program models the temperature distribution for a grid with
six rows and eight columns. It prompts the user to enter the 
temperatures for the four sides. It uses one grid to store the
temperatures. Thus, when a point is updated, its new value is
used to update the next opint. It continues updating the points,
moving across the rows until the temperature differences for all
updates are less than a user-entered tolerance value.  It uses
the vector class to implement the grid.

						Background: 
The temperature distribution in a thin metal plate with constant
(or isothermal) temperatures on each side can be modeled using a
two-dimensional grid. Typically, the number of points in the grid 
are specified, as are the constant temperatures on the four sides. 
The temperatures of the interior points are usually intiialized
to zero, but they change according to the temperatures around them.
Assume that the temperature of an interior point can be computed as 
the average of the four adjacent temperatures. Each time that the
temperature of an interior point changes, the temperatures of the
points adjacent to it change. These changes continue until a 
thermal equilibrium is achieved and all temperatures become constant.
*/
int main()
{
	//declare and initialize variables
	double top, bottom, left, right, firstAveraging, firstAverage, placeHolderVariable,
		   touchingAbove, touchingBeneath, userDefinedToleranceValue, 
		   touchingRight, touchingLeft, differenceBetweenX2andX1;
	static int m = 0, userDefinedValueSatisfiedCounter;
	vector< vector<double> > v(8, vector<double>(6));
	
	cout << "User, define the value for top " << endl;				//prompts user for input
	cin >> top;
	cout << "User, define the value for bottom " << endl;
	cin >> bottom;
	cout << "User, define the value for left " << endl;
	cin >> left;
	cout << "User, define the value for right " << endl;
	cin >> right;
	cout << "User, define your Tolerance Value " << endl;
	cin >> userDefinedToleranceValue;

	for (int i = 0; i <= v.size() - 1; ++i) //offset to the top          //The user defined temperature values are 
	{																	 //entered into the grid.
		v[i][0] = top;
	}
	for (int i = 0; i <= v.size() - 1; ++i) //offset to the bottom
	{
		v[i][4] = bottom;								
	}
	for (int i = 1; i <= v[0].size() - 2; ++i) //offset to the left
	{
		v[0][i] = left;
	}
	for (int i = 1; i <= v[0].size() - 2; ++i) //offset to the right
	{
		v[6][i] = right;
	}
	while(m<99999) //loops a denumerable number of times in case the user defined tolerance value is wacky
	{ 
		for (int j = 1; j < v[0].size() - 2; ++j) //then iterates the inner loop over the j'th vector
		{
			for (int i = 1; i < v.size() - 2; ++i) //fills the ith vector with the average of the point and all adjacent points
			{
				auto touchingAbove = (v[i][j - 1]);
				auto touchingBeneath = (v[i][j + 1]);
				auto touchingRight = (v[i + 1][j]);
				auto touchingLeft = (v[i - 1][j]);
				placeHolderVariable = v[i][j];
				v[i][j] = ((touchingAbove + touchingBeneath
					+ touchingLeft + touchingRight + (v[i][j])) / 5.0);
				firstAveraging = v[i][j];
			}
			if (((placeHolderVariable-firstAveraging) || (firstAveraging-placeHolderVariable)) < userDefinedToleranceValue) //this checks to see if the difference of the point and the point prior to it 
			{																												//are within the user defined tolerance... I used an OR to handle different signs 
				cout << " User Defined Tolerance Threshold met for a single point! " << endl;							
				++userDefinedValueSatisfiedCounter;
				cout << "user1 is " << userDefinedValueSatisfiedCounter << endl; //increments a counter if the threshold is met for a point
				
				if (userDefinedValueSatisfiedCounter >= 46) //I set the counter to 46 to ensure it cycles through twice within tolerance to introduce a factor of safety due to the possibility of rounding error
				{
					cout << "All of the Temperature grid-values in the metal plate are within the userDefinedToleranceValue!" << endl;
					cout << endl << "The temperature is " << firstAveraging;
					return 0;
				} 
			}
		}
		++m;
		//userDefinedValueSatisfiedCounter = 0;
	}
	return 0;
}

