#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

class HashTable {
    vector<int> table;
    int size;
    int emptySlot = -1;

public:
    HashTable(int s) : size(s) {
        table.resize(size, emptySlot);
    }

    int hashFunction1(int key) {
        return key % size;
    }

    int hashFunction2(int key) {
        return (7 - (key % 7));
    }

    // Linear probing insertion
    void insertLinear(int key) {
        int hashIndex = hashFunction1(key);
        while (table[hashIndex] != emptySlot) {
            hashIndex = (hashIndex + 1) % size;  // Linear probing
        }
        table[hashIndex] = key;
    }

    // Double hashing insertion
    void insertDouble(int key) {
        int hashIndex = hashFunction1(key);
        int stepSize = hashFunction2(key);
        while (table[hashIndex] != emptySlot) {
            hashIndex = (hashIndex + stepSize) % size;  // Double hashing
        }
        table[hashIndex] = key;
    }

    // Searching in linear probing
    int searchLinear(int key) {
        int hashIndex = hashFunction1(key);
        while (table[hashIndex] != emptySlot) {
            if (table[hashIndex] == key)
                return hashIndex;
            hashIndex = (hashIndex + 1) % size;
        }
        return -1;
    }

    // Searching in double hashing
    int searchDouble(int key) {
        int hashIndex = hashFunction1(key);
        int stepSize = hashFunction2(key);
        while (table[hashIndex] != emptySlot) {
            if (table[hashIndex] == key)
                return hashIndex;
            hashIndex = (hashIndex + stepSize) % size;
        }
        return -1;
    }

    // Reset table for fresh operations
    void reset() {
        fill(table.begin(), table.end(), emptySlot);
    }
};

int main() {
    int tableSize = 10000;
    HashTable ht(tableSize);

    // Measure linear probing time
    auto start = high_resolution_clock::now();
    for (int i = 0; i < tableSize; i++) {
        ht.insertLinear(i);
    }
    auto stop = high_resolution_clock::now();
    auto linearTime = duration_cast<microseconds>(stop - start);
    cout << "Time taken for insertion using Linear Probing: " << linearTime.count() << " microseconds" << endl;

    // Reset the hash table for double hashing
    ht.reset();

    // Measure double hashing time
    start = high_resolution_clock::now();
    for (int i = 0; i < tableSize; i++) {
        ht.insertDouble(i);
    }
    stop = high_resolution_clock::now();
    auto doubleTime = duration_cast<microseconds>(stop - start);
    cout << "Time taken for insertion using Double Hashing: " << doubleTime.count() << " microseconds" << endl;

    // Searching performance comparison
    int searchKey = tableSize - 1;  // Last key

    // Linear search time
    start = high_resolution_clock::now();
    ht.searchLinear(searchKey);
    stop = high_resolution_clock::now();
    auto linearSearchTime = duration_cast<nanoseconds>(stop - start);
    cout << "Time taken for searching using Linear Probing: " << linearSearchTime.count() << " nanoseconds" << endl;

    // Double search time
    start = high_resolution_clock::now();
    ht.searchDouble(searchKey);
    stop = high_resolution_clock::now();
    auto doubleSearchTime = duration_cast<nanoseconds>(stop - start);
    cout << "Time taken for searching using Double Hashing: " << doubleSearchTime.count() << " nanoseconds" << endl;

    return 0;
}
