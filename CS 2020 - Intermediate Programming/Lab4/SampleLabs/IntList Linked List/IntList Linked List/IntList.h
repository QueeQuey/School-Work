//****************************************************
// Class: IntList.h  (Class Declaration File)        *
// This class maintains a linked list of integer     *
// nodes.                       		             *
//****************************************************
#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "IntNode.h"
using namespace std;

class IntList {
public:
	IntList() {}						//Default Constructor, No paramters for this class

										//RULE OF THREE!!!
	IntList(IntList& rhs);				//Copy Constructor, use during declaration
	~IntList();							//Destructor, dealocates all of the memory use in the lists
	IntList& operator=(IntList& rhs);	//Overloaded Assignment Operator

	int GetSize() { return size; }		//return the number of nodes in the list

	void PushBack(IntNode* nuNode); // adds a node to the end of the list
	void PushFront(IntNode* nuNode); // adds a node to the head of the list
	void DeleteNode(int dval);		//search the list and deletes the node with the
									// given integer.

	double GetListAvg();			//Calculates and returns the average of the integers
	IntNode* GetHiVal();			//Finds and returns a pointer to the node with the 
									//highest value.

	void PrintOddList();			//Prints the odd integers in the list.
	void PrintList();				//Prints all of the integers in the list.
private:
	IntNode* head = nullptr;	    //Pointer to the first node in the list
	IntNode* tail = nullptr;		//Pointer to the last node in the list
	int size = 0;					//Keeps track of the number of nodes in the list.
									//Could be useful?
};
#endif

