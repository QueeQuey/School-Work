//****************************************************
// Class: IntNode (Implementation File)                                    *
// This class maintains a node object that can be    *
// used to create a linked list.		             *
//****************************************************
#include <iostream>

using namespace std;

#include "IntNode.h"

//****************************************************
// Function: Constructor, used to initialize Object  *
//****************************************************
IntNode::IntNode(int dataInit, IntNode* nextLoc) {
	this->dataVal = dataInit;
	this->nextNodePtr = nextLoc;
}
//****************************************************
// Function: ~IntNode, is the destructor             *
// Used to deallocate the nodes in the list. It      *
// exhibits a kind of recursive behavior. By deleting*
// the nextNodePtr, it calls on the this function    *
// again until there are no more nodes to delete.    *
// The print statment is for tracing purposes and is *
// not needed.                                       *
//****************************************************
IntNode::~IntNode() {
	cout << dataVal << "Node Deleted." << endl;
	if (nextNodePtr != nullptr) {
		delete nextNodePtr;
		nextNodePtr = nullptr;
	}
}

//****************************************************
// Function: Print dataVal                           *
// Print the data value in the node                  *
//****************************************************
void IntNode::PrintNodeData() {
	cout << this->dataVal << endl;
}
//****************************************************
// Function: GetNext                                 *
// Grab location pointed by nextNodePtr              *
// this->nextNodePtr is optionall, it could be just  *
// return nextNodePtr; since it is the implicit      *
// object											 *
//****************************************************
IntNode* IntNode::GetNext() {
	return this->nextNodePtr;
}
//****************************************************
// Function: SetNext                                 *
// Points the implied node to the location of the    *
// node passed to the function   		             *
//****************************************************
void IntNode::SetNext(IntNode* nextNodeLoc){
	nextNodePtr = nextNodeLoc;
}
//****************************************************
// Function: GetDataVal                              *
// Returns the data valuse                           *
// this->dataVal is optionall, it could be just      *
// return dataVal; since it is the implicit          *
// object											 *
//****************************************************
int IntNode::GetDataVal() {
	return this->dataVal;
}