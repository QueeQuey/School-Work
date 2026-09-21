// Program #1 – Hurricane Program
// Programmer:  Layne Woodruff
// Class:  CS 2020, Spring 2023
// Due Date: Feb 5, 2023
// Purpose of program: Create a program that 
// will read data from a file called hurricanes.txt.  
// The data will consist of a city’s name, wind velocity 
//and amount of rain for the hurricanes that occurred in the United States.

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
//global constants
const int MAXCITIES = 50;
using namespace std;
// Prototype (ADD MISSING PROTOTYPES)
void fillvector(vector<string>& city, vector<int>& wind, vector<double>& rain, int& numcities);
void printvectors(vector<string>city, vector<int>wind, vector<double>rain, int numcities);


//A few more prototypes, note the return types
int Windiestcitypos(vector<string>city, vector<int>wind, int numcities);
double Averagewind(vector<string>city, vector<int>wind, int numcities);


int main()
{
// Declared variables and vectors


// call to the functions
	fillvector(city, wind, rain, numcities);
	printvectors(city, wind, rain, numcities);


// output averages and highest
	cout << "/* add variable */" << " is the windiest city at " << "/* add variable */" << " mph." << endl;
	cout << endl;
	cout << "The average wind is " << "/* add variable */" << endl;
	cout << "The average rain is " << "/* add variable */" << endl;


	system("Pause");
	return 0;
}
//************************************************************************************
//Function: fillvector
//Function to read and fill vectors. The file is opened and closed after filling vectors
//************************************************************************************

void fillvector(vector<string>&city, vector<int>&wind, vector<double>&rain, int& numcities)
{
	cout << left << fixed << setprecision(1);
	ifstream infile;
	string tempstr;
	numcities = 0;

	//Now we will open the file

	infile.open("hurricanes.txt");
	if (!infile)
	{
		cerr << "Error" << endl;
	}

	//We will now run a loop to get al of the data from the file and assign it to the proper vector
	while (!infile.eof() && numcities < MAXCITIES)
	{
		getline(infile, city.at(numcities));
		infile >> wind.at(numcities);
		infile >> rain.at(numcities);
		getline(infile, tempstr);
		numcities++;
	}
	infile.close();
}
//************************************************************************************
//Function: printvectors
//Function to print the vectors in tabular form
//************************************************************************************
void printvectors(vector<string>city, vector<int>wind, vector<double>rain, int numcities)
{
	cout << "The Data file consists of: " << endl;
	cout << setw(15) << "City" << setw(10) << "Wind" << setw(10) << " Rain" << endl;
	cout << setw(15) << "------" << setw(10) << "----" << setw(10) << "-----" << endl;

	for (int count = 0; count < numcities; count++)
	{
		cout << setw(15) << city.at(count) << setw(10);
		cout << wind.at(count) << setw(10);
		cout << rain.at(count) << endl;
		

	}
	cout << endl;
	cout << endl;
}

int Windiestcitypos(vector<string>city, vector<int>wind, int numcities)
{
	return 0;
}
double Averagewind(vector<string>city, vector<int>wind, int numcities)
{
	return 0;
}