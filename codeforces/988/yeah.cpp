#include <iostream>
#include <vector>
using namespace std;

void updateInterval(vector<int>& diff, int l, int r, int x) {
    diff[l] += x;
    if (r + 1 < diff.size()) {
        diff[r + 1] -= x;
    }
}

vector<int> applyUpdates(const vector<int>& arr, const vector<int>& diff) {
    int n = arr.size();
    vector<int> result(n);
    int runningSum = 0;

    for (int i = 0; i < n; ++i) {
        runningSum += diff[i];
        result[i] = arr[i] + runningSum;
    }
    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5}; // Original array
    int n = arr.size();
    vector<int> diff(n + 1, 0); // Difference array

    // Update intervals
    updateInterval(diff, 1, 3, 2); // Increment elements in range [1, 3] by 2
    updateInterval(diff, 0, 2, 1); // Increment elements in range [0, 2] by 1

    // Apply updates and reconstruct the array
    vector<int> updatedArr = applyUpdates(arr, diff);

    // Print updated array
    for (int x : updatedArr) {
        cout << x << " ";
    }
    return 0;
}
