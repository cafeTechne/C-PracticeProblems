// HW 16-3 CSC215 LaGuardia-LoBianco.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>



using namespace std;


class BankAccount
{
protected:
	int accountNumber=0;
	string name = "";
	double total=0;

public:
	                            
	int checknumber = 0;
	double checkAmount = 0;

	typedef std::map<int, double> mapType;
	std::map<int, double> m;

	double depositAmount(double amount) 
	{
		double sum = 0;
		sum = total + amount;
		total = sum;
		return total;
	}

	double withdrawCheck(int num, double amount)
	{
		double sum = 0;
		sum = total - amount;
		total = sum;
		m.insert(std::pair<int, double>(num, amount));
		return total;
	}

	double totalChecks() 
	{
		mapType::iterator pos;
		double sum = 0;
		//returns the sum of all amounts in the checks written
		for (pos = m.begin(); pos !=m.end(); ++pos)
		{
			sum += pos->second;
		}
		return sum;
	}
	
	double findCheck(int n)
	{
		try{
		std::map<int, double>::iterator it;
		it = m.find(n);
		if (it != m.end())
			if (m.find(n)->second >= 0) return m.find(n)->second;
		return m.find(n)->second;
		}
		catch(int n){
			if (isnan(m.find(n)->second)) cout << "check doesn't exist" << endl;
		}

	}
	

	void bouncedCheck(int n) 
	{
		std::map<int, double>::iterator it;
		it = m.find(n);
		if (it != m.end())
			total = total + (m.find(n)->second);
			m.erase(it);
			cout << " bounced check number " << n << endl;
		//removes the check with that number from the map
		//of checks and adds the amount back to the bank account

	}

	double checkBalance()
	{
		if (total < 0)
		return total;
	}

};

int main()
{
	BankAccount a;
	cout << "Balance after Depositing: " << a.depositAmount(100) << endl;
	cout << "Balance after Depositing: " << a.depositAmount(200) << endl;
	cout << "Balance after Depositing: " << a.depositAmount(300) << endl;

	a.withdrawCheck(10, 100);
	if (a.checkBalance() < 0) a.bouncedCheck(10);
	a.withdrawCheck(11, 200);
	if (a.checkBalance() < 0) a.bouncedCheck(11);
	a.withdrawCheck(12, 300);
	if (a.checkBalance() < 0) a.bouncedCheck(12);
	a.withdrawCheck(13, 200);
	if (a.checkBalance() < 0) a.bouncedCheck(13);

	cout << " the total of all checks is: " << a.totalChecks() << endl;
	cout << " The amount check 10 was written for was: " << a.findCheck(10) << endl;
	
	cout << "find check 100: " << a.findCheck(100) << endl;
	cout << "find check 11: " << a.findCheck(11) << endl;

    return 0;
}

