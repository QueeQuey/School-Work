//Layne Woodruff, CS4120, Project 1
#include <cstdlib>
#include "number_data.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;

int optimizedBubbleSort(vector<int>& arr);
int insertionSort(vector<int>& arr);
int heapify(vector<int>& arr, int n, int i, int& numComparisons);
int heapSort(vector<int>& arr);
void quickSort(vector<int>& arr, int low, int high, int& numComparisons);
void threeWayMergeSort(vector<int>& arr, int left, int right, int& mergeComparisons);
void fill_random_numbers(vector<int>& arr, const unsigned int SIZE);
void fill_sorted_numbers(vector<int>& asc, vector<int>& dsc, const unsigned int SIZE);

void calculateBubbleSort(vector<int> numbers, vector<int> increasing, vector<int> decreasing);
void calculateInsertionSort(vector<int> numbers, vector<int> increasing, vector<int> decreasing);
void calculateQuickSort(vector<int> numbers, vector<int> increasing, vector<int> decreasing);
void calculateHeapSort(vector<int> numbers, vector<int> increasing, vector<int> decreasing);
void calculate3MergeSort(vector<int> numbers, vector<int> increasing, vector<int> decreasing);

const unsigned int SIZE = 8000;

int main() {
    //All sorting algorithms taken from previous classes (ex. 3350)
        //Bubble, Quick, and Merge needed some adjustments. But I was able to reference book/stack overflow.
    
    //Needed since quickSort calls itself recursively 
    int quickSortComparisons = 0;
    int mergeComparisons = 0;

    vector<int> numbers;
    vector<int> increasing;
    vector<int> decreasing;

    ofstream randFile("randData.txt");
    ofstream incFile("increasingData.txt");
    ofstream decFile("decreasingData.txt");
    
    numbers.resize(SIZE);
    increasing.resize(SIZE);
    decreasing.resize(SIZE);
    cout << "Created vectors" << endl;

    fill_random_numbers(numbers, SIZE);
    cout << "filled random numbers" << endl;
    fill_sorted_numbers(increasing, decreasing, SIZE);
    cout << "filled the sorted numbers" << endl;


    //Triple if, for loops for output of data for Submission deliverable 1.
    if (randFile.is_open()) {
        for (size_t i = 0; i < numbers.size(); ++i) {
            randFile << numbers[i];
            if (i < numbers.size() - 1) {
                randFile << ",";
            }
        }
        randFile.close();
    }

    if (incFile.is_open()) {
        for (size_t i = 0; i < numbers.size(); ++i) {
            incFile << numbers[i];
            if (i < numbers.size() - 1) {
                incFile << ",";
            }
        }
        incFile.close();
    }

    if (decFile.is_open()) {
        for (size_t i = 0; i < numbers.size(); ++i) {
            decFile << numbers[i];
            if (i < numbers.size() - 1) {
                incFile << ",";
            }
        }
        decFile.close();
    }


    //Code for this is at the bottom, each is a copy of the calculateBubble sort, so you'll get the idea from just that.
    calculateBubbleSort(numbers, increasing, decreasing);
    calculateInsertionSort(numbers, increasing, decreasing);
    calculateQuickSort(numbers, increasing, decreasing);
    calculateHeapSort(numbers, increasing, decreasing);
    calculate3MergeSort(numbers, increasing, decreasing);
    
    return 0;
}


int optimizedBubbleSort(vector<int>& bubbleArray) {
    int numComparisons = 0;
    //Sets n as the bubbleArrayay size that way it can track the position
    int pos = bubbleArray.size();
    //While the bubbleArrayay has more than one element
    while (pos > 1) {
        // Initialized at first position, tracks last swapped
        int lastSwap = 0;
        //Starts at i = 1 instead of 0 due to backwards comparison.
        for (int i = 1; i < pos; ++i) {
            numComparisons++; //Itterating the number of comparions made before if loop as a comparison may be made, but the if isn't executed.
            if (bubbleArray[i - 1] > bubbleArray[i]) {
                swap(bubbleArray[i - 1], bubbleArray[i]);
                // If there's a swap, update the last swapped location.
                lastSwap = i;  
            }
        }
        // Cuts off the swap location that way it doesn't start at the beginning every time (like bubbleArrayay size - 1)
        pos = lastSwap;  
    }
    return numComparisons;
}

/////////////////
/////////////////
// INSERTION SORT//
/////////////////
/////////////////

int insertionSort(vector<int>& insertionArray) {
    int numComparisons = 0;
    int n = insertionArray.size();
    for (int i = 1; i < n; i++) {
        int needToInsert = insertionArray[i];
        //j starts at 0
        int j = i - 1; 

        // Move elements that are greater than key one position ahead
        //NOT double incremented since j is just an int.
        while (++numComparisons, j >= 0 && insertionArray[j] > needToInsert) {
            //++numComparisons; - Moved to inside the while loop as mentioned in Assignment
            insertionArray[j + 1] = insertionArray[j];
            j--;
        }
        insertionArray[j + 1] = needToInsert;
    }
    return numComparisons;
}

/////////////////
/////////////////
// HEAP SORT //
/////////////////
/////////////////

// Function to heapify a subtree rooted at index i
int heapify(vector<int>& arr, int n, int i, int& numComparisons) {

    int largest = i;      // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root / Node
    //No double increases since left and right are int locations, not elements
    if (++numComparisons, left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (++numComparisons, right < n && arr[right] > arr[largest]){
        largest = right;
    }

    // If largest is not root
    //No increment since largest is a val, not an element. Likewise with i.
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, numComparisons); // Recurse
    }

    return numComparisons;
}

