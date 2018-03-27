// LaGuardia-LoBianco_CH8_Problem_21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/****************************************************************
Gino LaGuardia-LoBianco, Chapter 8, Problem 21:

**This program expands on Problem 19 by incorporating a 3-dimensional
Vector. It modifies problem 19 so that two grids are used and so 
that the program can perform the updates AS IF they all happen at
the same time. Thus, all temperatures are updated using one set of
grid values (v2 [x][x][0]). The two grids are needed so that all 
the old temperatures are available to compute each new temperature.

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
			//Declare and initialize objects!
	double top, bottom, left, right, firstAveraging, 
		touchingAbove, touchingBeneath, oldValue,
		touchingRight, touchingLeft, userDefinedToleranceValue;
	int m = 0, userDefinedValueSatisfiedCounter;
	vector<vector<vector<double> > > v2(8, vector<vector<double> >(8, vector <double>(2)));  //  I incorporate a 3-d Vector here to meet the problem's expectations, 
																							//I could have done it with just 2, 2-d vectors, conceptually the same thing.
	//Prompt user to define edges
	cout << "User, define the value for top " << endl;
	cin >> top;
	cout << "User, define the value for bottom " << endl;
	cin >> bottom;
	cout << "User, define the value for left " << endl;
	cin >> left;
	cout << "User, define the value for right " << endl;
	cin >> right;
	cout << "User, define your Tolerance Value " << endl;

	//input checking
	cin >> userDefinedToleranceValue;
		if (cin.fail())
		{
			cout << "cin failed!";
			exit(-1);
		}

	for (int i = 0; i <= v2.size() - 1; ++i) //offset to the top
	{
		v2[i][0][0] = top;
		v2[i][0][1] = top;

	}
	for (int i = 0; i <= v2.size() - 1; ++i) //offset to the bottom
	{
		v2[i][4][0] = bottom;
		v2[i][4][1] = bottom;
	}
	for (int i = 1; i <= v2[0].size() - 2; ++i) //offset to the left
	{
		v2[0][i][0] = left;
		v2[0][i][1] = left;
	}
	for (int i = 1; i <= v2[0].size() - 2; ++i) //offset to the right
	{
		v2[6][i][0] = right;
		v2[6][i][1] = right;
	}
	while (m<99999) //the whole thing is nested in a finite loop
	{
		for (int j = 1; j < v2[0].size() - 2; ++j)
		{
			for (int i = 1; i < v2.size() - 2; ++i)
			{
				auto touchingAbove = (v2[i][j - 1][0]);  //define the values around the point on the grid
				auto touchingBeneath = (v2[i][j + 1][0]);
				auto touchingRight = (v2[i + 1][j][0]);
				auto touchingLeft = (v2[i - 1][j])[0];
				v2[i][j][1] = ((touchingAbove + touchingBeneath
					+ touchingLeft + touchingRight + (v2[i][j][0])) / 5.0); //finds average
				firstAveraging = v2[i][j][1]; 
				v2[i][j][0] = v2[i][j][1];
				oldValue = v2[i][j][0];
			}

			if (((oldValue - firstAveraging) || (firstAveraging - oldValue)) < userDefinedToleranceValue) //compares difference both ways, because signed numbers.
			{
				cout << " User Defined Tolerance Threshold met for a single point! " << endl;
				++userDefinedValueSatisfiedCounter;
				cout << "user1 is " << userDefinedValueSatisfiedCounter << endl;

				if (userDefinedValueSatisfiedCounter >= 500) //arbitrarily large number so that it iterates after established value is met and a more accurate answer
				{
					cout << "All of the Temperature grid-values in the metal plate are within the userDefinedToleranceValue!" << endl;
					cout << endl << "The temperature is " << firstAveraging;
					return 0;
				}
			}
		}
		++m;
	}
	return 0;
}