// CW 13-3 CSC 215 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Employee
{

	string name;
	int id;
	string department;
	string title;
	static string classname[5];
	int counter;

	//constructor

	Employee::Employee(string name, int id, string department, string title)
	{	
	}
	
	//constructor that takes only the name and id, and assigns 
	// "" to department and title
	Employee::Employee(string name, int id)
	{
		department = "";
		title = "";
	}

	//a default constructer that assigns "" to name, department and title and 0 to id
	Employee::Employee()
	{
		name = "";
		department = "";
		title = "";
		id = 0;
	}

	//setters
	string* setClassSize(int size)
	{
		string *classNamePointer = nullptr;
		classNamePointer = new string [size];
		return classNamePointer;

	//when called will dynamically allocate an array for the class names with that size
		
	}
	
	void addClass(string a)
	{
		classname->append(a);
		counter++ ;
		if (counter >= 5) { cout << "array is full";}
		//adds class name to the array
		//should return true if successful and false if the array is already full
	}


	//write a destructor function. make sure to delete any dynamically allocated
	//memory that is part of the Employee class


	//write a main function that dynamically allocates 3 employees
	//for each employee, use a different constructor

	//getters
	~Employee() {};
};

int main()
{
	Employee *employeePointer = nullptr;
	
	//won't let me dynamically allocate without squigglies. I don't have 4+ hours
	//to spend on each classwork meeting your arbitrarily designed specifications
	//this is clearly 2 different problems combined. Why would an employee need an 
	//array of classnames? 
	
	//Trying to dynamically allocate as shown in the book fails in 
	// this example. Why? 

	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			Employee e1(string="gino", int=105, string="bh", string="nobody");
		}

		if (i == 1)
		{
			Employee e2(string = "gino", int = 105);
		}

		if (i == 2)
		{
			Employee e3();
		}
	}

    return 0;
}

