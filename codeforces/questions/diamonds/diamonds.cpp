#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Error: Unable to open file(s)." << endl;
        return 1;
    }
    int n, k;
    fin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i < n;i++){
        fin >> arr[i];
    }
    int ans = 0;
    sort(arr.begin(), arr.end());
    for(int i=0;i < n;i++){
        int temp = 0;
        for(int j = i+1;j < n;j++){
            if(arr[j] - arr[i] <= k){
                temp++;
            }
        }
        ans = max(temp, ans);
    }
    fout << ans+1;
    return 0;
}