// HW 15-1 CSC215 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Employee
{
protected:
	string employeeName;
	int employeeNumber;
	int hireDate; //DAYmonthYEAR == xxyyzzzz
	
public:
	Employee(){ employeeName = ""; hireDate = 11223333; employeeNumber = 0; };
	Employee(string s, int e, int h) { employeeName = s; employeeNumber = e; hireDate = h; };

	void setEmployeeName(string s) { employeeName = s; };
	string getEmployeeName() { return employeeName; };
	
	void setEmployeeNumber(int e) { employeeNumber = e; };
	int getEmployeeNumber() { return employeeNumber; };

	void setHireDate(int h) { hireDate = h; };
	int getHireDate() { return hireDate; };
};

class ProductionWorker : public Employee
{
protected:
	int shift; //2 shifts: shift variable will hold an integer
				//value representing the shift that the employee works
				//day ==1 , night ==2. 
	double hourlyPayRate;

public:
	ProductionWorker() { shift = 1; hourlyPayRate = 15; };
	ProductionWorker(int s, double p) { shift = s; hourlyPayRate = p; };
	
	int getShift() { return shift; }
	void setShift(int n) { shift = n; }

	double getHourlyPayRate() { return hourlyPayRate; }
	void setHourlyPayRate(double p) { hourlyPayRate = p; }

};


int main()
{
	ProductionWorker worker1(2, 20);
	ProductionWorker worker2(1, 55);
	string s;
	int n;
	int n2;
	int d;

	cout << "what is Production Worker 1's name?" << endl;
	cin >> s;
	worker1.setEmployeeName(s);

	cout << "what is Production Worker 2's name?" << endl;
	cin >> s;
	worker2.setEmployeeName(s);

	cout << "what is Production Worker 1's employee number?" << endl;
	cin >> n;
	worker1.setEmployeeNumber(n);

	cout << "what is Production Worker 2's employee number?" << endl;
	cin >> n2;
	worker2.setEmployeeNumber(n2);

	cout << "what is Production Worker 1's hire date?" << endl;
	cin >> d;
	worker1.setHireDate(d);

	cout << "what is Production Worker 2's hire date?" << endl;
	cin >> d;
	worker2.setHireDate(d);
	cout << "Production Worker 1: " << endl;
	cout << "Employee name: " << worker1.getEmployeeName() << endl <<
		"Employee number: " << worker1.getEmployeeNumber() << endl <<
		"Employee Hire Date: " << worker1.getHireDate() << endl <<
		"Employee Shift: " << worker1.getShift() << endl <<
		"Employee Hourly Pay Rate: " << worker1.getHourlyPayRate() << endl;

	cout << "Production Worker 2: " << endl;
	cout << "Employee name: " << worker2.getEmployeeName() << endl <<
		"Employee number: " << worker2.getEmployeeNumber() << endl <<
		"Employee Hire Date: " << worker2.getHireDate() << endl <<
		"Employee Shift: " << worker2.getShift() << endl <<
		"Employee Hourly Pay Rate: " << worker2.getHourlyPayRate() << endl;

    return 0;
}


