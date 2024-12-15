// // #include <iostream>
// // #include<unordered_set>
// // #include <fstream>
// // #include <sstream>
// // #include <iomanip>
// // #include <string>  
// // #include <vector>
// // #include <list>        
// // #include <set> 
// // #include <map>    
// // #include <queue> 
// // #include <stack>
// // #include <algorithm>  
// // #include <cmath> 
// // #include <ctime> 
// // #include <cstdlib>
// // #include <cstring> 
// // #include <cctype> 
// // #include <cassert>
// // #include <exception>   
// // #include <functional>
// // #include <iterator>
// // #include <limits>  
// // #include <locale>   
// // #include <numeric>  
// // #include <random> 
// // #include <stdexcept> 
// // #include <typeinfo> 
// // #include <utility>
// // using namespace std;

// // void SieveOfEratosthenes(int n)
// // {
// //     // unordered_map<int, bool> prime;
// //     vector<int> prime(n+1, true);
// //     for (int p = 2; p * p <= n; p++) {
// //         if (prime[p] == true) {
// //             for (int i = p * p; i <= n; i += p)
// //                 prime[i] = false;
// //         }
// //     }

// //     // Print all prime numbers
// //     // unordered_map<int, int> m;
    
// //     int c = 0;
// //     vector<int> vals;
// //     for (int p = 2; p <= n; p++){
// //         if (prime[p]){
// //             // cout << p << " ";
// //             // m[p] = c;
// //             vals.push_back(p);
// //             c++;
// //         }
// //     }
// //     // cout << vals[3];
// //     vector<int> ans;
// //     // prime.resize(n+1, false);
// //     unordered_set<int> s;
// //     int countt = 0;
// //     for(int i = vals.size() - 1;i > 0;i--){
// //         for(int j = i - 1;j>=0;j--){
// //             int v = vals[i] - vals[j];
// //             if(prime[v] && s.find(v) == s.end() && v >1){
// //                 s.insert(v);
// //                 // ans.push_back(v);
// //                 countt++;
// //             }
// //         }
// //     }

// //     // for(int i = 0;i < ans.size();i++){
// //     //     cout << ans[i] << " ";
// //     // }
// //     cout << countt << endl;
// // }

// // int main()
// // {
// //     int t;
// //     cin >> t;
// //     while(t--){
// //         int in;
// //         cin >> in;
// //         SieveOfEratosthenes(in);
// //     }
// //     return 0;
// // }

// // #include <iostream>
// // #include <unordered_set>
// // #include <fstream>
// // #include <vector>

// // using namespace std;

// // void SieveOfEratosthenes(int n, ofstream &outfile)
// // {
// //     vector<int> prime(n+1, true);
// //     for (int p = 2; p * p <= n; p++) {
// //         if (prime[p] == true) {
// //             for (int i = p * p; i <= n; i += p)
// //                 prime[i] = false;
// //         }
// //     }

// //     vector<int> vals;
// //     for (int p = 2; p <= n; p++) {
// //         if (prime[p]) {
// //             vals.push_back(p);
// //         }
// //     }

// //     unordered_set<int> s;
// //     int countt = 0;
// //     for(int i = vals.size() - 1; i > 0; i--) {
// //         for(int j = i - 1; j >= 0; j--) {
// //             int v = vals[i] - vals[j];
// //             if(prime[v] && s.find(v) == s.end() && v > 1) {
// //                 s.insert(v);
// //                 countt++;
// //             }
// //         }
// //     }
// //     // Write the result to the output file
// //     outfile << countt << endl;
// // }

// // int main()
// // {
// //     // Open input and output files
// //     ifstream infile("prime_subtractorization_validation_input.txt");
// //     ofstream outfile("output.txt");

// //     // Check if files are successfully opened
// //     if (!infile.is_open() || !outfile.is_open()) {
// //         cerr << "Error opening file!" << endl;
// //         return 1;
// //     }

// //     int t;
// //     infile >> t;  // Read number of test cases
// //     while (t--) {
// //         int in;
// //         infile >> in;  // Read each input value
// //         SieveOfEratosthenes(in, outfile);  // Call the function and pass the output file stream
// //     }

// //     // Close the files
// //     infile.close();
// //     outfile.close();

// //     return 0;
// // }


// #include <iostream>
// #include <vector>
// #include <unordered_set>
// using namespace std;

// // Function to generate primes up to maxN using Sieve of Eratosthenes
// vector<bool> sieveOfEratosthenes(int maxN) {
//     vector<bool> is_prime(maxN + 1, true);
//     is_prime[0] = is_prime[1] = false;
//     for (int p = 2; p * p <= maxN; p++) {
//         if (is_prime[p]) {
//             for (int i = p * p; i <= maxN; i += p)
//                 is_prime[i] = false;
//         }
//     }
//     return is_prime;
// }

// int main() {
//     // Define the maximum N we need to handle
//     const int MAX_N = 10000000;

//     // Precompute primes up to MAX_N
//     vector<bool> is_prime = sieveOfEratosthenes(MAX_N);
    
//     // Create a list of primes for easier access
//     vector<int> primes;
//     for (int i = 2; i <= MAX_N; i++) {
//         if (is_prime[i]) primes.push_back(i);
//     }

//     // Precompute the number of N-subtractorizations for all N <= MAX_N
//     vector<int> subtractorizations(MAX_N + 1, 0);
//     unordered_set<int> prime_set(primes.begin(), primes.end());

//     for (int i = 2; i <= MAX_N; i++) {
//         int count = 0;
//         for (int p : primes) {
//             if (p > i) break;
//             int diff = i - p;
//             if (prime_set.count(diff)) {
//                 count++;
//             }
//         }
//         subtractorizations[i] = count;
//     }

