#include<bits/stdc++.h>
#include<iostream>
using namespace std;
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    long long mod = 10000000;
    long long result = (mod_exp(2, n, mod) - 1 + mod) % mod; // + mod to handle negative result
    cout << result << endl;
    return 0;
}