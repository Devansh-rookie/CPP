// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     unordered_map<int, int> m;
//     int q;
//     cin >> q;
//     int query, x;
//     for(int i=0;i < q;i++){
//         cin >> query>> x;
//         if(query == 1){
//             m[x]++;
//         }
//         if(query == 2){
//             m[x]--;
//             if(m[x] <= 0){
//                 m[x] = 0;
//             }
//         }
//         if(query == 3){
//             // int ans = 0;
//             // for(pair<int, int> j: m){
//             //     ans += j.second;
//             // }
//             cout << m.size() << endl;
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, int> m;
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int query;
        cin >> query;

        if (query == 1) {
            int x;
            cin >> x;
            m[x]++;
        }
        else if (query == 2) {
            int x;
            cin >> x;
            m[x]--;
            if (m[x] == 0) {
                m.erase(x);
            }
        }
        else if (query == 3) {
            cout << m.size() << endl;
        }
    }
    return 0;
}
