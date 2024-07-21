#include <bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	unordered_map<int, vector<int>> adj;
	vector<int> ans;

	for(int i=0;i < edges.size();i++){
		int u = edges[i].first;
		int v= edges[i].second;
		adj[u].push_back(v);
		// undirected
		adj[v].push_back(u);
	}
	queue<int> q;
	q.push(s);
	unordered_map<int, bool> visited;
	unordered_map<int, int> parent;
	visited[s] = true;
	parent[s] = -1;
	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(auto i : adj[front]){
			if(!visited[i]){
				q.push(i);
				visited[i] = true;
				parent[i] = front;
			}
		}
	}

	int curr = t;
	ans.push_back(t);

	while(curr != s){
		curr = parent[curr];
		ans.push_back(curr);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
