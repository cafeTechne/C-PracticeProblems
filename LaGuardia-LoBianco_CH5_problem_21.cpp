// LaGuardia-LoBianco_CH5_problem_21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> //required for cerr
#include <fstream> //required for ifstream, ofstream
#include <string> // required for string

using namespace std;


//Gino LaGuardia-LoBianco, CH5, Problem 21
/*This program analyzes a text file with data, 
arranged in columns representing time,
altitude, velocity, and acceleration 
(in s, m , m/s, and m/s^2 respectively) 
and determines how many stages a rocket has! 
*/
int main()
{

	//Declare objects, instantiate input file	
	ifstream sensorInput("rocket2.txt");
	
	
	//iniatialize variables
	double time=0.0, altitude=0.0, velocityInitial=0.0, velocityFinal=0.0, acceleration=0.0;
	int stage=0;
	bool peakFlag(true);

	cout << "This program analyzes a text file with data, \n arranged in columns representing time, \n altitude, velocity, and acceleration \n (in s, m , m/s, and m/s^2 respectively) and \n determines how many stages a rocket has! \n \n" << endl;
	

	//error checking
	if (sensorInput.fail())
	{
		cerr << "Error opening input file \n";
		return(-1);
	}
	
		//formats input from scientific notation to doubles from the input file and assigns them to variables
		sensorInput >> std::scientific >> time >> altitude >> velocityFinal >> acceleration;

		//while loop sets a flag to determine if the slope is positive or negative and then increments
		// the variable stage each time it decreases from a peak
		 
		while (time >= 0 && !sensorInput.eof())
		{
			sensorInput >> std::scientific >> time >> altitude;
			velocityInitial = velocityFinal;
			sensorInput >> std::scientific >> velocityFinal >> acceleration;

			if (velocityInitial>velocityFinal && peakFlag==true)
			{ 
				peakFlag = false;
				stage++;
			}
			if (time == (double)-99){
				break;
			}
			if (velocityFinal>velocityInitial)
			{ 
				peakFlag = true;
			}
 			
			cout << " time = " << time << " altitude = " << altitude << " velocity = " << velocityFinal << " acceleration = " << acceleration << endl;
			cout << "Based on this data, the rocket had " << stage << " stages!" << endl;
		
		}
		sensorInput.close();
	
    return 0;
}











/*

// LaGuardia-LoBianco_CH5_problem_14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> //required for cerr
#include <fstream> //required for ifstream, ofstream


using namespace std;


//Gino LaGuardia-LoBianco, Chapter 5, Problem 14. 
//This program reads the text from a file, and generates a new file without commas.

int main()
{
	//Declare objects
	char character;
	ifstream fileWithComma;
	ofstream fileSansComma;

	//opens input file
	fileWithComma.open("dataIn.txt");

	//error checking
	if (fileWithComma.fail())
	{
		cout << "There was an error opening your file" << endl;
		return -1;
	}

	//opens outputfile
	fileSansComma.open("results.txt");

	//loops checking for end of file with the eof() function,
	//while reading character by character and printing it
	//to a new file if it is not a comma.
	while (!fileWithComma.eof())
	{
		fileWithComma.get(character);
		if (character != ',')
		{
			fileSansComma << character;
			cout << character;
		}
	}


}
*/


/*

#include "stdafx.h"
#include <iostream> //required for cerr
#include <fstream> //required for ifstream, ofstream
#include <string> // required for string

int main()
{
//Declare objects.
char character;
bool text_state(true);
string infile, outfile;
ifstream html;
ofstream htmltext;

//Prompt user for name of input file.
cout << "enter the name of the input file";
cin >> infile;

// Prompt user for name of output file.
cout << "enter the name of the output file";
cin >> outfile;

//open files
html.open(infile.c_str());
if (html.fail())
{
cerr << "Error opening input file \n";
exit(1);
}
htmltext.open(outfile.c_str());
//read first character from html file.
html.get(character);

while (!html.eof())
{
//check stat.
if (text_state)
{
if (character == '<') // Beginning of a tag.
text_state = false; //Change states.
else
htmltext << character;  //still text. write to the file.
}
else
{
//command state, no output required.
if (character == '>') //end of tag.
text_state = true; //change states.
}


//read next character from html file.
html.get(character);
}
html.close();
htmltext.close();
return 0;

}

*/


/*
int main()
{
//Define file streams for input and output.
ifstream fin("sensor.txt");
ofstream fout("checkedSensor.txt");

//Check for possible erros
if (fin.fail())
{
cerr << "could not open input file sensor.dat\n";
exit(1);
}
if (fout.fail())
{
cerr << "could not open output file checkedSensor.dat\n";
exit(1);
}

//All files are open.
double t, motion;
int count(0);
fin >> t >> motion;
while (!fin.eof())
{
++count;

//Write valid data to output file.
if (t >= 0 && motion >= 0)
{
fout << t << " " << motion << endl;
}
//Write invalid data to standard error output.
else
{
cerr << "Bad data encountered on line"
<< count << endl
<< t << " " << motion << endl;
}

//Input next data pair
fin >> t >> motion;
} //end while

//close all files.
fin.close();
fout.close();

return 0;
}

*/