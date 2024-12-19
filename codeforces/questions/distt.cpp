#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for(int i=0;i < n;i++){
        cin >> x[i];
    }
    for(int i=0;i < n;i++){
        cin >> y[i];
    }

    long long ans = 0;

    for(int i=0;i < n;i++){
        for(int j=i+1;j<n;j++){
            ans = std::max(ans, (long long)(x[j] - x[i])*(x[j] - x[i]) + (y[j] - y[i])*(y[j] - y[i]));
        }
    }
    cout << ans << "\n";
    return 0;
}