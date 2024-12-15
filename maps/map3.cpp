#include <iostream>
#include <chrono>
#include <vector>
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

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        int hashIndex = hashFunction(key);
        while (table[hashIndex] != emptySlot) {
            hashIndex = (hashIndex + 1) % size;
        }
        table[hashIndex] = key;
    }

    int search(int key) {
        int hashIndex = hashFunction(key);
        while (table[hashIndex] != emptySlot) {
            if (table[hashIndex] == key)
                return hashIndex;
            hashIndex = (hashIndex + 1) % size;
        }
        return -1;
    }
};

int main() {
    HashTable ht(10000);

    // Insert large number of elements
    for (int i = 0; i < 10000; i++) {
        ht.insert(i * 2);  // Even numbers
    }

    // Measure the time taken for searching
    int key = 9998;  // Key to search
    auto start = high_resolution_clock::now();
    int result = ht.search(key);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    if (result != -1)
        cout << "Key " << key << " found at index " << result << endl;
    else
        cout << "Key " << key << " not found" << endl;

    cout << "Time taken: " << duration.count() << " nanoseconds" << endl;

    return 0;
}
