// Assignment2_Woodruff.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include "SortTracker.h"
using namespace std;

//Declaring Functions:
//void SelectionSort(string* numbers, int numbersSize);
vector<string> readFileLines(const string& filename);

void SelectionSort(vector<string>& numbers, int& comparisons, int& swaps);
void InsertionSort(vector<string>& numbers, int& comparisons, int& swaps);
void MergeSort(vector<string>& numbers, int left, int right, int& comparisons, int& swaps);
void Merge(vector<string>& numbers, int left, int mid, int right, int& comparisons, int& swaps);
void BubbleSort(vector<string>& numbers, int& comparisons, int& swaps);
void QuickSort(vector<string>& numbers, int low, int high, int& comparisons, int& swaps);
int MedianOfThree(vector<string>& numbers, int low, int high, int& comparisons, int& swaps);
int Partition(vector<string>& numbers, int low, int high, int& comparisons, int& swaps);

int main() {
    //Not necessary for the assingment, but I created a text file for each for the output to check
    ofstream bubbleFile("BubbleSort_Sorted.txt");
    ofstream selectionFile("SelectionSort_Sorted.txt");
    ofstream insertionFile("InsertionSort_Sorted.txt");
    ofstream mergeFile("MergeSort_Sorted.txt");
    ofstream quickFile("QuickSort_Sorted.txt");

    vector<string> fileLines = readFileLines("Passwords.txt");
    
    //Making copies for each test
    vector<string> bubbleLines = fileLines;
    vector<string> selectionLines = fileLines;
    vector<string> insertionLines = fileLines;
    vector<string> mergeLines = fileLines;
    vector<string> quickLines = fileLines;
    int textLength = sizeof(fileLines);
    int comparisons = 0;
    int swaps = 0;
    int passwordNumbers = 0;
    //Getting the total Number of passwords
    for (const auto& line : fileLines) {
        passwordNumbers++;
    }
    cout << "Number of passwords (n):" << passwordNumbers << endl;
    //cout << "Hello World!\n";
    /*
    cout << "SELECTION SORT TEST \n";
    string words[] = { "banana", "apple", "grape", "cherry", "orange" };
    int wordsSize = sizeof(words) / sizeof(words[0]);
    //SelectionSort(words, wordsSize);
    for (int i = 0; i < wordsSize; i++) {
        cout << words[i] << " ";
        }
    */
    
    //Calling each of the Sorting types and putting the results into the console/File.
    //----------------------------------------------------------------------------------------------
    cout << "Selection Sort \n";
    SelectionSort(selectionLines, comparisons, swaps);
    for (const auto& line : selectionLines) {
        //cout << line << endl;
        selectionFile << line << endl;
    }
    cout << "Selection Sort comparisons: " << comparisons << "\n";
    cout << "Selection Sort swaps: " << swaps << "\n";
    selectionFile << "Selection Sort comparisons: " << comparisons << "\n";
    selectionFile << "Selection Sort swaps: " << swaps << "\n";
    selectionFile.close();

    //Resetting comparisons and swaps to 0 for the next Sorting algorithm
    comparisons = 0;
    swaps = 0;

    //-----------------------------------------------------------------------------------

    cout << "\nInsertion Sort \n";
    InsertionSort(insertionLines, comparisons, swaps);
    for (const auto& line : insertionLines) {
        //cout << line << endl;
        insertionFile << line << endl;
    }
    cout << "Insertion Sort comparisons: " << comparisons << "\n";
    cout << "Insertion Sort swaps: " << swaps << "\n";
    insertionFile << "Insertion Sort comparisons: " << comparisons << "\n";
    insertionFile << "Insertion Sort swaps: " << swaps << "\n";
    insertionFile.close();

    //-----------------------------------------------------------------------------------

    comparisons = 0;
    swaps = 0;
    cout << "\nMerge Sort \n";
    MergeSort(mergeLines, 0, mergeLines.size() - 1, comparisons, swaps);
    for (const auto& line : mergeLines) {
        //cout << line << endl;
        mergeFile << line << endl;
    }
    cout << "Merge Sort comparisons: " << comparisons << "\n";
    cout << "Merge Sort \"swaps\":" << swaps << "\n";
    cout << "(\"swaps\" Because copies are made, not swaps)" << "\n";
    mergeFile << "Merge Sort comparisons: " << comparisons << "\n";
    mergeFile << "Merge Sort \"swaps\":" << swaps << "\n";
    mergeFile << "(\"swaps\" Because copies are made, not swaps)" << "\n";

    mergeFile.close();

    //-----------------------------------------------------------------------------------

    comparisons = 0;
    swaps = 0;
    cout << "\nBubble Sort \n";
    BubbleSort(bubbleLines, comparisons, swaps);
    for (const auto& line : bubbleLines) {
        //cout << line << endl;
        bubbleFile << line << endl;
    }
    cout << "Bubble Sort comparisons: " << comparisons << "\n";
    cout << "Bubble Sort swaps: " << swaps << "\n";
    bubbleFile << "Bubble Sort comparisons: " << comparisons << "\n";
    bubbleFile << "Bubble Sort swaps: " << swaps << "\n";
    bubbleFile.close();
    
    //-----------------------------------------------------------------------------------
    
    comparisons = 0;
    swaps = 0;
    cout << "\nQuick Sort \n";
    QuickSort(quickLines, 0, quickLines.size() - 1, comparisons, swaps);
    for (const auto& line : quickLines) {
        //cout << line << endl;
        quickFile << line << endl;
    }
    cout << "Quick Sort comparisons: " << comparisons << "\n";
    cout << "QUick Sort swaps : " << swaps << "\n";
    quickFile << "Quick Sort comparisons: " << comparisons << "\n";
    quickFile << "Quick Sort \"swaps\":" << swaps << "\n";
    quickFile.close();

    return 0;
}

