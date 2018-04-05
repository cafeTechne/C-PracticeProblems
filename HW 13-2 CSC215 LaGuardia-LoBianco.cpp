// HW 13-2 CSC215 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>

using namespace std;

class NumberArray
{
private:
	float arr[5];
public:
	NumberArray(){} //default constructor
	NumberArray(int z) //constructor takes an int, dynamically allocates an array of that size
	{
		float* floatpointer = nullptr;
		floatpointer = &arr[5];
		floatpointer = new float[z];

	}


	void storeNumber(int k, float n) //store a number in any element of the array
	{
		arr[k] = n;
	}
	float getNumber(int k) //retrieve a number from any element of the array
	{
		float y = arr[k];
		return y;
	}
	float getLowestNumber(int num) //return the lowest value stored in the array	
	{
		float a=500.0, b=500.0, c=500.0;
	
		for (int i = 0; i<num; i++)
		{
			if (arr[i] < a)
			{
				a = arr[i];
			}
		}
		return a;
	}
	float getHighestNumber(int num) //return the highest value stored in the array
	{
		float a = 0, b = 0, c = 0;
		
		for (int i = 0; i<num; i++)
		{
			if (arr[i] > a) (b = arr[i]);
		}
		return b;
	}
	float averageNumbers(int num) //averages based on the input of how many elements there are
	{
		float a = 0, b = 0;
		float d = 0;
		int c = num;
		d = float(c);

		for (int i = 0; i < (num); i++)
		{
			b = b + arr[i];
			
		}
		return (b/d);
	}

	//destructor should free memory held by the array
	//can't get the destructor working without an error about
	//deleting the wrong array. Why don't we use unique_ptr and shared_ptr again?
/*
	~NumberArray()
	{
		delete [] floatpointer;
	}
	*/
};

int main()
{
	//demonstrate the class in a program:
	int num = 0;
	int a = 0, c = 0, d = 0;
	float b = 0;

	cout << "How many elements would you like to import into the array?" << endl;
	cin >> num;

	cout << "How big should the array be?" << endl;
	cin >> a;
	
	if (num > a) 
	
	{ 
		cout << "The array needs to be atleast as big as the number of things you are storing in there! Try again" << endl;
		cout << "How big should the array be?" << endl;
		cin >> a;
		if (num > a)

		{
			cout << "Failed again. Terminating." << endl;
			exit(1);
		}

	}

	NumberArray noIdea(a);

	for (int i = 0; i < num; i++)
	{
	cout << "What number should we arbitrarily store in this array?" << endl;
	cin >> b;
	cout << "What element of this array should we arbitrarily store this number in?" << endl;
	cin >> c;

	noIdea.storeNumber(c, b);
	
	cout << "What element do you want to arbitrarily access?" << endl;
	cin >> d;
	cout << "The value of the element you arbitrarily accessed was: " << noIdea.getNumber(d) << endl;
	}


	cout << "This is the lowest number: " << noIdea.getLowestNumber(num);
	cout << "This is the highest number: " << noIdea.getHighestNumber(num);
	cout << "The average is : " << noIdea.averageNumbers(num);
	
	int test;
	cout << "test" << endl;
	cin >> test;

	//noIdea.~NumberArray; // i give up on this... why is this destructor not working?

    return 0;
}

