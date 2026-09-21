#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class wall
{
public:
	wall(string sName = "null", int sPosition = 0);
	//Getter and setters for position, name (even though setters are not needed), and climb and drop function.

	int getposition();
	void setposition(int sPosition);
	
	string getname() const;
	void setname(string sName);

	void climb();
	void drop();

private:
	string name;	//Player Name
	int position;	//Player position
};