// Heap Sort function
int heapSort(vector<int>& arr) {
    //Due to recursion, passing numComparisons by reference.
    //Don't need to do extra assignments
    int numComparisons = 0;
    int pos = arr.size();

    // Building a max heap
    for (int i = pos / 2 - 1; i >= 0; i--) {
        heapify(arr, pos, i, numComparisons);
    }

    // Extract elements from heap one by one
    for (int i = pos - 1; i > 0; i--) {
        //Moves current element (root) to end
        swap(arr[0], arr[i]);
        //Reheapifys the smaller heap
        heapify(arr, i, 0, numComparisons);
    }

    return numComparisons;
}

/////////////////
/////////////////
// QUICK SORT //
/////////////////
/////////////////

// Function to find the median of three and use it as pivot
int medianOfThree(vector<int>& arr, int low, int high, int& numComparisons) {
    //Midpoint of the array
    int mid = low + (high - low) / 2;

    // Swaps the three elements (low mid and high) to rearrange into correct order
    numComparisons++;
    if (arr[mid] < arr[low]){
        swap(arr[mid], arr[low]);
    }
    numComparisons++;
    if ( arr[high] < arr[low]){
        swap(arr[high], arr[low]);
    }
    numComparisons++;
    if (arr[high] < arr[mid]){
        swap(arr[high], arr[mid]);
    }

    // Use the median as pivot by swapping it to the end
    swap(arr[mid], arr[high]);
    return arr[high];
}


