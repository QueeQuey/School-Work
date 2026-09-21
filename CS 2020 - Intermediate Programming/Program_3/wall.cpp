#include "wall.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


//Sets the name and position of a wall object upon creation.
wall::wall(string sName, int sPosition){
	name = sName;
	position = 0;
}

//Functions for getters and setters:
int wall::getposition() {
	return position;
}

void wall::setposition(int sPosition) {
	position = sPosition;
}


string wall::getname() const {
	return name;
}
void wall::setname(string sName) {
	name = sName;
}

void wall::climb() {
	int climbNum;
	//Randomly generates number, modulo 3 sets to 0-2, + 1 makes it 1-3
	climbNum = (rand() % 3) + 1;
	
	/* Set climbnum to 2 for testing purposes.Commented out now due to testing being complete.
	* climbNum = 2;
	*/

	//If the player goes above the wall, sets the player to the top of the wall.
	position = position + climbNum;
	if (position > 20) {
		position = 20;
	}
}
void wall::drop() {
	int dropNum;
	//Randomly generates number, modulo 3 sets to 0-2, + 1 makes it 1-3
	dropNum = (rand() % 3) + 1;
	
	position = position - dropNum;
	//If the player drops below the floor, sets the player to the floor.
	if (position < 0) {
		position = 0;
	}
}
