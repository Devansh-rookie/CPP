#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for(int i=0; i < n;i++){
            cin >> arr[i];
        }
        int last = arr[0];
        int ans = 0;
        int i = 0;
        unordered_map<int, int> m;
        for(i=0;i < n;i++){
            m[arr[i]]++;
        }
        int maxx = 0;
        for(auto it: m){
            maxx = max(maxx, it.second);
        }
        ans = n - maxx;
        cout << ans << endl;
    }
    return 0;
}