//Input is swapped from Arrays to Vectors, since it was easier.
//SELECTION SORT TAKEN FROM BOOK - hence the shared variable names. 
void SelectionSort(vector<string>& numbers, int& comparisons, int& swaps) {
    int numbersSize = numbers.size();
    for (int i = 0; i < numbersSize - 1; i++) {
        int indexSmallest = i;
        for (int j = i + 1; j < numbersSize; j++) {
            comparisons++;
            if (numbers[j] < numbers[indexSmallest]) {
                indexSmallest = j;
                //swaps++;
            }
        }
        if (indexSmallest != i) {
            swap(numbers[i], numbers[indexSmallest]);
            swaps++;
        }
    }
        // Swap numbers[i] and numbers[indexSmallest]
        //string temp = numbers[i];
        //numbers[i] = numbers[indexSmallest];
        //numbers[indexSmallest] = temp;
    
}


vector<string> readFileLines(const string& filename) {
    ifstream inputFile(filename);
    vector<string> unsortedPasswordVector;
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            unsortedPasswordVector.push_back(line);
        }
        inputFile.close();
    }
    else {
        cout << "Can't open the file \n";
    }

    return unsortedPasswordVector;
}

//Swapped to vector for the same reason as Selection sort.
//Instead of passing in a length, calls the size command of the input vector.
void InsertionSort(vector<string>& numbers, int& comparisons, int& swaps) {
    for (int i = 1; i < numbers.size(); i++) {
        string key = numbers[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (numbers[j] > key) {
                //swap(numbers[j + 1] , numbers[j]);
                numbers[j + 1] = numbers[j];
                swaps++;
                j--;
            }
            else {
                break;
            }
        }
        numbers[j + 1] = key;
    }
}


//Taken from book, slightly adjusted to take in the left, mid and right from the MergeSort()
// since the tracker isn't included then moved the calulations to here
void Merge(vector<string>& numbers, int left, int mid, int right, int& comparisons, int& swaps) {
    //int mergedSize = rightLast - leftFirst + 1;
    //int* mergedNumbers = new int[mergedSize];
    //int mergePos = 0;

    //Changed going by position to set
    int n1 = mid - left + 1; //int leftPos = leftFirst;
    int n2 = right - mid; //int rightPos = leftLast + 1;

    vector<string> leftArr(n1); // Creating a left vector
    vector<string> rightArr(n2); //Creating a right vector

    //Building the arrays
    for (int i = 0; i < n1; i++){
        leftArr[i] = numbers[left + i];
    swaps++;
    }
    for (int i = 0; i < n2; i++){
        rightArr[i] = numbers[mid + 1 + i];
    swaps++;
    }

    //Resetting values to 0 for the while loops.
    int leftPos= 0;
    int rightPos = 0;
    int mergePos = left;

    //Instead of leftPos <= leftLast && rightPos <= rightLast, going to n1 and n2
    while (leftPos < n1 && rightPos < n2){
        comparisons++;
        if (leftArr[leftPos] <= rightArr[rightPos]) {
            numbers[mergePos] = leftArr[leftPos];
            swaps++;
            leftPos++;
        }
        else{
            numbers[mergePos] = rightArr[rightPos];
            swaps++;
            rightPos++;
        }
        mergePos++;
    }
    //Going through the left side and itterating
    comparisons++;
    while (leftPos < n1) {
        numbers[mergePos] = leftArr[leftPos];
        swaps++;
        leftPos++;
        mergePos++;
    }
    //Going through the right side and itterating
    comparisons++;
    while (rightPos < n2) {
        numbers[mergePos] = rightArr[rightPos];
        swaps++;
        rightPos++;
        mergePos++;
    }
}

