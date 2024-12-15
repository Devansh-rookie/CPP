#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    unordered_set<int> s;
    for(int i=0;i < n-1;i++){
        int val;
        cin >> val;
        s.insert(val);
    }

    for(int i=1;i <= n;i++){
        if(s.find(i) == s.end()){
            cout << i <<endl;
            return 1;
        }
    }
    return 0;
}