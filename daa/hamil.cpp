#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &adj, int node,int i, vector<int> &ansnode){
    for(int j: ansnode){
        if(i == j) return false;
    }
    return true;
}

void solve(vector<vector<int>> &adj, int node, vector<int> &ansnode){
    int V = adj.size();
    if(ansnode.size() == V){
        bool flag = false;
        for(int i: adj[node]){
            if(i == ansnode[0])flag = true;
        }
        if(!flag) return;
        for(int i: ansnode){
            cout << i << ' ';
        }
        cout << ansnode[0];
        cout << endl;
    }

    for(int i: adj[node]){
        if(isSafe(adj, node, i, ansnode)){
            ansnode.push_back(i);
            solve(adj, i, ansnode);
            ansnode.pop_back();
        }
    }
}

int main()
{
    // start node has to remain the same as they can be part of the same cycle

    int V, E;
    cout << "Number of Vertex and Edges: ";
    cin >> V >> E;

    cout << "Give the Edges Undirected here\n"; 
    vector<vector<int>> adj(V);
    for(int i=0;i < E;i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // 4 4 0 1 1 2 2 3 3 0
    int node = 0;
    vector<int> ansnode;
    ansnode.push_back(node);
    solve(adj, node, ansnode);
    return 0;
}