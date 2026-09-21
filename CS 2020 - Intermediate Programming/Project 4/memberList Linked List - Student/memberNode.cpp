/* DOCUMENTATION
* Name: Layne Woodruff
* Due Date: March 2nd, 2023
* Description of purpose of memberNode.cpp:
This defines the functions created by the memberNode.h file for the memberNode object
*/
#include "memberNode.h"
#include<fstream>
#include<string>
#include <iomanip>
#include <iostream>
using namespace std;


//Destructor - syntax comes from ZyBooks
memberNode::~memberNode() {
	if (nextNodeRef != nullptr) {
		delete nextNodeRef;
	}
	nextNodeRef = nullptr;
}

//Getters and setters
int memberNode::getID() {
	return id;
}
void memberNode::setID(int id) {
	this->id = id;
}
string memberNode::getName() {
	return name;
}
void memberNode::setName(string name) {
	this->name = name;
}
string memberNode::getPolicy() {
	return policy;
}
void memberNode::setPolicy(string policy) {
	this->policy = policy;
}
int memberNode::getYear() {
	return year;
}
void memberNode::setYear(int year) {
	this->year = year;
}
int memberNode::getPremium() {
	return premium;
}
void memberNode::setPremium(int premium) {
	this->premium = premium;
}

void memberNode::SetNext(memberNode* nextNode) {
	nextNodeRef = nextNode;
}


//Location of the next node
memberNode* memberNode::GetNext(){
	return this->nextNodeRef;
}

void memberNode::Print() {
	cout << setfill(' ') << setw(4)  << id;
	cout << setw(25) << this->name;
	cout << setw(15) << this->policy;
	cout << setw(15) << this->premium;
	cout << setw(3) << this->year;
	cout << endl;
}

void memberNode::PrintHeader() {
	cout << "===============================================================================" << endl;
	cout << "Id   Name                     policy         premium        years" << endl;
	cout << "--   ----                     ------         -------        -----" << endl;
}


