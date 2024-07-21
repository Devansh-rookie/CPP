#include <bits/stdc++.h>

void dfs(int i, unordered_map<int, vector<int>> &adj, vector<bool> &vis, stack<int> &stk) {
    vis[i] = true;
    for(int j: adj[i]){
        if (!vis[j]) {
            dfs(j , adj, vis, stk);
        }
    }
    stk.push(i);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int> ans;
    unordered_map<int, vector<int>> adj;
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    vector<bool> vis(v);
    stack<int> stk;
    for(int i=0;i<v;i++){
        if (!vis[i]) {
            dfs(i , adj, vis, stk);
        }
    }
    while (!stk.empty()) {
        ans.push_back(stk.top());
        stk.pop();
    }
    return ans;
}