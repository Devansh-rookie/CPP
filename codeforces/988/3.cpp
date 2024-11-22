#include<bits/stdc++.h>
using namespace std;

vector<bool> sieve(int maxN) {
    vector<bool> isPrime(maxN + 1, true); // Boolean array for marking primes
    isPrime[0] = isPrime[1] = false;     // 0 and 1 are not prime

    for (int i = 2; i * i <= maxN; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxN; j += i) {
                isPrime[j] = false; // Mark multiples of i as non-prime
            }
        }
    }
    return isPrime;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> primes = sieve(4*100000 + 1);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        // vector<bool> done(n+1, false);
        vector<int> ans;
        vector<int> odd, even;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) even.push_back(i);
            else odd.push_back(i);
        }
        int oL = odd.size();
        int eL = even.size();
        int specialOdd=0, specialEven =0;
        for(int i=0;i < oL;i++){
            if(specialEven){
                break;
            }
            for(int j=0;j < eL;j++){
                if(!primes[odd[i] + even[j]]){
                    specialEven = even[j];
                    specialOdd = odd[i];
                    break;
                }
            }
        }
        if(!specialEven){
            cout<< "-1" << endl;
            continue;
        }
        for(int i=0;i < oL;i++){
            if(odd[i] != specialOdd){
                cout<< odd[i]<< " ";
            }
        }
        cout << specialOdd << " ";
        cout << specialEven << " ";
        for(int i=0;i < eL;i++){
            if(even[i] != specialEven){
                cout<< even[i]<< " ";
            }
        }
        cout << endl;
    }
   return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// vector<bool> sieve(int maxN) {
//     vector<bool> isPrime(maxN + 1, true);
//     isPrime[0] = isPrime[1] = false;
//     for (int i = 2; i * i <= maxN; i++) {
//         if (isPrime[i]) {
//             for (int j = i * i; j <= maxN; j += i) {
//                 isPrime[j] = false;
//             }
//         }
//     }
//     return isPrime;
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     // Precompute primes up to 4 * 10^5
//     int maxN = 4 * 100000;
//     vector<bool> isPrime = sieve(maxN);

//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;

//         if (n == 2) {
//             cout << "-1\n"; // No valid permutation for n = 2
//             continue;
//         }

//         vector<int> odd, even;
//         for (int i = 1; i <= n; i++) {
//             if (i % 2 == 0) even.push_back(i);
//             else odd.push_back(i);
//         }

//         vector<int> perm;
//         if (even.size() >= odd.size()) {
//             perm.insert(perm.end(), even.begin(), even.end());
//             perm.insert(perm.end(), odd.begin(), odd.end());
//         } else {
//             perm.insert(perm.end(), odd.begin(), odd.end());
//             perm.insert(perm.end(), even.begin(), even.end());
//         }

//         // Check validity of the permutation
//         bool valid = true;
//         for (int i = 1; i < n; i++) {
//             if (isPrime[perm[i] + perm[i - 1]]) {
//                 valid = false;
//                 break;
//             }
//         }

//         if (!valid) {
//             cout << "-1\n";
//         } else {
//             for (int x : perm) cout << x << " ";
//             cout << "\n";
//         }
//     }

//     return 0;
// }
