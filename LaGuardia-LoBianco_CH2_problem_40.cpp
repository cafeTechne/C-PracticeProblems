// LaGuardia-LoBianco_CH2_problem_40.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>


using namespace std;

//These lines establish the constant values of the atomic weights of each of these organic elements
const double OXYGEN = 15.9994;
const double CARBON = 12.011;
const double NITROGEN = 14.00674;
const double SULFUR = 32.066;
const double HYDROGEN = 1.00794;


//Gino N. LaGuardia-LoBianco, 01775469, Chapter 2, Problem # 40
/*This program calculates the average weight of a molecule in an amino acid, the user defines how many of each molecule are in it and it computes an average*/

int main()
{

	//declarations

	
	double oxygenAtoms;
	double carbonAtoms;
	double nitrogenAtoms;
	double sulfurAtoms;
	double hydrogenAtoms;
	double answer(0.0);
	double answer1(0.0);

	//statements

	//These statements prompt the user to define the number of atoms in each molecule

	cout << " How many oxygen atoms does your amino acid have? ";
	cin >> oxygenAtoms;

	cout << " How many carbon atoms does your amino acid have? ";
	cin >> carbonAtoms;

	cout << " How many nitrogen atoms does your amino acid have? ";
	cin >> nitrogenAtoms;

	cout << " How many sulfur atoms does your amino acid have? ";
	cin >> sulfurAtoms;

	cout << " How many hydrogen atoms does your amino acid have? ";
	cin >> hydrogenAtoms;


	//answer1 is the denominator of the equation, it represents the total number of atoms
	/*answer is the formula that takes the molecular weights, multiplies them against the number of each atom, sums them, and then divides
	that sum by the total number of atoms*/

	answer1 = ((oxygenAtoms + (carbonAtoms + (nitrogenAtoms + (sulfurAtoms + (hydrogenAtoms))))));
	answer = ((((oxygenAtoms*OXYGEN) + ((carbonAtoms*CARBON) + ((nitrogenAtoms*NITROGEN) + ((sulfurAtoms*SULFUR) + (hydrogenAtoms*HYDROGEN))))))/answer1);

	cout << " The average weight of an atom in your compound is " << answer << " atomic mass units.                 ";



	return 0;
}