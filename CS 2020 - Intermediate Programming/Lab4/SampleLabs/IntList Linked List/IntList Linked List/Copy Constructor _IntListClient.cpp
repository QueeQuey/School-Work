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
	MyListOfInt.PrintList();

	//Calling the copy constructor
	cout << "Declaring CopyListOfInt using MyListOfInt  \n";
	IntList CopyListOfInt = MyListOfInt;
	cout << "List created by calling the Copy Constructor\n";
	CopyListOfInt.PrintList();

	return 0;
}

