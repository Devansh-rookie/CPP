#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include<math.h>
using namespace std;

// pair<int, int>find_subarray_with_min_sum(const vector<int>& values, int required_sum) {
//     int n = values.size();
//     int current_sum = 0;
//     int start = 0;
//     for (int end = 0; end < n; ++end) {
//         current_sum += values[end];
//         while (current_sum >= required_sum) {
//             if (current_sum >= required_sum) {
//                 return {start, end};
//             }
//             current_sum -= values[start];
//             ++start;
//         }
//     }
//     return {-1, -1};
// }

vector<pair<int, int>>all_min_sum(const vector<int>& values, int required_sum) {
    vector<pair<int, int>> result;
    int n = values.size();
    int current_sum = 0;
    int start = 0;
    for (int end = 0; end < n; ++end) {
        current_sum += values[end];
        while (current_sum>=required_sum) {
            result.push_back({start, end});
            current_sum -= values[start];
            ++start;
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n),b(n),c(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        for (int i = 0; i < n; ++i) cin>>b[i];
        for (int i = 0; i < n; ++i) cin>>c[i];
        int total = accumulate(a.begin(), a.end(), 0);
        int by3 = ceil((total) / 3);
        auto alice_slices = all_min_sum(a, by3);
        auto bob_slices = all_min_sum(b, by3);
        auto charlie_slices = all_min_sum(c, by3);
        bool found = false;

        for (const auto& [la, ra] : alice_slices) {
            for (const auto& [lb, rb] : bob_slices) {
                if (rb < la||lb >ra) {
                    for (const auto& [lc, rc] : charlie_slices) {
                        if ((rc < la || lc > ra) && (rc < lb || lc > rb)) {
                            cout << la + 1 << " " << ra + 1 << " " << lb + 1 << " " << rb + 1 << " " << lc + 1 << " " << rc + 1 << endl;
                            found = true;
                            break;
                        }
                    }
                }
                if (found) break;
            }
            if (found) break;
        }
        if (!found) {
            cout << -1 << endl;
        }
    }

    return 0;
}