//     // Process input and handle multiple test cases
//     int T;
//     cin >> T;
//     for (int t = 1; t <= T; t++) {
//         int N;
//         cin >> N;
//         cout << "Case #" << t << ": " << subtractorizations[N] << endl;
//     }

//     return 0;
// }


#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream>

using namespace std;

// Function to generate primes up to maxN using Sieve of Eratosthenes
vector<bool> sieveOfEratosthenes(int maxN) {
    vector<bool> is_prime(maxN + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= maxN; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= maxN; i += p)
                is_prime[i] = false;
        }
    }
    return is_prime;
}

int main() {
    // Define the maximum N we need to handle
    const int MAX_N = 10000000;

    // Precompute primes up to MAX_N
    vector<bool> is_prime = sieveOfEratosthenes(MAX_N);
    
    // Create a list of primes for easier access
    vector<int> primes;
    for (int i = 2; i <= MAX_N; i++) {
        if (is_prime[i]) primes.push_back(i);
    }

    // Precompute the number of N-subtractorizations for all N <= MAX_N
    vector<int> subtractorizations(MAX_N + 1, 0);
    unordered_set<int> prime_set(primes.begin(), primes.end());

    for (int i = 2; i <= MAX_N; i++) {
        int count = 0;
        for (int p : primes) {
            if (p > i) break;
            int diff = i - p;
            if (prime_set.count(diff)) {
                count++;
            }
        }
        subtractorizations[i] = count;
    }

    // Open input and output files
    ifstream infile("prime_subtractorization_validation_input.txt");
    ofstream outfile("output.txt");

    // Check if files are successfully opened
    if (!infile.is_open() || !outfile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Process input from the file and handle multiple test cases
    int T;
    infile >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        infile >> N;  // Read N from the file
        outfile << "Case #" << t << ": " << subtractorizations[N] << endl;  // Write the result to the output file
    }

    // Close the files
    infile.close();
    outfile.close();

    return 0;
}


// #include <iostream>
// #include <vector>
// #include <unordered_set>
// #include <fstream>

// using namespace std;

// // Function to generate primes up to maxN using Sieve of Eratosthenes
// vector<bool> sieveOfEratosthenes(int maxN) {
//     vector<bool> is_prime(maxN + 1, true);
//     is_prime[0] = is_prime[1] = false;
//     for (int p = 2; p * p <= maxN; p++) {
//         if (is_prime[p]) {
//             for (int i = p * p; i <= maxN; i += p)
//                 is_prime[i] = false;
//         }
//     }
//     return is_prime;
// }

// int main() {
//     // Define the maximum N we need to handle
//     const int MAX_N = 10000000;

//     // Precompute primes up to MAX_N
//     vector<bool> is_prime = sieveOfEratosthenes(MAX_N);
    
//     // Create a list of primes for easier access
//     vector<int> primes;
//     for (int i = 2; i <= MAX_N; i++) {
//         if (is_prime[i]) primes.push_back(i);
//     }

//     // Precompute the number of N-subtractorizations for all N <= MAX_N
//     vector<int> subtractorizations(MAX_N + 1, 0);
//     unordered_set<int> prime_set(primes.begin(), primes.end());

//     // Two-pointer method to efficiently count N-subtractorizations
//     for (int i = 0; i < primes.size(); i++) {
//         for (int j = i; j < primes.size(); j++) {
//             int diff = primes[j] - primes[i];
//             if (diff > MAX_N) break; // No point in continuing if the difference exceeds MAX_N
//             subtractorizations[diff]++;
//         }
//     }

//     // Open input and output files
//     ifstream infile("prime_subtractorization_validation_input.txt");
//     ofstream outfile("output.txt");

//     // Check if files are successfully opened
//     if (!infile.is_open() || !outfile.is_open()) {
//         cerr << "Error opening file!" << endl;
//         return 1;
//     }

//     // Process input from the file and handle multiple test cases
//     int T;
//     infile >> T;
//     for (int t = 1; t <= T; t++) {
//         int N;
//         infile >> N;  // Read N from the file
//         outfile << "Case #" << t << ": " << subtractorizations[N] << endl;  // Write the result to the output file
//     }

//     // Close the files
//     infile.close();
//     outfile.close();

//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <unordered_map>

// using namespace std;

// // Function to calculate the count of N-subtractorizations
// int CountNSubtractorizations(int n) {
//     vector<bool> is_prime(n+1, true);
//     vector<int> primes;
//     unordered_map<int, int> prime_indices;

//     // Sieve of Eratosthenes to find prime numbers up to n
//     for (int p = 2; p*p <= n; p++) {
//         if (is_prime[p]) {
//             for (int i = p*p; i <= n; i += p) {
//                 is_prime[i] = false;
//             }
//         }
//     }

//     for (int p = 2; p <= n; p++) {
//         if (is_prime[p]) {
//             primes.push_back(p);
//             prime_indices[p] = primes.size() - 1;
//         }
//     }

//     int count = 0;
//     for (int i = 0; i < primes.size(); i++) {
//         for (int j = i; j < primes.size(); j++) {
//             int diff = primes[j] - primes[i];
//             if (diff > n) break;
//             if (is_prime[diff]) {
//                 count++;
//             }
//         }
//     }

//     return count;
// }

// int main() {
//     int T;
//     cin >> T;

//     for (int t = 1; t <= T; t++) {
//         int N;
//         cin >> N;
//         int result = CountNSubtractorizations(N);
//         cout << "Case #" << t << ": " << result << endl;
//     }

//     return 0;
// }