#pragma once

/* DOCUMENTATION
* Name: Layne Woodruff
* Due Date: March 2nd, 2023
* Description of purpose of memberNode.h:
* Header file of the memberNode class, which is the class of obbject that is stored within the memberList.
* This file creates the class of memberNode, which are then placed into a list in the memberList class.
* The memberNode stores the information of individual clients.
*/
class memberNode {
private:
	int id;
	string name;
	string policy;
	int year;
	int premium;
	memberNode* nextNodeRef;

public:
	//Constructor no arguments
	memberNode() {
		id = 0;
		name = "null";
		policy = "null";
		year = 0;
		premium = 0;
		nextNodeRef = nullptr;
	}
	//Constructor all element arguments EXCEPT for pointer
	memberNode(int id, string name, string policy, int year, int premium) {
		this->id = id;
		this->name = name;
		this->policy = policy;
		this->year = year;
		this->premium = premium;
		nextNodeRef = nullptr;
	}
	//Constructor for ALL elements including the pointer to the next node
	memberNode(int id, string name, string policy, int year, int premium, memberNode* nextNodeReference) {
		this->id = id;
		this->name = name;
		this->policy = policy;
		this->year = year;
		this->premium = premium;
		this->nextNodeRef = nextNodeRef;
	}

	//Destructor
	~memberNode();

	//Getters and setters
	int getID();
	void setID(int id);

	string getName();
	void setName(string name);

	string getPolicy();
	void setPolicy(string policy);

	int getYear();
	void setYear(int year);

	int getPremium();
	void setPremium(int premium);

	memberNode* GetNext();
	void SetNext(memberNode* nextNodeRef);
	//get Reference
	//setReference
	//memberNode* GetNext();
	//void setNext(memberNode* nextNodeRef);

	void Print();
	void PrintHeader();
};