//****************************************************
// Class: memberList.cpp (Implementation File)       *
// This class maintains a list of objects.           *
//****************************************************
#include "memberNode.h"
#include "memberList.h"

#include <iostream>
using namespace std;

//****************************************************
// Function: memberList  (Constructor)               *
// This function set the head and tail to nullptr    *
//****************************************************
memberList::memberList()
{

	head = nullptr;
	tail = nullptr;

}

//****************************************************
// Function: ~memberList  (Destructor)               *
// This function destroys the entire list somewhat   *
// recusively?										 *
//****************************************************
memberList::~memberList()
{
	if (head) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
}
//****************************************************
// Function: operator=                               *
// This is an overloaded assignment function. It is  *
// needed when the object had dynamic memory		 *
// allocated										 *
//****************************************************
memberList& memberList::operator=(memberList& rhs){
	memberNode* currNode = rhs.head;                // Copy List
	if (head != rhs.head)
	{
		if (head){
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		while (currNode != nullptr) {

			PushBack(new memberNode(/*add your getters __________, __________,
											__________, ___________,
											__________*/));
			currNode = currNode->getNext();					//Traversal Statement
		}													//Important to point to the next node
	}
	return *this;
}
//****************************************************
// Function: memberList(memberList& rhs)                   *
// This is an copy constructor function. It is       *
// needed when the object had dynamic memory		 *
// allocated										 *
//****************************************************
memberList::memberList(memberList& rhs){
	memberNode* currNode = rhs.head;                // Copy List

	while (currNode != nullptr) {
		PushBack(new memberNode(/*add your getters __________, __________,
											__________, ___________,
											__________*/));
		currNode = currNode->getNext();					//Traversal Statement
	}													//Important to point to the next node
}

//****************************************************
// Function: PushBack                                *
// Takes the node passed in and adds it to the end   *
// of the linked list. Accounts for an empty list.	 *
//****************************************************
void memberList::PushBack(memberNode* currNode) {
	if (!head) {
		head = tail = currNode;
	}
	else {
		tail->setNext(currNode);
		tail = currNode;
	}
}