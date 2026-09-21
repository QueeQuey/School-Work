//****************************************************
// Class: IntNode.h (Class Declaration File)         *
// This class maintains a node object that can be    *
// used to create a linked list.		             *
//****************************************************
#ifndef INTNODE_H
#define INTNODE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class IntNode {
public:
	IntNode(int dataInit = 0, IntNode * nextLoc = nullptr);
	~IntNode();								//Destructor to deallocate memory
	
	int GetDataVal();

	IntNode* GetNext();
	void SetNext(IntNode* nextNodeLoc);		//Allows the client to change where the node points
	
	void PrintNodeData();
private:
	int dataVal;
	IntNode* nextNodePtr;  // pointer to the next node
};
#endif

