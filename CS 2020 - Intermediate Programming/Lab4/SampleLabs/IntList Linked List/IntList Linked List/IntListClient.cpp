//****************************************************
// Program: IntListClient.cpp						 *
// Client program to use the IntNode and IntList     *
// classes                                          *
//****************************************************
#include <iostream>
using namespace std;

#include "IntNode.h"
#include "IntList.h"
int menu();


int main() {

	IntList MyListOfInt;
	int choice, MyInt, DelInt, AvgInt;
	IntNode* HiNode;

	choice = menu(); // get a menu choice before entering the loop		

	while (choice != 8)
	{
		if (choice == 1) {				//Add a newly created node to the front of the list
			cout << "Enter an integer:";
			cin >> MyInt;
			MyListOfInt.PushFront(new IntNode(MyInt));
		}

		else if (choice == 2){			//Add a newly created node to the end of the list
			cout << "Enter an integer:";
			cin >> MyInt;
			MyListOfInt.PushBack(new IntNode(MyInt));
		}
		else if (choice == 3){			//Finds and deletes a node based on the integer entered
			cout << "Enter the integer to be deleted:";
			cin >> DelInt;
			MyListOfInt.DeleteNode(DelInt);
		}
		else if (choice == 4){				  //Average integer
			AvgInt = MyListOfInt.GetListAvg();
			cout << "The average value is:" << AvgInt << endl;
		}
		else if (choice == 5) {					//Highest integer, returns a pointer to that node
			HiNode = MyListOfInt.GetHiVal();
			cout << "The highest value is:";
			HiNode->PrintNodeData();
		}
		else if (choice == 6)
			MyListOfInt.PrintOddList();			//Prints Odd Integers
		else if (choice == 7)
			MyListOfInt.PrintList();			//Prints All Integers
		choice = menu();
	}
	cout << "The original MyListOfInt list\n";
	MyListOfInt.PrintList();

	return 0;
}

//-----------------------------------------------------
// Function: Menu
// Allows the user to enter a menu choice from 1-8.
// Uses a data validation loop to insure a valid choice
//-----------------------------------------------------

int menu(){
	int choice;

	// Display a menu.
	cout << "1. Add an integer to the front\n";
	cout << "2. Add an integer to the end\n";
	cout << "3. Delete an integer\n";
	cout << "4. Get List Avg\n";
	cout << "5. Get Largest integer Node\n";
	cout << "6. Print Odd integers\n";
	cout << "7. Print All integers\n";
	cout << "8. Exit the program\n\n";
	// Get the user's choice.
	cout << "Enter your choice: ";
	cin >> choice;


	while (choice < 1 || choice > 8){ // while choice is outside the range
		cout << "Invalid, Enter your choice: ";
		cin >> choice;
	}
	return choice;
}