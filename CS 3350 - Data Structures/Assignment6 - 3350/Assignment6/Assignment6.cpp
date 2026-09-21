//Layne Woodruff CS3350
#include <iostream>
#include <vector>
using namespace std;
//The ZyLabs talked about priority_queue, and I think that'd be better here, but I dont know if it
    //isn't allowed for this assignment. So I used the provided Heapify function but didn't use percolate down.


//Create a minimum heap, if the element passed in is larger than the root, add it to heap then heapify
int findKthLargest(vector<int> const& ints, int k){
    vector<int> heap;

    //Get the first k elements and put into heap
    for (int i = 0; i < k; i++) {
        heap.push_back(ints[i]);
    }
    buildMinHeap(heap);

    // Process the remaining elements
    for (int i = k; i < ints.size(); i++) {
        if (ints[i] > heap[0]) {
            heap[0] = ints[i]; // Replace the root with the larger element
            heapify(heap, 0, k); // Re-heapify the root
        }
    }

    // The root of the heap is the kth largest element
    return heap[0];
}

int main()
{
    vector<int> ints = { 7, 4, 6, 3, 9, 1 };
    int k = 3;

    cout << "k'th largest array element is " << findKthLargest(ints, k);

    return 0;
}