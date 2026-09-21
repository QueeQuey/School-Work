//****************************************************
// Program: IntListClient.cpp						 *
// Client program to use the IntNode and IntList     *
// classes                                          *
//****************************************************
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "IntNode.h"
#include "IntList.h"

int main() {

	IntList MyListOfInt;
	int i;
	unsigned seed = time(0);   // Get system time
	srand(seed);			   // Seed the random number generator

	for (i = 0; i < 5; ++i)        // Append 20 rand nums
		MyListOfInt.PushBack(new IntNode(rand()));

	cout << "Original MyListOfInt\n";
	MyListOfInt.PrintList();

	IntList Copy2ListOfInt;

	//Calling the overloaded assignment operator
	cout << "Assigning Copy2ListOfInt to MyListOfInt\n";
	Copy2ListOfInt = MyListOfInt;
	cout << "Copy2ListOfInt created by overloaded assignment operator\n";
	Copy2ListOfInt.PrintList();
	cout << "---------------------------------------------------------\n";

	//Calling the overloaded assignment operator
	cout << "Assigning SAME Object, no copying takes place.\n";
	Copy2ListOfInt = Copy2ListOfInt;
	cout << "Same Copy2ListOfInt\n";
	Copy2ListOfInt.PrintList();
	cout << "---------------------------------------------------------\n";
	//Calling the overloaded assignment operator
	cout << "Added 1000 to MyListOfInt\n";
	MyListOfInt.PushBack(new IntNode(1000)); //ad one more node to MyListOfInt
	MyListOfInt.PrintList();
	cout << "---------------------------------------------------------\n";
	cout << "Assigning Object Copy2ListOfInt with the new MyListOfInt\n";
	cout << "Copy2ListOfInt must realease old list before the copy.\n";
	Copy2ListOfInt = MyListOfInt;
	cout << "---------------------------------------------------------\n";
	cout << "Copy2ListOfInt created with the new MyListOfInt\n";
	Copy2ListOfInt.PrintList();
	cout << "---------------------------------------------------------\n";
	cout << "Program ending and releasing memory\n";

	return 0;
}
