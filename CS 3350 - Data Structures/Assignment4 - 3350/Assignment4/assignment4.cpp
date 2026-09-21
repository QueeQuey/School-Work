//Layne Woodruff, CS3350:
#include <iostream>
#include <list>
using namespace std;

class HashTable {
private:
    list<int>* table;
    int total_elements;
    // Hash function to calculate hash for a value:
    int getHash(int key) {
        return key % total_elements;
    }

public:
    // Constructor to create a hash table with 'n' indices:
    HashTable(int n) {
        total_elements = n;
        table = new list<int>[total_elements];
    }

    // Insert data in the hash table:
    void insertElement(int key) {
        //Implement the function below:
        //Get hash, insert hash into table
        int locKey = getHash(key);
        table[locKey].push_back(key);
    }

    // Remove data from the hash table:
    void removeElement(int key) {
      //Implement the function below:
       //Get get hash, remove.
       int locKey = getHash(key);
       table[locKey].remove(key);
    }

    void printAll() {
        //Implement the function below:
         //Loop through hash, print each pair.
        for (int i = 0; i < total_elements; i++) {
            cout << "Index " << i << ": ";
            for (int val : table[i]) {
                //cout << "Key " << val;
                cout << val << " => ";
            }
            cout << endl;
        }
    }

};



    class HashTable2 {
    //implement the entire HashTable2 using doublel hashing. You need to implement insertElement(), removeElement(), and printALL().
    //Use key % total_elements as first hash function, and 7 - (key % 7) as second hash function.
    private:
        int* table;
        int total_elements;
        //had to swallow my pride and do it like how they do on geeksforgeeks and set -1 to an empty value to fill the table;
        const int EMPTY = -1;

        //First and second Hash
        int firstHash(int key){
            return key % total_elements;
        }
        int secondHash(int key) {
            return 7 - (key % 7);
        }

        // Check if a slot is empty
        bool isEmpty(int index) const {
            return table[index] == EMPTY;
        }

    public:
        // Constructor to initialize table
        HashTable2(int n) : total_elements(n) {
            table = new int[total_elements];
            for (int i = 0; i < total_elements; i++) {
                table[i] = EMPTY;
            }
        }

        // Insert function using double hashing
        void insertElement(int key) {
            int index = firstHash(key);
            int stepSize = secondHash(key);

            //While the spot is not empty, and the index is not the key, keep searching
            while (!isEmpty(index) && table[index] != key) {
                index = (index + stepSize) % total_elements;
            }
            table[index] = key;
        }

        // Remove function
        void removeElement(int key) {
            int index = firstHash(key);
            int addSecondHash = secondHash(key);

            //While spots aren't empty, keep searching
            //If found, mark spot as empty, then return
            while (!isEmpty(index)) {
                if (table[index] == key) {
                    table[index] = EMPTY;
                    return;
                }
                //Increment for while loop
                index = (index + addSecondHash) % total_elements;
            }
        }

        
        void printAll() {
            //Goes through table, prints each through a loop
            for (int i = 0; i < total_elements; i++) {
                cout << "Index " << i << ": ";
                if (!isEmpty(table[i]) && table[i] >= 0) {
                    cout << table[i] << endl;
                }
                else { 
                    cout << endl; 
                }
            }
        }

};


int main() {

    // Create a hash table with 11 indices:
    HashTable ht(11);
    // Declare the data to be stored in the hash table:
    int arr[] = { 2, 8, 19, 20, 26 };

    // Insert the whole data into the hash table:
    for (int i = 0; i < 5; i++)
        ht.insertElement(arr[i]);

    cout << "..:: Hash Table with separate chaining::.." << endl;
    ht.printAll();

    ht.removeElement(8);
    cout << endl << "..:: After deleting 8 ::.." << endl;
    ht.printAll();
    cout << endl;
    cout << "*************************************************************************" << endl;

    // Create a hash table with 11 indices:
    HashTable2 ht2(11);

    // Declare the data to be stored in the hash table:
    int arr2[] = { 2, 8, 19, 20, 26 };

    // Insert the whole data into the hash table:
    for (int i = 0; i < 5; i++)
        ht2.insertElement(arr2[i]);

    cout << "..:: Hash Table with double hashing::.." << endl;
    ht2.printAll();

    ht2.removeElement(8);
    cout << endl << "..:: After deleting 8 ::.." << endl;
    ht2.printAll();

    return 0;


}



/*
The old HashTable2. I was having an issue with Initialization and the remove function since I wanted to use the one given in cplusplus.com that 
was linked to us from lists.

class HashTable2 {
    //implement the entire HashTable2 using doublel hashing. You need to implement insertElement(), removeElement(), and printALL().
    //Use key % total_elements as first hash function, and 7 - (key % 7) as second hash function.
    private:
        int* table;
        int total_elements;
        //had to swallow my pride and do it like how they do on geeksforgeeks and set -1 to an empty value;
        const int EMPTY = -1;


        //First and second Hash
        int firstHash(int key){
            return key % total_elements;
        }
        int secondHash(int key) {
            return 7 - (key % 7);
        }

    public:
        //Initialize New Table
        HashTable2(int n){
            //New table of ints, same ize
            total_elements = n;
            table = new int[total_elements];
        }
        void insertElement(int key) {
            int index = firstHash(key);
            int addSecondHash = secondHash(key);

            while (!isEmpty(table[index]) && table[index] != key) {
                index = (index + addSecondHash) % total_elements;
            }
            table[index] = key;
        }

        void removeElement(int key) {
            int index = firstHash(key);
            int addSecondHash = secondHash(key);

            while (!isEmpty(table[index])) {
                if (table[index] == key) {
                    //delete table[index];
                    return;
                }
                index = (index + addSecondHash) % total_elements;
            }
        }

        void printAll() {
            for (int i = 0; i < total_elements; i++) {
                cout << "Index " << i << ": ";
                if (!isEmpty(table[i])) {
                    cout << table[i] << endl;
                }
                else { cout << endl; }
            }
        }

        bool isEmpty(int index) const {
            return isEmpty(table[index]);
        }
};
*/