int partition(vector<int>& arr, int low, int high, int& numComparisons) {
    //Finding Pivot
    int pivot = medianOfThree(arr, low, high, numComparisons);
    int i = low - 1;

    for (int j = low; j < high; j++) {
        numComparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}



// QuickSort function
void quickSort(vector<int>& arr, int low, int high, int& numComparisons) {
    numComparisons++;
    if (low < high) {
        //If it isn't sorted yet
        int pivotIndex = partition(arr, low, high, numComparisons);
        //Recursively calls itself for both halves
        quickSort(arr, low, pivotIndex - 1, numComparisons);
        quickSort(arr, pivotIndex + 1, high, numComparisons);
    }
}

/////////////////
/////////////////
// MERGE SORT // 
/////////////////
/////////////////


void merge(vector<int>& arr, int left, int mid1, int mid2, int right, int& mergeComparisons) {
    //Size of the 3 subarrays
    int size1 = mid1 - left + 1;
    int size2 = mid2 - mid1;
    int size3 = right - mid2;

    // Temp arrays - this and following from W3Schools
    vector<int> leftArr(size1), midArr(size2), rightArr(size3);
    
    // Copying data to temporary arrays
    for (int i = 0; i < size1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < size2; i++) {
        midArr[i] = arr[mid1 + 1 + i];
    }
    for (int i = 0; i < size3; i++) {
        rightArr[i] = arr[mid2 + 1 + i];
    }


    // Merging the three arrays
    int i = 0, j = 0, k = 0, index = left;
    while (i < size1 || j < size2 || k < size3) {
        int minValue = INT_MAX, minIdx = -1;

        // Find the smallest among the three current elements
        //There is only one increment despite &&s since i, j, and k are only comparing an int val and not elements like the right side
            //of each of the if statements
        if (++mergeComparisons, i < size1 && leftArr[i] < minValue) {
            minValue = leftArr[i];
            minIdx = 0;
        }
        if (++mergeComparisons, j < size2 && midArr[j] < minValue) {
            minValue = midArr[j];
            minIdx = 1;
        }
        if (++mergeComparisons, k < size3 && rightArr[k] < minValue) {
            minValue = rightArr[k];
            minIdx = 2;
        }

        // Place the smallest element in the merged array
        //Not incrementing mergeComparisons here for the same reason as i,j, and k.
        if (minIdx == 0) {
            arr[index++] = leftArr[i++];
        }
        else if (minIdx == 1) {
            arr[index++] = midArr[j++];
        }
        else {
            arr[index++] = rightArr[k++];
        }
    }
}

// Function to perform Three-Way Merge Sort
void threeWayMergeSort(vector<int>& arr, int left, int right, int& mergeComparisons) {
    // Base case: If single element, return
    if (left >= right) {
        return;
    }

    // Divide the array into three parts
    int mid1 = left + (right - left) / 3;
    int mid2 = left + 2 * (right - left) / 3;

    // Recursively sort the three parts
    threeWayMergeSort(arr, left, mid1, mergeComparisons);
    threeWayMergeSort(arr, mid1 + 1, mid2, mergeComparisons);
    threeWayMergeSort(arr, mid2 + 1, right, mergeComparisons);

    // Merge the three sorted parts
    merge(arr, left, mid1, mid2, right, mergeComparisons);
}

/////////////////
/////////////////
// Included Functionality // 
/////////////////
/////////////////

void fill_random_numbers(vector<int>& arr, const unsigned int SIZE)
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

void fill_sorted_numbers(vector<int>& asc, vector<int>& dsc, const unsigned int SIZE)
{
    // Pre:  SIZE is no more than a million, and asc and dsc have been declared
    //       to be arrays of at least SIZE elements.
    // Post: The first SIZE elements of the array asc have been populated with
    //       integers between 0 and one million in ascending order, and dsc has
    //       the same numbers in descending order.

    int step = 1000000 / SIZE;

    for (int i = 0; i < SIZE; i++)
    {
        asc[i] = dsc[SIZE - 1 - i] = step * i;
    }
}

void calculateBubbleSort(vector<int> numbers, vector<int> increasing, vector<int> decreasing) {
    cout << endl << "BUBBLE SORT" << endl << endl;
    vector<int> numbersCopy = numbers;
    vector<int> increasingCopy = increasing;
    vector<int> decreasingCopy = decreasing;

    //Randomized Numbers
    //cout << "Commensing Bubble Sort..." << endl << endl;
    //cout << "Randomized Numbers, 8000 elements" << endl;
    auto start = chrono::high_resolution_clock::now();
    int bubbleNumComparisons = optimizedBubbleSort(numbersCopy);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> bubbleNumTime8 = end - start;

    //Increasing Numbers
    //cout << "Increasing numbers, 8000 elements" << endl;
    start = chrono::high_resolution_clock::now();
    int bubbleIncComparisons = optimizedBubbleSort(increasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> bubbleIncTime8 = end - start;

    //Decreasing Numbers
    //cout << "Decreasing numbers, 8000 elements" << endl;
    start = chrono::high_resolution_clock::now();
    int bubbleDecComparisons = optimizedBubbleSort(decreasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> bubbleDecTime8 = end - start;


    //cout << "Resetting vectors..." << endl;
    numbersCopy = numbers;
    increasingCopy = increasing;
    decreasingCopy = decreasing;
    //cout << "Decreasing Vector size to 4000" << endl;
    numbersCopy.resize(4000);
    increasingCopy.resize(4000);
    decreasingCopy.resize(4000);


    //Randomized Numbers
    //cout << "Commensing Bubble Sort..." << endl << endl;
    //cout << "Randomized Numbers, 4000 elements" << endl;
    start = chrono::high_resolution_clock::now();
    int bubbleNumComparisons4 = optimizedBubbleSort(numbersCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> bubbleNumTime4 = end - start;

    //Increasing Numbers
    //cout << "Increasing numbers, 4000 elements" << endl;
    start = chrono::high_resolution_clock::now();
    int bubbleIncComparisons4 = optimizedBubbleSort(increasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> bubbleIncTime4 = end - start;

    //Decreasing Numbers
    //cout << "Decreasing numbers, 4000 elements" << endl;
    start = chrono::high_resolution_clock::now();
    int bubbleDecComparisons4 = optimizedBubbleSort(decreasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> bubbleDecTime4 = end - start;

    //cout << "Resetting vectors..." << endl;
    numbersCopy = numbers;
    increasingCopy = increasing;
    decreasingCopy = decreasing;
    //cout << "Decreasing Vector size to 2000" << endl;
    numbersCopy.resize(2000);
    increasingCopy.resize(2000);
    decreasingCopy.resize(2000);


    //Randomized Numbers
    //cout << "Commensing Bubble Sort..." << endl << endl;
    //cout << "Randomized Numbers, 2000 elements" << endl;
    start = chrono::high_resolution_clock::now();
    int bubbleNumComparisons2 = optimizedBubbleSort(numbersCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> bubbleNumTime2 = end - start;

    //Increasing Numbers
    //cout << "Increasing numbers, 2000 elements" << endl;
    start = chrono::high_resolution_clock::now();
    int bubbleIncComparisons2 = optimizedBubbleSort(increasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> bubbleIncTime2 = end - start;

    //Decreasing Numbers
    //cout << "Decreasing numbers, 2000 elements" << endl;
    start = chrono::high_resolution_clock::now();
    int bubbleDecComparisons2 = optimizedBubbleSort(decreasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> bubbleDecTime2 = end - start;

    //cout << "Resetting vectors..." << endl;
    numbersCopy = numbers;
    increasingCopy = increasing;
    decreasingCopy = decreasing;
    //cout << "Decreasing Vector size to 1000" << endl;
    numbersCopy.resize(1000);
    increasingCopy.resize(1000);
    decreasingCopy.resize(1000);


    //Randomized Numbers
    //cout << "Commensing Bubble Sort..." << endl << endl;
    //cout << "Randomized Numbers, 1000 elements" << endl;
    start = chrono::high_resolution_clock::now();
    int bubbleNumComparisons1 = optimizedBubbleSort(numbersCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> bubbleNumTime1 = end - start;

    //Increasing Numbers
    //cout << "Increasing numbers, 1000 elements" << endl;
    start = chrono::high_resolution_clock::now();
    int bubbleIncComparisons1 = optimizedBubbleSort(increasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> bubbleIncTime1 = end - start;

    //Decreasing Numbers
    //cout << "Decreasing numbers, 1000 elements" << endl;
    start = chrono::high_resolution_clock::now();
    int bubbleDecComparisons1 = optimizedBubbleSort(decreasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> bubbleDecTime1 = end - start;


    //cout << "Number of Optimized Bubble Sort comparisons (8000 Random Elements): " << bubbleNumComparisons << endl;
    //cout << "Total time of Optimized Bubble Sort comparisons (8000 Random Elements): " << bubbleNumTime8.count() << " seconds" << endl;
    cout << "Comparisons (8000 Random Elements): " << bubbleNumComparisons << endl;
    cout << "Time (8000 Random Elements): " << bubbleNumTime8.count() << " seconds" << endl << endl;
    cout << "Comparisons (8000 Increasing Elements): " << bubbleIncComparisons << endl;
    cout << "Time (8000 Increasing Elements): " << bubbleIncTime8.count() << " seconds" << endl << endl;
    cout << "Comparisons (8000 Decreasing Elements): " << bubbleDecComparisons << endl;
    cout << "Time (8000 Decreasing Elements): " << bubbleDecTime8.count() << " seconds" << endl << endl;

    cout << "Comparisons (4000 Random Elements): " << bubbleNumComparisons4 << endl;
    cout << "Time (4000 Random Elements): " << bubbleNumTime4.count() << " seconds" << endl << endl;
    cout << "Comparisons (4000 Increasing Elements): " << bubbleIncComparisons4 << endl;
    cout << "Time (4000 Increasing Elements): " << bubbleIncTime4.count() << " seconds" << endl << endl;
    cout << "Comparisons (4000 Decreasing Elements): " << bubbleDecComparisons4 << endl;
    cout << "Time (4000 Decreasing Elements): " << bubbleDecTime4.count() << " seconds" << endl << endl;

    cout << "Comparisons (2000 Random Elements): " << bubbleNumComparisons2 << endl;
    cout << "Time (2000 Random Elements): " << bubbleNumTime2.count() << " seconds" << endl << endl;
    cout << "Comparisons (2000 Increasing Elements): " << bubbleIncComparisons2 << endl;
    cout << "Time (2000 Increasing Elements): " << bubbleIncTime2.count() << " seconds" << endl << endl;
    cout << "Comparisons (2000 Decreasing Elements): " << bubbleDecComparisons2 << endl;
    cout << "Time (2000 Decreasing Elements): " << bubbleDecTime2.count() << " seconds" << endl << endl;

    cout << "Comparisons (1000 Random Elements): " << bubbleNumComparisons1 << endl;
    cout << "Time (1000 Random Elements): " << bubbleNumTime1.count() << " seconds" << endl << endl;
    cout << "Comparisons (1000 Increasing Elements): " << bubbleIncComparisons1 << endl;
    cout << "Time (1000 Increasing Elements): " << bubbleIncTime1.count() << " seconds" << endl << endl;
    cout << "Comparisons (1000 Decreasing Elements): " << bubbleDecComparisons1 << endl;
    cout << "Time (1000 Decreasing Elements): " << bubbleDecTime1.count() << " seconds" << endl << endl;
}

void calculateInsertionSort(vector<int> numbers, vector<int> increasing, vector<int> decreasing) {
    cout << endl << "Insertion SORT" << endl << endl;
    vector<int> numbersCopy = numbers;
    vector<int> increasingCopy = increasing;
    vector<int> decreasingCopy = decreasing;

    //Randomized Numbers
    auto start = chrono::high_resolution_clock::now();
    int insertionNumComparisons = insertionSort(numbersCopy);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> insertionNumTime8 = end - start;

    //Increasing Numbers
    start = chrono::high_resolution_clock::now();
    int insertionIncComparisons = insertionSort(increasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> insertionIncTime8 = end - start;

    //Decreasing Numbers
    start = chrono::high_resolution_clock::now();
    int insertionDecComparisons = insertionSort(decreasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> insertionDecTime8 = end - start;


    //cout << "Resetting vectors..." << endl;
    numbersCopy = numbers;
    increasingCopy = increasing;
    decreasingCopy = decreasing;
    //cout << "Decreasing Vector size to 4000" << endl;
    numbersCopy.resize(4000);
    increasingCopy.resize(4000);
    decreasingCopy.resize(4000);


    //Randomized Numbers
    start = chrono::high_resolution_clock::now();
    int insertionNumComparisons4 = insertionSort(numbersCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> insertionNumTime4 = end - start;

    //Increasing Numbers
    start = chrono::high_resolution_clock::now();
    int insertionIncComparisons4 = insertionSort(increasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> insertionIncTime4 = end - start;

    //Decreasing Numbers
    start = chrono::high_resolution_clock::now();
    int insertionDecComparisons4 = insertionSort(decreasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> insertionDecTime4 = end - start;

    numbersCopy = numbers;
    increasingCopy = increasing;
    decreasingCopy = decreasing;
    numbersCopy.resize(2000);
    increasingCopy.resize(2000);
    decreasingCopy.resize(2000);


    //Randomized Numbers
    start = chrono::high_resolution_clock::now();
    int insertionNumComparisons2 = insertionSort(numbersCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> insertionNumTime2 = end - start;

    //Increasing Numbers
    start = chrono::high_resolution_clock::now();
    int insertionIncComparisons2 = insertionSort(increasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> insertionIncTime2 = end - start;

    //Decreasing Numbers
    start = chrono::high_resolution_clock::now();
    int insertionDecComparisons2 = insertionSort(decreasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> insertionDecTime2 = end - start;

    numbersCopy = numbers;
    increasingCopy = increasing;
    decreasingCopy = decreasing;
    numbersCopy.resize(1000);
    increasingCopy.resize(1000);
    decreasingCopy.resize(1000);


    //Randomized Numbers
    start = chrono::high_resolution_clock::now();
    int insertionNumComparisons1 = insertionSort(numbersCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> insertionNumTime1 = end - start;

    //Increasing Numbers
    start = chrono::high_resolution_clock::now();
    int insertionIncComparisons1 = insertionSort(increasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> insertionIncTime1 = end - start;

    //Decreasing Numbers
    start = chrono::high_resolution_clock::now();
    int insertionDecComparisons1 = insertionSort(decreasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> insertionDecTime1 = end - start;


    cout << "Comparisons (8000 Random Elements): " << insertionNumComparisons << endl;
    cout << "Time (8000 Random Elements): " << insertionNumTime8.count() << " seconds" << endl << endl;
    cout << "Comparisons (8000 Increasing Elements): " << insertionIncComparisons << endl;
    cout << "Time (8000 Increasing Elements): " << insertionIncTime8.count() << " seconds" << endl << endl;
    cout << "Comparisons (8000 Decreasing Elements): " << insertionDecComparisons << endl;
    cout << "Time (8000 Decreasing Elements): " << insertionDecTime8.count() << " seconds" << endl << endl;

    cout << "Comparisons (4000 Random Elements): " << insertionNumComparisons4 << endl;
    cout << "Time (4000 Random Elements): " << insertionNumTime4.count() << " seconds" << endl << endl;
    cout << "Comparisons (4000 Increasing Elements): " << insertionIncComparisons4 << endl;
    cout << "Time (4000 Increasing Elements): " << insertionIncTime4.count() << " seconds" << endl << endl;
    cout << "Comparisons (4000 Decreasing Elements): " << insertionDecComparisons4 << endl;
    cout << "Time (4000 Decreasing Elements): " << insertionDecTime4.count() << " seconds" << endl << endl;

    cout << "Comparisons (2000 Random Elements): " << insertionNumComparisons2 << endl;
    cout << "Time (2000 Random Elements): " << insertionNumTime2.count() << " seconds" << endl << endl;
    cout << "Comparisons (2000 Increasing Elements): " << insertionIncComparisons2 << endl;
    cout << "Time (2000 Increasing Elements): " << insertionIncTime2.count() << " seconds" << endl << endl;
    cout << "Comparisons (2000 Decreasing Elements): " << insertionDecComparisons2 << endl;
    cout << "Time (2000 Decreasing Elements): " << insertionDecTime2.count() << " seconds" << endl << endl;

    cout << "Comparisons (1000 Random Elements): " << insertionNumComparisons1 << endl;
    cout << "Time (1000 Random Elements): " << insertionNumTime1.count() << " seconds" << endl << endl;
    cout << "Comparisons (1000 Increasing Elements): " << insertionIncComparisons1 << endl;
    cout << "Time (1000 Increasing Elements): " << insertionIncTime1.count() << " seconds" << endl << endl;
    cout << "Comparisons (1000 Decreasing Elements): " << insertionDecComparisons1 << endl;
    cout << "Time (1000 Decreasing Elements): " << insertionDecTime1.count() << " seconds" << endl << endl;
}


void calculateQuickSort(vector<int> numbers, vector<int> increasing, vector<int> decreasing) {
    cout << endl << "QUICK SORT" << endl << endl;
    vector<int> numbersCopy = numbers;
    vector<int> increasingCopy = increasing;
    vector<int> decreasingCopy = decreasing;
    int startLow = 0;
    int startHigh = numbersCopy.size() - 1;

    int passedComparisonsRand8 = 0;
    int passedComparisonsInc8 = 0;
    int passedComparisonsDec8 = 0;
    //Randomized Numbers quickSort(numbersCopy, startLow, startHigh, passedComparisons);
    auto start = chrono::high_resolution_clock::now();
    quickSort(numbersCopy, startLow, startHigh, passedComparisonsRand8);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> quickNumTime8 = end - start;

    //Increasing Numbers
    start = chrono::high_resolution_clock::now();
    quickSort(increasingCopy, startLow, startHigh, passedComparisonsInc8);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> quickIncTime8 = end - start;

    //Decreasing Numbers
    start = chrono::high_resolution_clock::now();
    quickSort(decreasingCopy, startLow, startHigh, passedComparisonsDec8);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> quickDecTime8 = end - start;


    //cout << "Resetting vectors..." << endl;
    numbersCopy = numbers;
    increasingCopy = increasing;
    decreasingCopy = decreasing;
    //cout << "Decreasing Vector size to 4000" << endl;
    numbersCopy.resize(4000);
    increasingCopy.resize(4000);
    decreasingCopy.resize(4000);

    startHigh = numbersCopy.size() - 1;
    int passedComparisonsRand4 = 0;
    int passedComparisonsInc4 = 0;
    int passedComparisonsDec4 = 0;
    //Randomized Numbers
    start = chrono::high_resolution_clock::now();
    quickSort(numbersCopy, startLow, startHigh,  passedComparisonsRand4);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> quickNumTime4 = end - start;

    //Increasing Numbers
    start = chrono::high_resolution_clock::now();
    quickSort(increasingCopy, startLow, startHigh, passedComparisonsInc4);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> quickIncTime4 = end - start;

    //Decreasing Numbers
    start = chrono::high_resolution_clock::now();
    quickSort(decreasingCopy, startLow, startHigh, passedComparisonsDec4);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> quickDecTime4 = end - start;

    numbersCopy = numbers;
    increasingCopy = increasing;
    decreasingCopy = decreasing;
    numbersCopy.resize(2000);
    increasingCopy.resize(2000);
    decreasingCopy.resize(2000);

    startHigh = numbersCopy.size() - 1;
    int passedComparisonsRand2 = 0;
    int passedComparisonsInc2 = 0;
    int passedComparisonsDec2 = 0;
    //Randomized Numbers
    start = chrono::high_resolution_clock::now();
    quickSort(numbersCopy, startLow, startHigh,  passedComparisonsRand2);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> quickNumTime2 = end - start;

    //Increasing Numbers
    start = chrono::high_resolution_clock::now();
    quickSort(increasingCopy, startLow, startHigh, passedComparisonsInc2);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> quickIncTime2 = end - start;

    //Decreasing Numbers
    start = chrono::high_resolution_clock::now();
    quickSort(decreasingCopy, startLow, startHigh, passedComparisonsDec2);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> quickDecTime2 = end - start;

    numbersCopy = numbers;
    increasingCopy = increasing;
    decreasingCopy = decreasing;
    numbersCopy.resize(1000);
    increasingCopy.resize(1000);
    decreasingCopy.resize(1000);

    startHigh = numbersCopy.size() - 1;
    int passedComparisonsRand1 = 0;
    int passedComparisonsInc1 = 0;
    int passedComparisonsDec1 = 0;
    //Randomized Numbers
    start = chrono::high_resolution_clock::now();
    quickSort(numbersCopy, startLow, startHigh,  passedComparisonsRand1);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> quickNumTime1 = end - start;

    //Increasing Numbers
    start = chrono::high_resolution_clock::now();
    quickSort(increasingCopy, startLow, startHigh, passedComparisonsInc1);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> quickIncTime1 = end - start;

    //Decreasing Numbers
    start = chrono::high_resolution_clock::now();
    quickSort(decreasingCopy, startLow, startHigh, passedComparisonsDec1);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> quickDecTime1 = end - start;


    cout << "Comparisons (8000 Random Elements): " << passedComparisonsRand8 << endl;
    cout << "Time (8000 Random Elements): " << quickNumTime8.count() << " seconds" << endl << endl;
    cout << "Comparisons (8000 Increasing Elements): " << passedComparisonsInc8 << endl;
    cout << "Time (8000 Increasing Elements): " << quickIncTime8.count() << " seconds" << endl << endl;
    cout << "Comparisons (8000 Decreasing Elements): " << passedComparisonsDec8 << endl;
    cout << "Time (8000 Decreasing Elements): " << quickDecTime8.count() << " seconds" << endl << endl;

    cout << "Comparisons (4000 Random Elements): " << passedComparisonsRand4 << endl;
    cout << "Time (4000 Random Elements): " << quickNumTime4.count() << " seconds" << endl << endl;
    cout << "Comparisons (4000 Increasing Elements): " << passedComparisonsInc4 << endl;
    cout << "Time (4000 Increasing Elements): " << quickIncTime4.count() << " seconds" << endl << endl;
    cout << "Comparisons (4000 Decreasing Elements): " << passedComparisonsDec4 << endl;
    cout << "Time (4000 Decreasing Elements): " << quickDecTime4.count() << " seconds" << endl << endl;

    cout << "Comparisons (2000 Random Elements): " << passedComparisonsRand2 << endl;
    cout << "Time (2000 Random Elements): " << quickNumTime2.count() << " seconds" << endl << endl;
    cout << "Comparisons (2000 Increasing Elements): " << passedComparisonsInc2 << endl;
    cout << "Time (2000 Increasing Elements): " << quickIncTime2.count() << " seconds" << endl << endl;
    cout << "Comparisons (2000 Decreasing Elements): " << passedComparisonsDec2 << endl;
    cout << "Time (2000 Decreasing Elements): " << quickDecTime2.count() << " seconds" << endl << endl;

    cout << "Comparisons (1000 Random Elements): " << passedComparisonsRand1 << endl;
    cout << "Time (1000 Random Elements): " << quickNumTime1.count() << " seconds" << endl << endl;
    cout << "Comparisons (1000 Increasing Elements): " << passedComparisonsInc1 << endl;
    cout << "Time (1000 Increasing Elements): " << quickIncTime1.count() << " seconds" << endl << endl;
    cout << "Comparisons (1000 Decreasing Elements): " << passedComparisonsDec1 << endl;
    cout << "Time (1000 Decreasing Elements): " << quickDecTime1.count() << " seconds" << endl << endl;
}

void calculateHeapSort(vector<int> numbers, vector<int> increasing, vector<int> decreasing) {
    cout << endl << "HEAP SORT" << endl << endl;
    vector<int> numbersCopy = numbers;
    vector<int> increasingCopy = increasing;
    vector<int> decreasingCopy = decreasing;

    //Randomized Numbers
    auto start = chrono::high_resolution_clock::now();
    int heapNumComparisons = heapSort(numbersCopy);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> heapNumTime8 = end - start;

    //Increasing Numbers
    start = chrono::high_resolution_clock::now();
    int heapIncComparisons = heapSort(increasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> heapIncTime8 = end - start;

    //Decreasing Numbers
    start = chrono::high_resolution_clock::now();
    int heapDecComparisons = heapSort(decreasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> heapDecTime8 = end - start;


    //cout << "Resetting vectors..." << endl;
    numbersCopy = numbers;
    increasingCopy = increasing;
    decreasingCopy = decreasing;
    //cout << "Decreasing Vector size to 4000" << endl;
    numbersCopy.resize(4000);
    increasingCopy.resize(4000);
    decreasingCopy.resize(4000);


    //Randomized Numbers
    start = chrono::high_resolution_clock::now();
    int heapNumComparisons4 = heapSort(numbersCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> heapNumTime4 = end - start;

    //Increasing Numbers
    start = chrono::high_resolution_clock::now();
    int heapIncComparisons4 = heapSort(increasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> heapIncTime4 = end - start;

    //Decreasing Numbers
    start = chrono::high_resolution_clock::now();
    int heapDecComparisons4 = heapSort(decreasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> heapDecTime4 = end - start;

    numbersCopy = numbers;
    increasingCopy = increasing;
    decreasingCopy = decreasing;
    numbersCopy.resize(2000);
    increasingCopy.resize(2000);
    decreasingCopy.resize(2000);


    //Randomized Numbers
    start = chrono::high_resolution_clock::now();
    int heapNumComparisons2 = heapSort(numbersCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> heapNumTime2 = end - start;

    //Increasing Numbers
    start = chrono::high_resolution_clock::now();
    int heapIncComparisons2 = heapSort(increasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> heapIncTime2 = end - start;

    //Decreasing Numbers
    start = chrono::high_resolution_clock::now();
    int heapDecComparisons2 = heapSort(decreasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> heapDecTime2 = end - start;

    numbersCopy = numbers;
    increasingCopy = increasing;
    decreasingCopy = decreasing;
    numbersCopy.resize(1000);
    increasingCopy.resize(1000);
    decreasingCopy.resize(1000);


    //Randomized Numbers
    start = chrono::high_resolution_clock::now();
    int heapNumComparisons1 = heapSort(numbersCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> heapNumTime1 = end - start;

    //Increasing Numbers
    start = chrono::high_resolution_clock::now();
    int heapIncComparisons1 = heapSort(increasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> heapIncTime1 = end - start;

    //Decreasing Numbers
    start = chrono::high_resolution_clock::now();
    int heapDecComparisons1 = heapSort(decreasingCopy);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> heapDecTime1 = end - start;


    cout << "Comparisons (8000 Random Elements): " << heapNumComparisons << endl;
    cout << "Time (8000 Random Elements): " << heapNumTime8.count() << " seconds" << endl << endl;
    cout << "Comparisons (8000 Increasing Elements): " << heapIncComparisons << endl;
    cout << "Time (8000 Increasing Elements): " << heapIncTime8.count() << " seconds" << endl << endl;
    cout << "Comparisons (8000 Decreasing Elements): " << heapDecComparisons << endl;
    cout << "Time (8000 Decreasing Elements): " << heapDecTime8.count() << " seconds" << endl << endl;

    cout << "Comparisons (4000 Random Elements): " << heapNumComparisons4 << endl;
    cout << "Time (4000 Random Elements): " << heapNumTime4.count() << " seconds" << endl << endl;
    cout << "Comparisons (4000 Increasing Elements): " << heapIncComparisons4 << endl;
    cout << "Time (4000 Increasing Elements): " << heapIncTime4.count() << " seconds" << endl << endl;
    cout << "Comparisons (4000 Decreasing Elements): " << heapDecComparisons4 << endl;
    cout << "Time (4000 Decreasing Elements): " << heapDecTime4.count() << " seconds" << endl << endl;

    cout << "Comparisons (2000 Random Elements): " << heapNumComparisons2 << endl;
    cout << "Time (2000 Random Elements): " << heapNumTime2.count() << " seconds" << endl << endl;
    cout << "Comparisons (2000 Increasing Elements): " << heapIncComparisons2 << endl;
    cout << "Time (2000 Increasing Elements): " << heapIncTime2.count() << " seconds" << endl << endl;
    cout << "Comparisons (2000 Decreasing Elements): " << heapDecComparisons2 << endl;
    cout << "Time (2000 Decreasing Elements): " << heapDecTime2.count() << " seconds" << endl << endl;

    cout << "Comparisons (1000 Random Elements): " << heapNumComparisons1 << endl;
    cout << "Time (1000 Random Elements): " << heapNumTime1.count() << " seconds" << endl << endl;
    cout << "Comparisons (1000 Increasing Elements): " << heapIncComparisons1 << endl;
    cout << "Time (1000 Increasing Elements): " << heapIncTime1.count() << " seconds" << endl << endl;
    cout << "Comparisons (1000 Decreasing Elements): " << heapDecComparisons1 << endl;
    cout << "Time (1000 Decreasing Elements): " << heapDecTime1.count() << " seconds" << endl << endl;
}


void calculate3MergeSort(vector<int> numbers, vector<int> increasing, vector<int> decreasing) {
    cout << endl << "3-WAY MERGE SORT" << endl << endl;
    vector<int> numbersCopy = numbers;
    vector<int> increasingCopy = increasing;
    vector<int> decreasingCopy = decreasing;
    int startLow = 0;
    int startHigh = numbersCopy.size() - 1;

    int passedComparisonsRand8 = 0;
    int passedComparisonsInc8 = 0;
    int passedComparisonsDec8 = 0;
    //Randomized Numbers threeWayMergeSort(numbersCopy, startLow, startHigh, passedComparisons);
    auto start = chrono::high_resolution_clock::now();
    threeWayMergeSort(numbersCopy, startLow, startHigh, passedComparisonsRand8);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> mergeNumTime8 = end - start;

    //Increasing Numbers
    start = chrono::high_resolution_clock::now();
    threeWayMergeSort(increasingCopy, startLow, startHigh, passedComparisonsInc8);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> mergeIncTime8 = end - start;

    //Decreasing Numbers
    start = chrono::high_resolution_clock::now();
    threeWayMergeSort(decreasingCopy, startLow, startHigh, passedComparisonsDec8);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> mergeDecTime8 = end - start;


    //cout << "Resetting vectors..." << endl;
    numbersCopy = numbers;
    increasingCopy = increasing;
    decreasingCopy = decreasing;
    //cout << "Decreasing Vector size to 4000" << endl;
    numbersCopy.resize(4000);
    increasingCopy.resize(4000);
    decreasingCopy.resize(4000);

    startHigh = numbersCopy.size() - 1;
    int passedComparisonsRand4 = 0;
    int passedComparisonsInc4 = 0;
    int passedComparisonsDec4 = 0;
    //Randomized Numbers
    start = chrono::high_resolution_clock::now();
    threeWayMergeSort(numbersCopy, startLow, startHigh, passedComparisonsRand4);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> mergeNumTime4 = end - start;

    //Increasing Numbers
    start = chrono::high_resolution_clock::now();
    threeWayMergeSort(increasingCopy, startLow, startHigh, passedComparisonsInc4);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> mergeIncTime4 = end - start;

    //Decreasing Numbers
    start = chrono::high_resolution_clock::now();
    threeWayMergeSort(decreasingCopy, startLow, startHigh, passedComparisonsDec4);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> mergeDecTime4 = end - start;

    numbersCopy = numbers;
    increasingCopy = increasing;
    decreasingCopy = decreasing;
    numbersCopy.resize(2000);
    increasingCopy.resize(2000);
    decreasingCopy.resize(2000);

    startHigh = numbersCopy.size() - 1;
    int passedComparisonsRand2 = 0;
    int passedComparisonsInc2 = 0;
    int passedComparisonsDec2 = 0;
    //Randomized Numbers
    start = chrono::high_resolution_clock::now();
    threeWayMergeSort(numbersCopy, startLow, startHigh, passedComparisonsRand2);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> mergeNumTime2 = end - start;

    //Increasing Numbers
    start = chrono::high_resolution_clock::now();
    threeWayMergeSort(increasingCopy, startLow, startHigh, passedComparisonsInc2);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> mergeIncTime2 = end - start;

    //Decreasing Numbers
    start = chrono::high_resolution_clock::now();
    threeWayMergeSort(decreasingCopy, startLow, startHigh, passedComparisonsDec2);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> mergeDecTime2 = end - start;

    numbersCopy = numbers;
    increasingCopy = increasing;
    decreasingCopy = decreasing;
    numbersCopy.resize(1000);
    increasingCopy.resize(1000);
    decreasingCopy.resize(1000);

    startHigh = numbersCopy.size() - 1;
    int passedComparisonsRand1 = 0;
    int passedComparisonsInc1 = 0;
    int passedComparisonsDec1 = 0;
    //Randomized Numbers
    start = chrono::high_resolution_clock::now();
    threeWayMergeSort(numbersCopy, startLow, startHigh, passedComparisonsRand1);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> mergeNumTime1 = end - start;

    //Increasing Numbers
    start = chrono::high_resolution_clock::now();
    threeWayMergeSort(increasingCopy, startLow, startHigh, passedComparisonsInc1);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> mergeIncTime1 = end - start;

    //Decreasing Numbers
    start = chrono::high_resolution_clock::now();
    threeWayMergeSort(decreasingCopy, startLow, startHigh, passedComparisonsDec1);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> mergeDecTime1 = end - start;


    cout << "Comparisons (8000 Random Elements): " << passedComparisonsRand8 << endl;
    cout << "Time (8000 Random Elements): " << mergeNumTime8.count() << " seconds" << endl << endl;
    cout << "Comparisons (8000 Increasing Elements): " << passedComparisonsInc8 << endl;
    cout << "Time (8000 Increasing Elements): " << mergeIncTime8.count() << " seconds" << endl << endl;
    cout << "Comparisons (8000 Decreasing Elements): " << passedComparisonsDec8 << endl;
    cout << "Time (8000 Decreasing Elements): " << mergeDecTime8.count() << " seconds" << endl << endl;

    cout << "Comparisons (4000 Random Elements): " << passedComparisonsRand4 << endl;
    cout << "Time (4000 Random Elements): " << mergeNumTime4.count() << " seconds" << endl << endl;
    cout << "Comparisons (4000 Increasing Elements): " << passedComparisonsInc4 << endl;
    cout << "Time (4000 Increasing Elements): " << mergeIncTime4.count() << " seconds" << endl << endl;
    cout << "Comparisons (4000 Decreasing Elements): " << passedComparisonsDec4 << endl;
    cout << "Time (4000 Decreasing Elements): " << mergeDecTime4.count() << " seconds" << endl << endl;

    cout << "Comparisons (2000 Random Elements): " << passedComparisonsRand2 << endl;
    cout << "Time (2000 Random Elements): " << mergeNumTime2.count() << " seconds" << endl << endl;
    cout << "Comparisons (2000 Increasing Elements): " << passedComparisonsInc2 << endl;
    cout << "Time (2000 Increasing Elements): " << mergeIncTime2.count() << " seconds" << endl << endl;
    cout << "Comparisons (2000 Decreasing Elements): " << passedComparisonsDec2 << endl;
    cout << "Time (2000 Decreasing Elements): " << mergeDecTime2.count() << " seconds" << endl << endl;

    cout << "Comparisons (1000 Random Elements): " << passedComparisonsRand1 << endl;
    cout << "Time (1000 Random Elements): " << mergeNumTime1.count() << " seconds" << endl << endl;
    cout << "Comparisons (1000 Increasing Elements): " << passedComparisonsInc1 << endl;
    cout << "Time (1000 Increasing Elements): " << mergeIncTime1.count() << " seconds" << endl << endl;
    cout << "Comparisons (1000 Decreasing Elements): " << passedComparisonsDec1 << endl;
    cout << "Time (1000 Decreasing Elements): " << mergeDecTime1.count() << " seconds" << endl << endl;
}