#include<bits/stdc++.h>
using namespace std;
long long reverse(long long num) {
    long long original = num;
    long long reversed = 0;

    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return reversed;
}

int main(){
    long long n;
    cin >> n;
    long long L=floor(log10(n));
    long long p = pow(10, L - (1 < n && n < 1.1 * pow(10, L)));
    n -=p;
    cout<< (n * pow(10, L) + reverse(n / pow(10, n>=p)));
    return 0;
}
