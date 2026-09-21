//Layne Woodruff - CS3350
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Data structure to store a binary tree node
struct Node{
    int data;
    Node* left, * right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};


// Function to check if a given binary tree is a min-heap or not
bool isMinHeap(Node* root){
    //If the root is a null pointer, it's nothing and is a min heap.
    if (root == nullptr) {
        return true;
    }
    //If the node has a left child, and that child is SMALLER than the parent node, return false.
    if (root->left && root->left->data < root->data) {
        return false;
    }
    //If the right child is smaller than the parent, return false.
    if (root->right && root->right->data < root->data) {
        return false;
    }
    //Return double boolean for the left and right child.
    return isMinHeap(root->left) && isMinHeap(root->right);
}

//Copy+Pasting my isComplete function from Assignment 5 since a Heap needs to be a complete Tree:
bool isComplete(Node* root) {
    //If first root is nullpointer, there are no nodes.
    if (root == nullptr) {
        return true;
    }


    //Stack is probably more appropriate here, but wasn't sure how to implement without importing other files.
    queue<Node*> treeQueue;
    treeQueue.push(root);

    //If there's a node to make the tree incompete. Initally set to false for the loop
    bool incompleteNode = false;

    while (!treeQueue.empty()) {
        Node* current = treeQueue.front();
        treeQueue.pop();

        //IF there is a left node, push it into the queue. BUT if there was a node that would make this node create
            //a incomplete stack, (ex double left) then return false.
        if (current->left) {
            if (incompleteNode) {
                return false;
            }
            treeQueue.push(current->left);
        }
        //Set to true because if a right node is found AFTER a left node is missing, can quickly return false.
        else {
            incompleteNode = true;
        }

        //If a right node is found, AND there was a left node, push. If there wasn't a left node, return false.
        if (current->right) {
            if (incompleteNode) {
                return false;
            }
            treeQueue.push(current->right);
        }

        //Set to true for the next level. IF THERE IS NOT a next level left node then it's all good and the whole thing returns
            //true. But if there's a double left then the first check in the left node will return false.
        else {
            incompleteNode = true;
        }
    }
    return true;
}

//Realized that the heap needs to be complete and changed the old isHeap function to isMinHeap, then
//  added this one to combine the booleans, since if one is false the whole thing is False.
bool isHeap(Node* root) {
    return isComplete(root) && isMinHeap(root);
}

int main()
{
    /* Construct the following tree
               2
             /   \
            /     \
           3       4
          / \     / \
         /   \   /   \
        5     6 8    10
    */

    Node* root = new Node(2);
    root->left = new Node(3);
    //root->left = new Node(7);
    root->right = new Node(4);
    root->left->left = new Node(5); //Would comment this out for testing if it would detect a incomplete tree.
    root->left->right = new Node(6);
    root->right->left = new Node(8);
    root->right->right = new Node(10);

    if (isHeap(root)) {
        cout << "The given binary tree is a min-heap";
    }
    else {
        cout << "The given binary tree is not a min-heap";
    }

    return 0;
}
