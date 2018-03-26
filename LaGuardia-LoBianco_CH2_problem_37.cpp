// LaGuardia-LoBianco_CH2_problem_37.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

const double OXYGEN = 15.9994;
const double CARBON = 12.011;
const double NITROGEN = 14.00674;
const double SULFUR = 32.066;
const double HYDROGREN = 1.00794;

//Gino N. LaGuardia-LoBianco, 01775469, Chapter 2, Problem # 37

//This program calculates the molecular weight of glycine based on the weights of it's constituent elements.

int main()
{

	//declarations

	//declared and initialized the variable that will store the output of this program
	double glycine;

	//statements
	
	//algebraic equation multiplying the contant element weights against the number of each molecule in a molecule of glycine
	glycine = ((double(2) * OXYGEN) + ((double(2) * CARBON) + ((double(1) * NITROGEN) + (double(5) * HYDROGEN))));

	cout << " The Molecular weight of glycine is " << glycine << ".  ";
    return 0;
}

