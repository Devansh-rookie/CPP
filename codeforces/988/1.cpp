#include<bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while(t--){
        unordered_map<int, int>m;
        int n;
        cin >> n;
        vector<int> arr;
        for(int i=0; i <n;i++){
            int val;
            cin >> val;
            arr.push_back(val);
        }
        int ans = 0;
        unordered_set<int>s;
        for(int i=0;i < n;i++){
            for(int j=i+1;j < n;j++){
                if(arr[i] == arr[j] && s.find(j) == s.end() && s.find(i) == s.end()){
                    ans++;
                    s.insert(i);
                    s.insert(j);
                }
            }
        }
        cout << ans << endl;
    }
   return 0;
}