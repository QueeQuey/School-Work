//****************************************************
// Class: IntList.cpp (Implementation File)                                    *
// This class maintains a node object that can be    *
// used to create a linked list.		             *
//****************************************************
#include "IntNode.h"
#include "IntList.h"

#include <iostream>
using namespace std;
//****************************************************
// Function: ~IntList  (Destructor)                  *
// This function destroys the entire list.           *
//****************************************************
IntList::~IntList()
{
	cout << "--------------------------\n";
	if (head) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	cout << "--------------------------\n";
}
//****************************************************
// Function: operator=                               *
// This is an overloaded assignment function. It is  *
// needed when the object had dynamic memory		 *
// allocated										 *
//****************************************************
IntList& IntList::operator=(IntList& rhs){
	IntNode* currObj = rhs.head;                // Copy List
	cout << "Overloaded assignment operator called\n";
	if (head != rhs.head)
	{
		if (head){
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		while (currObj != nullptr) {
			PushBack(new IntNode(currObj->GetDataVal()));
			currObj = currObj->GetNext();					//Traversal Statement
		}													//Important to point to the next node
	}
	return *this;
}
//****************************************************
// Function: IntList(IntList& rhs)                   *
// This is an copy constructor function. It is       *
// needed when the object had dynamic memory		 *
// allocated										 *
//****************************************************
IntList::IntList(IntList& rhs){
	IntNode* currObj = rhs.head;                // Copy List
	cout << "Copy Constructor called\n";

	while (currObj != nullptr) {
		PushBack(new IntNode(currObj->GetDataVal()));
		currObj = currObj->GetNext();					//Traversal Statement
	}													//Important to point to the next node
}

//****************************************************
// Function: PushBack                                *
// Takes the node passed in and adds it to the end   *
// of the linked list. Accounts for an empty list.	 *
//****************************************************
void IntList::PushBack(IntNode* nuNode){
	if (!head){
		head = tail = nuNode;
	}
	else{
		tail->SetNext(nuNode);
		tail = nuNode;
	}
	size++;
}
//****************************************************
// Function: PushFront                               *
// Takes the node passed in and adds it to the front *
// of the linked list. Accounts for an empty list.	 *
//****************************************************
void IntList::PushFront(IntNode* nuNode){
	if (!head){
		head = tail = nuNode;
	}
	else{
		nuNode->SetNext(head);
		head = nuNode;
	}
	size++;
}
//****************************************************
// Function: DeleteNode                              *
// Searches for and deletes a node based on the      *
// integer passed in.                	             *
//****************************************************
void IntList::DeleteNode(int dval){
	IntNode* currNode = nullptr;       // To traverse the list
	IntNode* prevNode = nullptr;  // To point to the previous node

	 //Scenario #1 Empty List
	// If the list is empty, do nothing.
	if (!head){
		cout << "The list is empty." << endl;
		return;
	}
	//Scenario #2 delete the head
	// Determine if the first node is the one.
	if (head->GetDataVal() == dval){
		currNode = head;
		if (head == tail)
			tail = nullptr;
		head = head->GetNext();
		currNode->SetNext(nullptr);
		delete currNode;
		size--;
		cout << dval << " has been removed." << endl;
	}
	else{
		//Scenario #3 Node is on the list elsewhere
		// Scenario #4  Node is not on the list
		// Initialize currNode to head of list
		currNode = head;

		// Skip all nodes whose value member is 
		// not equal to target until you reach the end
		while (currNode && currNode->GetDataVal() != dval){
			prevNode = currNode;
			currNode = currNode->GetNext();				//Traversal Statement
		}												//Important to point to the next node
		// If currNode is not at the end of the list, 
		// link the previous node to the node after
		// currNode, then delete currNode.
		if (currNode){
			prevNode->SetNext(currNode->GetNext());
			currNode->SetNext(nullptr);
			if (currNode == tail)
				tail = prevNode;
			delete currNode;
			size--;
			cout << dval << " has been removed." << endl;
		}
		else
			cout << dval << " was not on the list." << endl;
	}
}
//****************************************************
// Function: GetListAvg                              *
// Calculates and returns the average of the nodes   *
//****************************************************
double IntList::GetListAvg(){
	IntNode* currObj = head;                // Average the list
	int cnt = 0;
	double sum = 0;

	while (currObj != nullptr) {
		cnt++;
		sum += currObj->GetDataVal();
		currObj = currObj->GetNext();			//Traversal Statement
	}											//Important to point to the next node
	return sum / cnt;
}
//****************************************************
// Function: GetHiVal                                *
// Finds and returns the average of the nodes        *
//****************************************************
IntNode* IntList::GetHiVal(){
	IntNode* currObj = head;                // Find the highest value
	IntNode* hiObj = head;
	while (currObj != nullptr) {
		if (currObj->GetDataVal() > hiObj->GetDataVal())
			hiObj = currObj;
		currObj = currObj->GetNext();			//Traversal Statement
	}											//Important to point to the next node
	return hiObj;
}
//****************************************************
// Function: PrintOddList                            *
// Prints the odd numbers in the list by using the % *
//****************************************************
void IntList::PrintOddList(){
	IntNode* currObj = head;                // Average the list
	cout << "Odd values are:" << endl;
	cout << "---------------" << endl;

	while (currObj != nullptr) {
		if (currObj->GetDataVal() % 2)
			cout << currObj->GetDataVal() << endl;
		currObj = currObj->GetNext();				//Traversal Statement
	}												//Important to point to the next node
}
//****************************************************
// Function: PrintList                               *
// Prints all of the numbers in the list.            *
//****************************************************
void IntList::PrintList(){
	IntNode* currObj = head;

	cout << "The values are:" << endl;
	cout << "---------------" << endl;
	while (currObj != nullptr) {
		cout << currObj->GetDataVal() << endl;
		currObj = currObj->GetNext();			//Traversal Statement
	}											//Important to point to the next node
}