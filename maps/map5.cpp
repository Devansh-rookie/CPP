#include <stdio.h>

#define SIZE 10
#define EMPTY -1

int hashTable[SIZE];

// First hash function
int hashFunction1(int key) {
    return key % SIZE;
}

// Second hash function
int hashFunction2(int key) {
    return (7 - (key % 7));  // Typically another prime number smaller than table size
}

void insert(int key) {
    int index = hashFunction1(key);
    int stepSize = hashFunction2(key);
    while (hashTable[index] != EMPTY) {
        index = (index + stepSize) % SIZE;  // Double hashing to resolve collision
    }
    hashTable[index] = key;
    printf("Inserted key %d at index %d\n", key, index);
}

int search(int key) {
    int index = hashFunction1(key);
    int stepSize = hashFunction2(key);
    int count = 0;
    while (hashTable[index] != EMPTY && count < SIZE) {
        if (hashTable[index] == key) {
            return index;
        }
        index = (index + stepSize) % SIZE;
        count++;
    }
    return -1;
}

void initHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

void printHashTable() {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != EMPTY)
            printf("%d --> %d\n", i, hashTable[i]);
        else
            printf("%d --> Empty\n", i);
    }
}

int main() {
    initHashTable();
    
    insert(5);
    insert(15);
    insert(25);
    insert(35);  // Collision handled by double hashing
    printHashTable();

    int key = 15;
    int result = search(key);
    if (result != -1)
        printf("Key %d found at index %d\n", key, result);
    else
        printf("Key %d not found\n", key);

    return 0;
}
