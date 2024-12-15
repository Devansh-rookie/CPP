#include <iostream>
using namespace std;
using ll = long long;

const ll MOD = 998244353;

// Function to compute x^y % MOD using binary exponentiation
ll mod_pow(ll x, ll y, ll mod) {
    ll res = 1;
    while (y > 0) {
        if (y % 2 == 1)
            res = res * x % mod;
        x = x * x % mod;
        y /= 2;
    }
    return res;
}

// Function to compute modular inverse using Fermat's Little Theorem
ll mod_inverse(ll x, ll mod) {
    return mod_pow(x, mod - 2, mod);
}

// Function to compute the expected number of days
ll expected_days(ll W, ll G, ll L) {
    if (L == 0) {
        // If L = 0, we can only lose weight every day
        return (W - G) % MOD;
    }

    // Probabilistic geometric series for random walk
    // Expected number of days = 2 * (W - G + 1)
    ll numerator = 2 * (W - G + 1) % MOD;
    return numerator % MOD;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        ll W, G, L;
        cin >> W >> G >> L;
        ll result = expected_days(W, G, L);
        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}
