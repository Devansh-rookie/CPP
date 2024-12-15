// // #include<bits/stdc++.h>
// // using namespace std;
// // int main()
// // {
// //     int t;
// //     int n, a, b;
// //     cin >> t;

// //     while(t--){
// //         cin >> n >> a>>b;

// //         string s;
// //         cin >> s;
// //         int x0 = 0, y0 = 0;
// //         bool flag = false;
// //             for(char c : s){
// //                 if(c == 'N'){
// //                     y0++;
// //                 }
// //                 else if(c == 'E') x0++;
// //                 else if(c == 'S') y0--;
// //                 else if(c == 'W') x0--;

// //                 if(x0 == a && y0 == b){
// //                     flag = true;
// //                     cout << "Yes" << endl;
// //                     break;
// //                 }
// //             }
// //             if(x0 == 0 && y0 == 0){ cout << "No" << endl; continue;}
        
// //         for(int i=0;i < 1;i++){
// //             if(flag) break;
// //             for(char c : s){
// //                 if(c == 'N'){
// //                     y0++;
// //                 }
// //                 else if(c == 'E') x0++;
// //                 else if(c == 'S') y0--;
// //                 else if(c == 'W') x0--;

// //                 if(x0*b == y0*a){
// //                     flag = true;
// //                     cout << "Yes" << endl;
// //                     break;
// //                 }
// //             }
// //         }
// //         if(!flag)cout << "NO" << endl;
// //     }
// //    return 0;
// // }
// // // #include <bits/stdc++.h>
// // // using namespace std;

// // // int main() {
// // //     int t;
// // //     cin >> t;

// // //     while (t--) {
// // //         int n, a, b;
// // //         cin >> n >> a >> b;
// // //         string s;
// // //         cin >> s;

// // //         int x0 = 0, y0 = 0; // Alice's starting position
// // //         bool found = false;
// // //         set<pair<int, int> > visited; // To keep track of positions visited by Alice

// // //         for (int i = 0; i < 100; i++) { // Arbitrarily chosen large number of repetitions
// // //             for (char c : s) {
// // //                 if (c == 'N') y0++;
// // //                 else if (c == 'E') x0++;
// // //                 else if (c == 'S') y0--;
// // //                 else if (c == 'W') x0--;

// // //                 if (x0 == a && y0 == b) {
// // //                     cout << "YES" << endl;
// // //                     found = true;
// // //                     break;
// // //                 }
                
// // //                 // Use make_pair instead of {} for older C++ standards
// // //                 if (visited.count(make_pair(x0, y0))) {
// // //                     cout << "NO" << endl;
// // //                     found = true;
// // //                     break;
// // //                 }
// // //                 visited.insert(make_pair(x0, y0));
// // //             }
// // //             if (found) break;
// // //         }

// // //         if (!found) cout << "NO" << endl;
// // //     }
// // //     return 0;
// // // }


// #include <bits/stdc++.h>
// using namespace std;

// vector<long long> solve(int t, vector<tuple<long long, long long, long long>>& test_cases) {
//     vector<long long> results;
//     for (int i = 0; i < t; ++i) {
//         long long n, b, c;
//         tie(n, b, c) = test_cases[i];
        
//         // Case 1: If b == 0, all elements are the same, a[i] = c.
//         if (b == 0) {
//             if (c >= 0 && c < n) {
//                 results.push_back(0);  // Already a permutation of [0, ..., n-1]
//             } else {
//                 results.push_back(-1); // Impossible to form a permutation
//             }
//             continue;
//         }
        
//         // Case 2: Calculate the range of the arithmetic progression
//         long long min_val = c;
//         long long max_val = c + (n - 1) * b;
        
//         if (min_val > max_val) swap(min_val, max_val); // Ensure min_val <= max_val
        
//         // Check if the range covers all values from 0 to n-1
//         if (min_val <= 0 && max_val >= n - 1) {
//             results.push_back(0);  // Already a permutation
//         } else {
//             // Case 3: Calculate the number of operations
//             // Since b is positive and large range, the number of replacements
//             // equals to the length of the array `n`
//             results.push_back(n); // Number of required operations to form the permutation
//         }
//     }
//     return results;
// }

// int main() {
//     int t;
//     cin >> t;
//     vector<tuple<long long, long long, long long>> test_cases(t);
    
//     for (int i = 0; i < t; ++i) {
//         long long n, b, c;
//         cin >> n >> b >> c;
//         test_cases[i] = make_tuple(n, b, c);
//     }
    
//     vector<long long> results = solve(t, test_cases);
    
//     for (long long res : results) {
//         cout << res << endl;
//     }
    
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

vector<long long> solve(int t, vector<tuple<long long, long long, long long> >& test_cases) {
    vector<long long> results;
    for (int i = 0; i < t; ++i) {
        long long n, b, c;
        tie(n, b, c) = test_cases[i];
        
        // Case 1: If b == 0, all elements are the same, a[i] = c.
        if (b == 0) {
            if (c >= 0 && c < n) {
                results.push_back(0);  // Already a permutation of [0, ..., n-1]
            } else {
                results.push_back(-1); // Impossible to form a permutation
            }
            continue;
        }
        
        // Case 2: Calculate the range of the arithmetic progression
        long long min_val = c;
        long long max_val = c + (n - 1) * b;
        
        if (min_val > max_val) swap(min_val, max_val); // Ensure min_val <= max_val
        
        // Check if the range covers all values from 0 to n-1
        if (min_val <= 0 && max_val >= n - 1) {
            results.push_back(0);  // Already a permutation
        } else {
            // Case 3: Calculate the number of operations
            results.push_back(n); // Number of required operations to form the permutation
        }
    }
    return results;
}

int main() {
    int t;
    cin >> t;
    vector<tuple<long long, long long, long long> > test_cases(t);
    
    for (int i = 0; i < t; ++i) {
        long long n, b, c;
        cin >> n >> b >> c;
        test_cases[i] = make_tuple(n, b, c);
    }
    
    vector<long long> results = solve(t, test_cases);
    
    for (long long res : results) {
        cout << res << endl;
    }
    
    return 0;
}
