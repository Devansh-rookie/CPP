#include <stdio.h>

#define SIZE 10
#define EMPTY -1

int hashTable[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    while (hashTable[index] != EMPTY) {
        index = (index + 1) % SIZE;  // Linear probing
    }
    hashTable[index] = key;
}

int search(int key) {
    int index = hashFunction(key);
    int count = 0;
    while (hashTable[index] != EMPTY && count < SIZE) {
        if (hashTable[index] == key) {
            return index;
        }
        index = (index + 1) % SIZE;
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
    printHashTable();

    int key = 15;
    int result = search(key);
    if (result != -1)
        printf("Key %d found at index %d\n", key, result);
    else
        printf("Key %d not found\n", key);

    return 0;
}