//As others, converted into vector. Removed the "tracker" that was in the 
//  example given in the book. Had to change to a left side and 
// right side after getting rid of the tracker.
void MergeSort(vector<string>& numbers, int left, int right, int& comparisons, int& swaps) {
    if (left < right) {
        // Find the midpoint in the partition
        int mid = left + (right - left) / 2;

        // Recursively sort left and right partitions
        MergeSort(numbers, left, mid, comparisons, swaps);
        MergeSort(numbers, mid + 1, right, comparisons, swaps);

        // Merge left and right partition in sorted order
        Merge(numbers, left, mid, right, comparisons, swaps);
    }
}

void BubbleSort(vector<string>& numbers, int& comparisons, int& swaps) {
    bool swapped;
    for (int i = 0; i < numbers.size() - 1; i++) {
        swapped = false;
        for (int j = 0; j < numbers.size() - i - 1; j++) {
            comparisons++;
            if (numbers[j] > numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]);
                swaps++;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

/*
* void Quicksort(int* numbers, int lowIndex, int highIndex) {
   if (highIndex <= lowIndex) {
      return;
   }

   int lowEndIndex = Partition(numbers, lowIndex, highIndex);
   Quicksort(numbers, lowIndex, lowEndIndex);
   Quicksort(numbers, lowEndIndex + 1, highIndex);
}
*/

void QuickSort(vector<string>& numbers, int low, int high, int& comparisons, int& swaps) {
    if (low < high) {
        // Uses the median-of-three to choose the pivot
        int pivotIndex = MedianOfThree(numbers, low, high, comparisons, swaps);
        // Partitions around the pivot and gets the index of the pivot
        int pi = Partition(numbers, low, high, comparisons, swaps);
        // Recursively sorts the two partitions
        QuickSort(numbers, low, pi - 1, comparisons, swaps);
        QuickSort(numbers, pi + 1, high, comparisons, swaps);
    }
}


int MedianOfThree(vector<string>& numbers, int low, int high, int& comparisons, int& swaps) {
    int mid = low + (high - low) / 2;

    //Might be a tad hard to read but a comparision is itterated before each if() statement. Likewise with the swaps.
    comparisons++;
    if (numbers[low] > numbers[mid]) {
        swaps++;
        swap(numbers[low], numbers[mid]); //Swap command found on dev.to when looking for the median of 3, addded to bubble sort above as well
    }
    comparisons++;
    if (numbers[low] > numbers[high]){
        swaps++;
        swap(numbers[low], numbers[high]);
    }
    comparisons++;
    if (numbers[mid] > numbers[high]) {
        swaps++;
        swap(numbers[mid], numbers[high]);
    }
    swaps++;
    swap(numbers[mid], numbers[high - 1]);
    return high - 1; // Return pivot index
}

/*
* for (let i = start; i < iPivotTemp; i++) { //update array in place by moving smaller elements to the front of the array
    const curr = arr[i];

    if (comparator(curr, pivotVal) < 0) {
      swap(arr, i, iPivotTarget);
      iPivotTarget++; // iPivotTarget is incremented with each swap to provide the correct location for the current swap and count the number of swaps. The final pivot index should be equal to the number of swaps.
    }
*/

//Needed to adjust the partition function from the book quite a bit here.
//  normally it has a boolean check if it's done as you go through the two
int Partition(vector<string>& numbers, int low, int high, int& comparisons, int& swaps) {
    int i = low - 1; //int midpoint = lowIndex + (highIndex - lowIndex) / 2;
    string pivot = numbers[high]; // int pivot = numbers[midpoint];

    for (int lowIndex = low; lowIndex < high; lowIndex++) {
        comparisons++;
        if (numbers[lowIndex] < pivot) {
            i++;
            swap(numbers[i], numbers[lowIndex]);
            swaps++;
        }
    }
    swap(numbers[i + 1], numbers[high]);
    swaps++;
    return (i + 1);
}