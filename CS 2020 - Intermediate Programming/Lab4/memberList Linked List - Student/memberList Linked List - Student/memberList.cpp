//****************************************************
// Class: memberList.cpp (Implementation File)       *
// This class maintains a list of objects.           *
//****************************************************
/* DOCUMENTATION
* Name: Layne Woodruff
* Due Date: March 2nd, 2023
* Description of purpose of memberList.cpp:
*/
#pragma once
#include "memberNode.h"
#include "memberList.h"
#include<fstream>
#include<string>
#include <iomanip>
#include <iostream>
using namespace std;

//****************************************************
// Function: memberList  (Constructor)               *
// This function set the head and tail to nullptr    *
//****************************************************
memberList::memberList(){
	head = nullptr;
	tail = nullptr;
}

//****************************************************
// Function: ~memberList  (Destructor)               *
// This function destroys the entire list somewhat   *
// recusively?										 *
//****************************************************
memberList::~memberList(){
	if (head) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	tail = nullptr;
}
//****************************************************
// Function: operator=                               *
// This is an overloaded assignment function. It is  *
// needed when the object had dynamic memory		 *
// allocated										 *
//****************************************************
memberList& memberList::operator=(memberList& rhs){
	memberNode* currNode = rhs.head;                // Copy List
	if (head != rhs.head){
		if (head){
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		//Might need to change the get to .getID etc
		while (currNode != nullptr) {
			PushBack(new memberNode(currNode->getID(), currNode->getName(), currNode->getPolicy(), currNode->getYear(), currNode->getPremium()));
			currNode = currNode->GetNext();					//Traversal Statement
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

	while(currNode != nullptr) {
		PushBack(new memberNode(currNode->getID(), currNode->getName(), currNode->getPolicy(), currNode->getYear(), currNode->getPremium()));
		currNode = currNode->GetNext();					//Traversal Statement
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
		tail->SetNext(currNode);
		tail = currNode;
	}
}





//Prints the entire list of customers
//Not sure why it uses rhs, need to check with TAs
void memberList::PrintMemberList() {
	memberNode* currNode = head;
	currNode->PrintHeader();
	while (currNode != nullptr) {
		currNode->Print(); // Basic Print function
		currNode = currNode->GetNext();
	}
}


//ADDS to "FRONT" of list which is where the HEAD is, NOT the tail.
void memberList::AddOneMember(memberNode* currNode) {
	//Node is passed in, previous node points to the new node, new node point to the following node
	if (!head) {
		head = tail = currNode; //Taken from IMQ
	}
	else {
		currNode->SetNext(head);
		head = currNode;
	}
}

//RemoveOneMember
void memberList::RemoveOneMember(int inId) {
	memberNode* currNode = head;
	memberNode* previousNode = nullptr;
	int i = 0;
	//If the ID is held by the head node
	if (head->getID() == inId) {
		currNode = head;
		if (head == tail) {
			tail = nullptr;
		}
		head = head->GetNext();
		delete currNode;
		i++;
	}

	//If the member ID matches, remove it, then patch the linked list
	//itterate through while loop of IDs
	while(currNode->getID() != inId && currNode){
		if(currNode->getID() == inId) {
			previousNode->SetNext(currNode->GetNext());
			if (currNode == tail){
				tail = previousNode;
			}
			currNode->SetNext(nullptr);
			delete currNode;
			i++;
		}
	}
	if (i == 0) {
		cout << inID << " is not a member." << endl;
	}
	cout << inId << " member removed" << endl;

}


//PrintPolicy - Other Print (insert) are based off of this
// It creates an int i to see if any customers are printed, and if not, then it outputs a sorryu
//It itterates through the linkedlist to see if the Policies match and prints that customer if they do.
void memberList::PrintPoicy(string inPolicy) {
	int i = 0;
	memberNode* currNode = head;
	cout << "             All "<< inPolicy << " members" << endl;
	
	currNode->PrintHeader();
	//currNode = head;

	while (currNode != nullptr) {
		if (currNode->getPolicy() == inPolicy) {
			currNode->Print();
			}
		currNode = currNode->GetNext();
		i = i+1; //Itterating i to see if the "no members" needs to be output
	}
	if(i==0){
		cout << "Sorry, no " << inPolicy << " members" << endl;
	}
	}


//PrintYear
void memberList::PrintYear(int inYear) {
	int i = 0;
	memberNode* currNode = head;
	cout << "             Members of at least: " << inYear << " years" << endl;
	currNode->PrintHeader();
	while (currNode != nullptr) {
		if (currNode->getYear() >= inYear) {
			currNode->Print();
		}
		currNode = currNode->GetNext();
		i = i + 1;
	}
	if (i == 0) {
		cout << "Sorry, no member with " << inYear << " or more years" << endl;
	}
}

//PrintLowPremium
void memberList::PrintLowPremium() {
	memberNode* currNode = head;
	memberNode* lowPrem = head;
	//memberNode* lowPrem = new memberNode(memberNode(0, "name", "policy", 9999, 9999)); - Realized I didn't need this

	currNode->PrintHeader();
	while (currNode != nullptr) {
		if (currNode->getPremium() < lowPrem->getPremium()) {
			lowPrem = currNode;
		}
		currNode = currNode->GetNext();
	}
	cout << lowPrem->getName() << " has the lowest premium of " << lowPrem->getPremium() << " dollars." << endl;
}
