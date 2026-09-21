/* DOCUMENTATION
* Name: Layne Woodruff
* Due Date: March 2nd, 2023
* Description of purpose of memberList.h:
*/

#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "memberNode.h"
using namespace std;




/* Create a list class called memberList that will maintain a linked list of members. 

AddOneMember	Parameter: (memberNode* currNode),  to be added to the front of the list.

RemoveOneMember	Parameter: (int id), removes the member from the list if found and display a message that xxxx member was removed. Otherwise it will display a message “xx is not a member” Replace xx with the id.

PrintMemberList	no parameter, displays all of the data about each member in tabular form.
			(hint: use getter functions)

PrintPolicy	Parameter: (string policy), displays a list of members with the given policy. (hint: use getter functions)

PrintYear	Parameter: (int year), displays a list of members of have been with the company for equal to or more than the given year. (hint: use getter functions)

PrintLowPremium	Parameter: (none), display the member with the lowest premium. (hint: use getter functions)

*/

class memberList{
public:
	memberList();

	memberList(memberList& rhs);
	~memberList();

	memberList& operator=(memberList& rhs);
	
	void PushBack(memberNode* currNode);

//Adds one member based on the location passed
	void AddOneMember(memberNode* currNode);

//Removes one member
	void RemoveOneMember(int id);

//PrintMemberList
	void PrintMemberList();

//Prints customers based on policy
	void PrintPoicy(string policy);

//Prints customers based on years with insurance
	void PrintYear(int year);

//Prints the customer with the lowest premium
	void PrintLowPremium();

private:
	memberNode* head = nullptr; //Pointer to first node in List
	memberNode* tail = nullptr; // Pointer to last node in the list
};
