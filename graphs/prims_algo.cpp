#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    // first make the adjacecy list
    unordered_map<int, list<pair<int, int>>> adj; // the pair is the representation of node and weight
    // Use Prim's algorithm
    for (int i=0;i < m;i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(n+1, INT_MAX);
    vector<int> parent(n+1, -1);
    vector<bool> mst(n+1, false);

    int source = 1;
    dist[source] = 0;

    for (int i=0;i<n-1;i++) {// run it one less than n
        int node = -1;
        int minimum = INT_MAX;

        for(int j=1;j<=n;j++){// check for the smallest value
            if (minimum > dist[j] && mst[j] == false) {
                minimum = dist[j];
                node = j;
            }
        }
        if(node == -1) break;
        mst[node] = true;

        for (auto &k: adj[node]) {
            int v = k.first;
            int w = k.second;
            if (!mst[v] && dist[v] >w) {
                dist[v] = w;
                parent[v] = node;
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
        for (int i=2;i<=n;i++) {// since 1 has different stuff
            int v = i;
            int u = parent[i];
            int distance = dist[i];

            if(u!=-1)ans.push_back({{u,v},distance});
        }
    return ans;
}
