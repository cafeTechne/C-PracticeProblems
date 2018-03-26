// GoogleGuessingGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <sstream>

using namespace std;

//https://stackoverflow.com/questions/18726102/what-difference-between-rand-and-random-functions
// I learned how to produce trully random numbers using the <random> library for this exercise!
//https://developers.google.com/edu/c++/getting-started <<== This is the exercise we're doing here! 
//******This Program Makes a Guessing Game that satisfies the criteria of the link directly above!

//void printRandom(random_device &e)            Commented out and kept because it
//{												is interesting and might be worth
//	for (int i=0; i < 10; i++)					looking at or showing others!
//		cout << e() << " ";
//	cout << endl;
//}

int main()
{
	//random_device //engine (non-deterministic URNG Uniform Random Number Generator)
	//can also use mt19937 or mt19937_64 which is mersenne twister engine seeded with 
	//constants from a "particular paper, per that article above"
	
	//uniform_int_distribution //uniform distribution can also 
	// use uniform_real_distribution

	int input;
	int wrongAnswerCounter = 0;
	bool answer = false;
	random_device e;
	random_device e2;
	uniform_int_distribution<int> distribution(0, 100);

	//printRandom(e);
	//printRandom(e2);
	cout << distribution(e);
	
	vector<int> v;
	v.push_back(distribution(e));
	int randomNumber = v[0];
	
	while (answer == false)
	{
		cout << "User, please guess an integer between 1 and 100!" << endl;
		cin >> input;

		if (cin.fail())
		{
			cout << "Incorrect input format! Integer please!" << endl;
			return(-1);
		}
		if (input < randomNumber)
		{
			cout << "Your guess was below the secret random number!" << endl;
			++wrongAnswerCounter;
		}
		if (input > randomNumber)
		{
			cout << "Your guess was above the secret random number!" << endl;
			++wrongAnswerCounter;
		}
		if (input == randomNumber)
		{
			cout << "Your guess is the secret random number!" << endl;
			++wrongAnswerCounter;
			answer = true;
		}
	}
	cout << " You guessed " << wrongAnswerCounter << " times!" << endl;
	return 0;
}

//std::default_random_engine generator;
//std::uniform_int_distribution<int> distribution(1, 6);
//int dice_roll = distribution(generator);  // generates number in the range 1..6

//For repeated uses, both can be bound together :
//auto dice = std::bind(distribution, generator);
//int wisdom = dice() + dice() + dice();

//shuffle() is considered awesome. 
//template <typename RanIt, typename URNG>
//void shuffle(RanIt f, RanIt l, URNG&& g);
//int a = rand() % 100
//return 0;
