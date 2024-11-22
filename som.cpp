#include<bits/stdc++.h>
using namespace std;
// long getReq(vector<int> server, vector<int> incoming, int k){
//     vector<vector<int>> diff;
//     priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
//     for(int i=0; i < server.size();i++){
//         diff.push_back({- incoming[i] + server[i], i});
//         pq.push({- incoming[i] + server[i], i});
//     }
//     while(!pq.empty() && k > 0){
//         k--;
//         int index = pq.top()[1];
//         server[index] = server[index]*2; //long
//         pq.pop();
//     }
//     long ans = 0;
//     for(int i=0;i<server.size();i++){
//         if(server[i] >= incoming[i]){
//             ans += incoming[i];
//         }
//         else{
//             ans += server[i];
//         }
//     }
//     return ans;
// }

// int main()
// {
//     vector<int> server = {10, 4, 3, 7};
//     vector<int> incoming = {3, 10, 4, 5};

//     cout << getReq(server, incoming, 2);
//     return 0;
// }

int findCount(int gn,vector<int>from,vector<int>to,vector<int>wt,int minDist,vector<int>company) {
    int ans = 0;
    vector<vector<pair<int,int>>>g;
    vector<vector<int>>comp(11);
    for(int i = 0 ; i < gn ; i++) {
        int f = from[i];
        int t = to[i];
        int w = wt[i];
        g[f].push_back({t,w});
        comp[company[i]].push_back(i);
    }

    vector<int>dist(gn,1e9);
    vector<vector<int>>floyd(gn,vector<int>(gn,1e9));
    for(int i = 0 ; i < gn ; i++) {
        floyd[i][i] = 0;
    }
    for(int i = 0 ; i < gn ; i++) {
        for(int j = 0 ; j < gn ; j++) {
            for(int k = 0 ; k < gn ; k++) {
                floyd[i][j] = min(floyd[i][j],floyd[i][k] + floyd[k][j]);
            }
        }
    }

    return ans;
}