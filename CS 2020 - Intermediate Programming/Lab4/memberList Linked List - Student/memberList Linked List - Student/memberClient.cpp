//******************************************************
// Program: memberListClient.cpp				       *
// Client program to use the memberNode and memberList *
// classes                                             *
//******************************************************

/* DOCUMENTATION
* Name: Layne Woodruff
* Due Date: March 2nd, 2023
* Description of purpose of memberClient.cpp:
* This is the main file that manages and calls the classes of the customers.
* it takes input from a file, and gives options as to what the program should do,
* it then performs actions to the linkedlist based on the input.
*/
#include "memberNode.h"
#include "memberList.h"
#include <iostream>
#include<fstream>
#include<string>

using namespace std;

memberNode*CreatecurrNode();
ifstream infile;				//file variable declared globally
								//no need to pass as a parameter

int main() {

	infile.open("memberData.txt");		//open file for input

	memberList MyListOfmembers;			//memberList Object
	int yrs;
	int choice, Delid;					//input variables for processing the list
	string policy;
	memberNode* currNode;				//pointer to current node to be added to the list

	infile >> choice; // get a menu choice before entering the loop		

	while (choice != 7)					//loop until 7 is entered
	{
		if (choice == 1) {				//Add a newly created node to the front of the list
			currNode = CreatecurrNode();
			MyListOfmembers.AddOneMember(currNode);

		}
		else if (choice == 2) {			//Finds and deletes a node based on the integer entered
			infile >> Delid;
			MyListOfmembers.RemoveOneMember(Delid);
		}
		else if (choice == 3) {				  
			MyListOfmembers.PrintMemberList(); // Prints all members
		}
		else if (choice == 4) {
			infile.ignore(); // Skips new line character
			getline(infile, policy);
			MyListOfmembers.PrintPoicy(policy); //Prints the members with the selected policy
		}
		else if (choice == 5) {					
			infile >> yrs;
			MyListOfmembers.PrintYear(yrs); //Prints the members with the selected amount of years or more
		}
		else if (choice == 6) {
			MyListOfmembers.PrintLowPremium(); //Prints the customer with the lowest premium
		}
		infile >> choice;				// get a menu choice in the loop	
	}

	return 0;
}

//-----------------------------------------------------
// Function: CreatecurrNode
// Create a node with member data
// Returns a pointer to that current node
//-----------------------------------------------------
memberNode* CreatecurrNode()
{
	memberNode* currNode;		//local pointer for the dynamic node that will be created
	string custName;
	int custID;
	string custPolicy;
	int custYears;
	int custPremium;


	//input those variables to popluate your node.
	infile >> custID;
	infile.ignore();
	getline(infile, custName);
	getline(infile, custPolicy);
	infile >> custYears;
	infile >> custPremium;

	//add those variables as arguments to populate your node.
	memberNode* currNode = new memberNode(custID, custName, custPolicy, custYears, custPremium);

	return currNode;

}
