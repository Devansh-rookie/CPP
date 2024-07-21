#include <bits/stdc++.h>
// #include <unordered_map>
// #include <vector>
// #include <queue>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  // first use Kahn's algo to find the TS if its correct that means the length is equal to the number of nodes it is fine else it is not

  queue<int>q;
  // vector<int> ans;
  int c = 0;
  vector<int> indegree(n,0);
  unordered_map<int, vector<int>> adj;
  for (int i=0;i < edges.size();i++) {
    int u = edges[i].first-1;
    int v = edges[i].second-1;
    adj[u].push_back(v);
  }

  for (int i=0;i< n;i++) {
    for (int j: adj[i]) {
      indegree[j]++;
    }
  }

  for(int i=0;i<n;i++){
    if(indegree[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    int front = q.front();
    q.pop();

    // ans.push_back(front);
    c++;

    for (int i: adj[front]) {
      indegree[i]--;
      if(indegree[i] == 0) q.push(i);
    }
  }

  if(c == n) return false;// its a DAG, cycle is not preset
  return true;
}