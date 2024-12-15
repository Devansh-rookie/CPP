#include <iostream>
#include <vector>
using namespace std;

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
        int originalIndex = hashIndex;
        while (table[hashIndex] != emptySlot) {
            hashIndex = (hashIndex + 1) % size;
            if (hashIndex == originalIndex) {
                cout << "Hash table is full, cannot insert " << key << endl;
                return;
            }
        }
        table[hashIndex] = key;
        cout << "Inserted " << key << " at index " << hashIndex << endl;
    }

    void search(int key) {
        int hashIndex = hashFunction(key);
        int originalIndex = hashIndex;
        while (table[hashIndex] != emptySlot) {
            if (table[hashIndex] == key) {
                cout << key << " found at index " << hashIndex << endl;
                return;
            }
            hashIndex = (hashIndex + 1) % size;
            if (hashIndex == originalIndex) {
                break;
            }
        }
        cout << key << " not found in the hash table." << endl;
    }

    void remove(int key) {
        int hashIndex = hashFunction(key);
        int originalIndex = hashIndex;
        while (table[hashIndex] != emptySlot) {
            if (table[hashIndex] == key) {
                table[hashIndex] = emptySlot;
                cout << "Removed " << key << " from index " << hashIndex << endl;
                return;
            }
            hashIndex = (hashIndex + 1) % size;
            if (hashIndex == originalIndex) {
                break;
            }
        }
        cout << key << " not found in the hash table, cannot remove." << endl;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (table[i] != emptySlot)
                cout << i << " --> " << table[i] << endl;
            else
                cout << i << " --> " << "Empty" << endl;
        }
    }
};

int main() {
    HashTable ht(7);
    ht.insert(10);
    ht.insert(20);
    ht.insert(5);
    ht.insert(15);
    ht.insert(7);
    ht.search(15);
    ht.remove(20);
    ht.display();

    return 0;
}
