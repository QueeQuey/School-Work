//Layne Woodruff CS3350
#include <iostream>
#include <vector>
using namespace std;
//The ZyLabs talked about priority_queue, and I think that'd be better here, but I dont know if it
    //isn't allowed for this assignment. So I used the provided Heapify function but modified percolate down.

void heapify(vector<int>& heap, int i, int n){
    int smallest = i;    // Assume the local root node is the smallest at first
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    //Both check to see if the child is smaller than the size of the array, (crashes on run if you don't do this)
        //then check to see if the value is smaller than the root node. If it IS
        //then the root value and that value are swapped.
    if (left < n && heap[left] < heap[smallest]){
        smallest = left;
    }
    if (right < n && heap[right] < heap[smallest]){
        smallest = right;
    }

    // If the smallest is not the current node, swap and heapify recursively
    if (smallest != i){
        swap(heap[i], heap[smallest]);
        //Passes in the heap, the 
        heapify(heap, smallest, n);
    }
}

// Function to build a min-heap of size k
void buildMinHeap(vector<int>& heap){
    //Get the size of the heap then go through the array backwards to heapify. Similar to the Zylabs.
    int n = heap.size();
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(heap, i, n);
    }
}



// Function to find the k'th largest element in an array using min-heap
//Create a minimum heap, if the element passed in is larger than the root, add it to heap then heapify
int findKthLargest(vector<int> const& ints, int k){
    vector<int> heap;

    //Get the first k elements and put into heap (to start the Kth elements)
    for (int i = 0; i < k; i++){
        heap.push_back(ints[i]);
    }
    buildMinHeap(heap);

    // Process the remaining elementss
    for (int i = k; i < ints.size(); i++){
        if (ints[i] > heap[0]) {
            heap[0] = ints[i]; // Replace the root with the larger element
            heapify(heap, 0, k); // Re-heapify the root
        }
    }

    // The root of the heap is the kth largest element since only larger elements are added
    return heap[0];
}

int main()
{
    vector<int> ints = { 7, 4, 6, 3, 9, 1};
    //12 , 97 , 0 , 11, 222
    int k = 3;

    cout << "k'th largest array element is " << findKthLargest(ints, k);

    return 0;
}