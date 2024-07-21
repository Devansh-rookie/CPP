#include <bits/stdc++.h>

// void dfs(int i, unordered_map<int, vector<int>> &adj, vector<bool> &vis, stack<int> &stk) {
//     vis[i] = true;
//     for(int j: adj[i]){
//         if (!vis[j]) {
//             dfs(j , adj, vis, stk);
//         }
//     }
//     stk.push(i);
// }

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int> ans;
    unordered_map<int, vector<int>> adj;
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    queue<int> q;
    vector<int> indegree(v);
    for (int i=0;i < v;i++) {
        for (int j: adj[i]) {
            indegree[j]++;
        }
    }

    for (int j=0;j < v;j++) {
        if(indegree[j] == 0) q.push(j);
    }

    while (!q.empty()) {
        int val = q.front();
        q.pop();

        ans.push_back(val);

        for (int j : adj[val]) {
            indegree[j]--; // reduce the indegree as we are removing the prev value
            if (indegree[j] == 0) {
                q.push(j);
            }
        }

        // for (int j=0;j < v;j++) {
        //     if(indegree[j] == 0) q.push(j);
        // }
    }

    return ans;
}