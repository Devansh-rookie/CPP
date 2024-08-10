#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> vals(n);
    int m = 0;
    for(int i=0;i < n;i++){
        cin >> vals[i];
        if(vals[i].length() > m){
            m = vals[i].length();
        }
    }
    reverse(vals.begin(), vals.end());
    vector<string>ans(m, "");
    for(int i=0; i<m;i++){
        int count =0;
        for(int j=0;j<vals.size();j++){
            if(i < vals[j].length()){
                if(count !=0){
                    for(int k=0;k < count;k++) ans[i]+="*";
                    count = 0;
                }
                ans[i] += vals[j][i];
            }
            else count++;
        }
    }
    for(int i=0;i < ans.size();i++){
        cout << ans[i] << endl;
    }
    return 0;
}