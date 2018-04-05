// HW 13-1 CSC215 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>

using namespace std;

//Challenge: write a member class that has the following member variables:

//radius: a double
//pi: a double initialized with a value of 3.14159

class Circle 
{
private:
	double radius = 0;
	const double PI = 3.14159;

public: 
	Circle() //defualt constructor that sets radius to 0
	{
		double radius = 0;
	}

	
	Circle(double r)
	{
		radius = r;
	}//constructor accepts the radius of the circle as an argument


	void setRadius(double r)
	{
		radius = r;
	}  //setRadius a setter


	void getRadius(double r) { radius = r; }  //getRadius a getter (an accessor) function for the radius variable
	

	double getArea() 
	{
		double area = PI * radius * radius;
		return area;
	}

	double getCircumference()
	{
		double circumference = double(2) * PI * radius;
		return circumference;
	}

	double getDiameter()
	{
		double diameter = double(2) * radius;
		return diameter;
	}

};

int main()
{
	//write a program that demonstrates the circle class by asking 
	//the user for the circle's radius, 
	double r;

	cout << "User what is the circle's radius?" << endl;
	cin >> r;

	Circle c(r);

	//creating a Circle object, 

	//and then reporting the circle's area, diameter, and circumference

	cout << "Area is: " << c.getArea() << endl;
	cout << "Diameter is: " << c.getDiameter() << endl;
	cout << "Circumference is: " << c.getCircumference() << endl;


    return 0;
}

