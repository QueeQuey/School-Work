// random_numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include "number_data.h"
#include <vector>
using namespace std;



void fill_random_numbers (int arr [], const unsigned int SIZE)
{
	// Pre:  SIZE is no more than a million, arr has been declared to be
	//       an array of at least SIZE elements.
	// Post: The first SIZE elements of the array arr have been populated with
	//       random integers between 0 and one million.

	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = round(rand() / double(RAND_MAX) * 1000000);
	}
}

void fill_sorted_numbers (int asc [], int dsc [], const unsigned int SIZE)
{
	// Pre:  SIZE is no more than a million, and asc and dsc have been declared
	//       to be arrays of at least SIZE elements.
	// Post: The first SIZE elements of the array asc have been populated with
	//       integers between 0 and one million in ascending order, and dsc has
	//       the same numbers in descending order.

	int step = 1000000 / SIZE;

	for (int i = 0; i < SIZE; i++)
	{
		asc[i] = dsc [SIZE-1-i] = step*i;
	}
}

/*
Example for usage:
*/
const unsigned int SIZE = 8000;

int main()
{
	int numbers [SIZE];
	int increasing [SIZE];
	int decreasing [SIZE];

	fill_random_numbers (numbers, SIZE);
	fill_sorted_numbers (increasing, decreasing, SIZE);
	// NOW apply sorting algorithms to a copy of each array or copy of a slice of the array.



	//All sorting algorithms taken from previous classes (ex. 3350)
        //Bubble, Quick, and Merge needed some adjustments. But I was able to reference book/stack overflow.
    
    //Needed since quickSort calls itself recursively 
    int quickSortComparisons = 0;
    int mergeComparisons = 0;

    //Setting a temp array and duplicating array to be sorted by each
    vector<int> arr = { 5, 1, 4, 2, 8, 0, 2 };
    vector<int> bubbleArray = arr;
    vector<int> insertionArray = arr;
    vector<int> quickArray = arr;
    vector<int> heapArray = arr;
    vector<int> mergeArray = arr;

    //Printing unsorted array first
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    //Sorts
    int bubbleComparisons = optimizedBubbleSort(bubbleArray);
    int insertionComparisons = insertionSort(insertionArray);
    quickSort(quickArray, 0, quickArray.size() - 1, quickSortComparisons);
    int heapComparisons = heapSort(heapArray);
    threeWayMergeSort(mergeArray, 0, mergeArray.size() - 1, mergeComparisons);


    cout << endl << "Bubble Sort Array" << endl;
    for (int num : bubbleArray) {
        cout << num << " ";
    }
    cout << endl;

    cout << endl << "Insertion Sort Array" << endl;
    for (int num : insertionArray) {
        cout << num << " ";
    }
    cout << endl;

    cout << endl << "Quick Sort Array" << endl;
    for (int num : quickArray) {
        cout << num << " ";
    }
    cout << endl;

    cout << endl << "Heap Sort Array" << endl;
    for (int num : heapArray) {
        cout << num << " ";
    }
    cout << endl;

    cout << endl << "Three-Way Merge Sort Array" << endl;
    for (int num : mergeArray) {
        cout << num << " ";
    }
    cout << endl << endl;

    cout << "Number of Optimized Bubble Sort comparisons: " << bubbleComparisons << endl;
    cout << "Number of Insertion Sort comparisons: " << insertionComparisons << endl;
    cout << "Number of Quick Sort comparisons: " << quickSortComparisons << endl;
    cout << "Number of Heap Sort comparisons: " << heapComparisons << endl;
    cout << "Number of Three-Way Merge Sort comparisons: " << mergeComparisons << endl;
    return 0;
}