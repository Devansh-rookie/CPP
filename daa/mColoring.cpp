#include<bits/stdc++.h>
using namespace std;

bool isSafe(int node, vector<vector<int>> &adj, vector<string> &ans, string color) {
    for (int neighbor : adj[node]) {
        if (ans[neighbor] == color) {
            return false; // Adjacent node has the same color
        }
    }
    return true;
}

// Recursive function to solve the graph coloring problem
void solve(int node, int V, vector<vector<int>> &adj, vector<string> &colors, vector<string> &ans, int m) {
    if (node == V) { // Base case: all nodes are colored
        for (int i = 0; i < V; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < m; i++) { // Try all colors for the current node
        if (isSafe(node, adj, ans, colors[i])) {
            ans[node] = colors[i]; // Assign color
            solve(node + 1, V, adj, colors, ans, m); // Recurse for the next node
            ans[node] = ""; // Backtrack
        }
    }
}


int main(){
    int m = 0;
    cout << "Number of colors: ";
    cin >> m;
    cout << "Give the Colours: ";
    vector<string> color(m);
    for(int i=0; i < m;i++){
        cin >> color[i];
    }
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
    int c = 0;
    int node = 0;
    // solve(adj, V, color, m, node, 0, ans, c+1);
    vector<string> ans(V, ""); // Initialize color assignment for each vertex
    cout << "Possible colorings:" << endl;
    solve(0, V, adj, color, ans, m);
    return 0;
}
// 0 1 0 2 0 4 1 3 1 2 2 5 2 4 3 5 4 5 2 3