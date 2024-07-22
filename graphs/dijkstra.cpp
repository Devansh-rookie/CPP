#include <bits/stdc++.h>

// bool mycomp(pair<int, int>a, pair<int, int>b) {
//     return a.second > b.second;
// }
struct mycomp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        return a.second > b.second;
    }
};
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int, vector<pair<int, int>>> adj;
    for (int i=0;i < vec.size();i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int weight = vec[i][2];

        adj[u].emplace_back(v, weight);
        adj[v].emplace_back(u, weight);//undirected graph
    }

    priority_queue<pair<int, int>,vector<pair<int, int>> ,mycomp>pq;
    int src = source;
    // node, dist here
    vector<bool> processed(vertices, false);
    pq.push({src, 0});
    vector<int> ans(vertices, INT_MAX);
    ans[source] = 0;
    while (!pq.empty()) {
        pair<int, int> val = pq.top();
        pq.pop();

        if(processed[val.first]) continue;
        processed[val.first] = true;
        for (auto &i : adj[val.first]) {
          if (ans[val.first] + i.second < ans[i.first]) {
              ans[i.first] = ans[val.first] + i.second;
              pq.push({i.first, ans[i.first]});
          }
        }
    }
    return ans;
}
