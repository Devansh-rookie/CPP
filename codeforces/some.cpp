// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int t;
//     cin  >> t;
//     while(t--){
//         vector<int> arr;
//         int n;
//         cin >> n;
//         while(n--){
//             int val;
//             cin >> val;
//             arr.push_back(val);
//         }
//         n = arr.size();
//         if(arr.size() == 2){
//             cout << arr[n-1] - arr[n-2]<<endl;
//         }
//         else{
//             // sub from n-2 and then n-1 make n-2 one the most negative and the basically add its abs to that
//             long long suma = 0;
//             for(int i=0;i < n-2;i++){
//                 suma += arr[i];
//             }
//             cout << arr[n-1] - (arr[n-2] - suma)<<endl;
//         }
//     }
//    return 0;
// }

#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n, m, q;
    cin >> n >> m >> q;
    vector<long long> teach(m,0);
    for(int i=0;i < m;i++){
        cin >> teach[i];
    }
    sort(teach.begin(), teach.end());
    long long david = 0;
    cin >> david;
    if(david > teach[0] && david < teach[1]){
        int val = abs((teach[0] - teach[1])/2);
        cout << val << endl;
        // else cout << val+1 << endl;
    }
    else{
        if(david>teach[1]){
            cout << n - teach[1]<<endl;
        }
        else if(teach[0] - david > 0){
            cout <<  teach[0] - david<<endl;
        }
    }
}

void solve2010C1(){
    string s;
    cin >> s;
    string sub = s;
    bool flag = false;
    string ans;
    for(int i= s.length() - 1;i>=0;i--){
        string check = s;
        int j = 0;
        while(j < s.length()){
            for(int k=0;k < j;k++){
                if(check.substr(j, k) == sub && sub != s){
                    flag = true;
                    ans = sub;
                }
            }
            j++;
        }
        if(flag) break;
        sub = sub.substr(0,sub.length() - 1);
    }
    if(flag && s.length()/2 < ans.length()+1){
        cout << "YES" <<endl << ans<<endl;
    }
    else cout << "NO" << endl;
}

int main()
{
    // int t;
    // cin >> t;
    // while(t--){
    // }
    solve2010C1();
   return 0;
}