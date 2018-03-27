// LaGuardia-LoBianco_CH7_Problem_19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream> //needed for cout
#include <algorithm> 
#include <time.h> //needed to seed srand
#include <cmath> //needed for pow
#include <numeric> //needed for the accumulator function to add all of the numbers in a vector


/* Gino LaGuardia-LoBianco, Chapter 7, Problem 19. This program uses the rand_float function
to generate sequences of random floating-point values between 4 and 109. Then, it compares the computed 
mean and variance to the theoretical values computed. As the sample size of simulated trials increases, 
the computed values and theoeretical values should converge.
*/

using namespace std;
double rand_float(double a, double b);				//function prototypes
double avg(vector<double> &v);

int main()
{
	double a(4), b(10), b1(4), c, d, e, average(7), sum(0.0), standardDeviation(0.0), variance(0.0);
	static double mean(0);
	int n(0), i(0), j(0), k(0);
	static vector<double> v(n);
	static vector<double> v2(n);

	srand(time(NULL));  //seeds time function with clock data to randomize across trials
	cout << "How many simulation would you like to run?" << endl; //queries user for number of simulations to run!
	cin >> n;

	if (cin.fail()) //error check
	{
		cout << "Input was not valid!";
	}
	else
	{
	cout << "Theoretical Variance = 9" << endl;  
	cout << "Theoretical Mean = 7" << endl;      
	}
	while (i < n)            //builds first array
	{
		c = rand_float(4, 10);	
		v.push_back(c);
		++i;
	}
	cout << "Experimental Mean is: " << avg(v);             
	mean = avg(v);
	while (j < n)			//builds second array
	{
		d = rand_float(4, 10);
		e = pow((d - mean), 2);
		v2.push_back(e);
		++j;
	}
	sum = accumulate(v2.begin(), v2.end(), double(0));       //accumulator function courtesy of <numeric>... adds all the numbers in an array it is called on 
	standardDeviation = (sum / n);							 //I cast in the the 3rd argument of the function because 0 is of type int and i read on stack
	variance = pow(standardDeviation, 2);					 //exchange that it's one of the times it's actually really important to cast in main!
	cout << "Standard Deviation is: " << standardDeviation << endl << "Variance is : " << variance << endl;
	cout << "size of v2 is " << v2.size();
	return 0;
}


/*This function generates a random double value between a and b.*/

double rand_float(double a, double b)
{
	return ((double)rand()/RAND_MAX)*(b - a) + a;
}


//function for mean
double avg(vector<double> &v)
{
	double return_value = 0.0;
	int n = v.size();

	for (int i = 0; i < n; i++)
	{
		return_value += v[i];
	}
	return (return_value / n);
}