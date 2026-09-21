//Layne Woodruff, CS 3350, Assignment 5
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
//Added vector for rearraging the keys, algorithm since I didn't want to add another insertion sort, and queue for similar reasons
    //but to avoid having to implement stack.



// Data structure to store a binary tree node
struct Node
{
    int key;
    Node* left, * right;

    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};


//if you need any helper functions, write them here:

void collectKeys(Node* root, vector<int>& keys) {
    //End if the root is a null pointer
    if (root == nullptr) {
        return;
    }

    //Collect all the keys to the left then push, all the ones on the right then push.
        //recursive call so it will do subtrees before adding them together in the vector.
    //(Inorder search just like the given function)
    collectKeys(root->left, keys);
    keys.push_back(root->key);
    collectKeys(root->right, keys);
}


void assignKeys(Node* root, vector<int>& keys, int& index) {
    if (root == nullptr) {
        return;
    }

    //Just reassigns the keys grabbed in collectKeys through inorder traversal as defined by inorder().
    assignKeys(root->left, keys, index);
    //Sets the key to the next index of the vector. Call for assignKeys is recursive, so incrementing here is needed.
    root->key = keys[index++];
    //Right side after left to assign the large values after the small ones.
    assignKeys(root->right, keys, index);
}


//function to print every node's key using inorder traversal
void inorder(Node* root) {

    if (root==nullptr) {
        return;
    }
    else {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
        
}


//  function to calculate the height of a binary tree
int height(Node* root){
    //Tree is empty, or the root is a null pointer and something went wrong somewhere.
    if (root == nullptr) {
        return -1;
    }
    //Recursive call, adds one level for each time it continues down.
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    // Returns 1 (base node) + whichever height set is higher.
    if (leftHeight >= rightHeight) {
        return 1 + leftHeight;
    }
    else {
        return 1 + rightHeight;
    }

}



//  function to calculate the total number of nodes in a binary tree   
int size(Node* root){
    //If the root is a null pointer, there aren't any nodes
    if (root == nullptr) {
        return 0;
    }

    //Pretty much the same thing as height, except left and right are ADDED rather than taking the higher value.
    int total = 1 + size(root->left) + size(root->right);
    return total;
}


//  function to check if a given binary tree is a complete tree or not
bool isComplete(Node* root){
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
            if (incompleteNode){
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


//  function to convert the binary tree to a binary search tree, but maintaining its structure 
void convert_BST(Node* root) {
    //TODO 4: convert the binary tree to a binary search tree, but maintaining its structure 
    
    // Gets keys from the original tree (via inorder) and places into a vector to sort and reassign keys later.
    vector<int> keys;
    collectKeys(root, keys);

    // Using built-in sort function to sort the vector.
    sort(keys.begin(), keys.end());

    //Takes the sorted keys from the vector and reassigns nodes.
    int index = 0;
    assignKeys(root, keys, index);
}


int main()
{
    /* Construct the following tree
              1
            /   \               
           2     3
            \   / \
             5 6   7                      
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Printing all nodes with inorder traversal:" << endl;
    inorder(root);
    cout << endl;

    cout << "The size of the tree is " << size(root) <<endl;

    cout << "The height of the tree is " << height(root) << endl;

    if (isComplete(root)) {
        cout << "The tree is a complete binary tree" << endl;
    }
    else {
        cout << "The tree is not a complete binary tree" << endl;
    }

    convert_BST(root);

    cout << "Printing all nodes with inorder traversal after the conversion:" << endl;
    inorder(root);
    cout << endl;

    return 0;
}