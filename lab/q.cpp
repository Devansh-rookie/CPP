#include<bits/stdc++.h>
using namespace std;




int main()
{
    int t =0;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i < n;i++){
            int val;
            cin >> val;
            a[i] = val;
        }

        sort(a.begin(), a.end());
        for(int i=0;i<n-1;i++){
            a[i+1] = (a[i+1]+a[i])/2;
        }
        cout << (a[n-1]) << endl;
    }
    return 0;
}