// HW 14-2 CSC215 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


class DivSales
{
private:
	double quarterlySalesData[4];
	static double totalCorporateSales;

public:
	//member function that takes four arguments, each sales for a quarter

	DivSales() {};
	~DivSales() {};


	void salesStorage(double q1, double q2, double q3, double q4)
	{
		quarterlySalesData[0] = q1;
		quarterlySalesData[1] = q2;
		quarterlySalesData[2] = q3;
		quarterlySalesData[3] = q4;
		totalCorporateSales = q1 + q2 + q3 + q4;
	}

	double returnValue(int n)
	{
		if (n < 3) { cout << "number must be less than 3"; return 0; };
		if (n > 0) { cout << "number must be greater than 0"; return 0; };

		return quarterlySalesData[n];
	}


	static double getTotalCorporateSales()
	{
		return totalCorporateSales;
	}
};

double DivSales::totalCorporateSales = 0;

int main()
{
	DivSales divSales[6];
	double q1, q2, q3, q4;


	cout << "User, please enter the sales for four quarters for each division: " << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << "Division " << i + 1 << endl;
		cout << "enter values for quarter 1 sales: ";
		cin >> q1;
		//if (q1 <= 0) { cout << "only positive values allowed!";}
		cout << "enter values for quarter 2 sales: ";
		cin >> q2;
		//if (q2 <= 0) { cout << "only positive values allowed!";}
		cout << "enter values for quarter 3 sales: ";
		cin >> q3;
		//if (q3 <= 0) { cout << "only positive values allowed!";}
		cout << "enter values for quarter 4 sales: ";
		cin >> q4;
		//if (q4 <= 0) { cout << "only positive values allowed!";}
		divSales->salesStorage(q1, q2, q3, q4);
	}


	cout << "Division 1 " << endl;

	for (int j = 0; j < 4; j++)
	{
		cout << "q1 sales: " << divSales[0].returnValue(j) << endl;
		cout << "q2 sales: " << divSales[0].returnValue(j) << endl;
		cout << "q3 sales: " << divSales[0].returnValue(j) << endl;
		cout << "q4 sales: " << divSales[0].returnValue(j) << endl;
	}

	cout << "Division 2 " << endl;

	for (int j = 0; j < 4; j++)
	{
		cout << "q1 sales: " << divSales[1].returnValue(j) << endl;
		cout << "q2 sales: " << divSales[1].returnValue(j) << endl;
		cout << "q3 sales: " << divSales[1].returnValue(j) << endl;
		cout << "q4 sales: " << divSales[1].returnValue(j) << endl;
	}

	cout << "Division 3 " << endl;

	for (int j = 0; j < 4; j++)
	{
		cout << "q1 sales: " << divSales[2].returnValue(j) << endl;
		cout << "q2 sales: " << divSales[2].returnValue(j) << endl;
		cout << "q3 sales: " << divSales[2].returnValue(j) << endl;
		cout << "q4 sales: " << divSales[2].returnValue(j) << endl;
	}

	cout << "Division 4 " << endl;

	for (int j = 0; j < 4; j++)
	{
		cout << "q1 sales: " << divSales[3].returnValue(j) << endl;
		cout << "q2 sales: " << divSales[3].returnValue(j) << endl;
		cout << "q3 sales: " << divSales[3].returnValue(j) << endl;
		cout << "q4 sales: " << divSales[3].returnValue(j) << endl;


		cout << "Division 5 " << endl;

		for (int j = 0; j < 4; j++)
		{
			cout << "q1 sales: " << divSales[4].returnValue(j) << endl;
			cout << "q2 sales: " << divSales[4].returnValue(j) << endl;
			cout << "q3 sales: " << divSales[4].returnValue(j) << endl;
			cout << "q4 sales: " << divSales[4].returnValue(j) << endl;
		}

		cout << "Division 6 " << endl;

		for (int j = 0; j < 4; j++)
		{
			cout << "q1 sales: " << divSales[5].returnValue(j) << endl;
			cout << "q2 sales: " << divSales[5].returnValue(j) << endl;
			cout << "q3 sales: " << divSales[5].returnValue(j) << endl;
			cout << "q4 sales: " << divSales[5].returnValue(j) << endl;
		}


		cout << "Total corporate sales is : " << divSales[5].getTotalCorporateSales();

		return 0;
	}
}

