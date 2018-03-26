// LaGuardia-LoBianco_CH2_problem 39.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const double oxygen = 15.9994;
const double carbon = 12.011;
const double nitrogen = 14.00674;
const double sulfur = 32.066;
const double hydrogen = 1.00794;

int main()
{

	//declarations

	double glycine;
	double oxygenatoms;
	double carbonatoms;
	double nitrogenatoms;
	double sulfuratoms;
	double hydrogenatoms;
	double answer(0.0);
	//statements


	//glycine = ((double(2.0) * oxygen) + ((double(2.0) * carbon) + ((double(1.0) * nitrogen) + (double(5.0) * hydrogen))))

	cout << " How many oxygen atoms does your amino acid have? ";
	cin >> oxygenatoms;

	cout << " How many carbon atoms does your amino acid have? ";
	cin >> carbonatoms;

	cout << " How many nitrogen atoms does your amino acid have? ";
	cin >> nitrogenatoms;

	cout << " How many sulfur atoms does your amino acid have? ";
	cin >> sulfuratoms;

	cout << " How many hydrogen atoms does your amino acid have? ";
	cin >> hydrogenatoms;


	answer = ((oxygenatoms*oxygen) + ((carbonatoms*carbon) + ((nitrogenatoms*nitrogen) + ((sulfuratoms*sulfur) + (hydrogenatoms*hydrogen)))));

	cout << " Your amino acid weighs " << answer << " atomic mass units.                 ";



	return 0;
}