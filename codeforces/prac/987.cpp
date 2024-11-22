#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        for(int i=0; i < n;i++){
            cin >> p[i];
        }

        for(int i=0; i < n-1;i++){
            if(std::abs(p[i+1] - p[i]) == 1 && p[i] != (i+1)) swap(p[i], p[i+1]);
        }
        bool flag = false;
        for(int i=0;i<n;i++){
            if(p[i] != i+1){
                cout << "No" << endl;
                flag = true;
                break;
            }
        }
        if(!flag) cout << "Yes" << endl;
    }
    return 0;
}