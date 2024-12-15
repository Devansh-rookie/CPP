#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,a;
    cin >> n >> t>>a;
    int maxi = n/2 + 1;
    if(max(t, a) >= maxi){
        cout << "Yes";
    }
    else cout << "No";
    return 0;
}