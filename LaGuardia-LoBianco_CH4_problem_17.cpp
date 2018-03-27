// LaGuardia-LoBianco_CH4_problem_17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> //required for cout
#include <iomanip> //required for setw()

//Initialization of the global constant PI
const double PI = 3.141593;


//Gino LaGuardia-LoBianco, Chapter 4, Problem # 17. 
//This program generates a table displaying the conversion from radians to degrees.


int main()
{
	using namespace std;

	// declare and initialize objects
	double degrees(0);
	double radians(0);

	// Set formats.
	cout.setf(ios::fixed);
	cout.precision(6);

	//print radians and degrees in a loop.
	std::cout << "Radians to Degrees \n";
	while (radians <= 2*PI)
	{
		radians = degrees*PI / 180;
		std::cout << setw(20) << radians << setw(20) << degrees << std::endl;
		degrees += 18;
	}

	return 0;
}














