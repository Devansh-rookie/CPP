#include<bits/stdc++.h>
using namespace std;

class MinHeap {
    vector<int> heap;

    // Helper function to get the parent, left, and right child indices
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

public:
    // Display the heap
    void display() {
        for (int i : heap) {
            cout << i << " ";
        }
        cout << endl;
    }

    // Insert a new key into the heap
    void push(int key) {
        heap.push_back(key);
        int i = heap.size() - 1;

        // Fix the min-heap property
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Extract the root (minimum element)
    int pop() {
        if (heap.size() <= 0) return INT_MAX;
        if (heap.size() == 1) {
            int root = heap[0];
            heap.pop_back();
            return root;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        heapify(0);
        return root;
    }

    // Heapify a subtree with the root at given index
    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < heap.size() && heap[l] < heap[smallest])
            smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    // Increase the value of a key at index i to new_val
    void increaseKey(int i, int new_val) {
        if (new_val < heap[i]) {
            cout << "New value is smaller than the current value" << endl;
            return;
        }

        heap[i] = new_val;
        heapify(i);
    }

    // Decrease the value of a key at index i to new_val
    void decreaseKey(int i, int new_val) {
        if (new_val > heap[i]) {
            cout << "New value is larger than the current value" << endl;
            return;
        }

        heap[i] = new_val;
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
};

int main() {
    MinHeap h;
    h.push(3);
    h.push(2);
    h.push(15);
    h.push(5);
    h.push(4);
    h.push(45);

    cout << "Heap elements: ";
    h.display();

    cout << "Extracted min: " << h.pop() << endl;
    cout << "Heap after extraction: ";
    h.display();

    h.decreaseKey(2, 1);
    cout << "Heap after decreasing key: ";
    h.display();

    h.increaseKey(0, 20);
    cout << "Heap after increasing key: ";
    h.display();

    return 0;
}
