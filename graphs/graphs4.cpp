//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int val, unordered_map<int, bool> &visi, vector<int> adj[]){
        queue<int> q;
        unordered_map<int, int> parent;// bappu ji
        parent[val] = -1;
        visi[val] = true;
        q.push(val);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(int &num : adj[temp]){
                if(visi[num] && parent[temp] != num){
                    return true;
                }
                else if(!visi[num]){
                    q.push(num);
                    visi[num] = true;
                    parent[num] = temp;
                }
            }
        }
        return false;
    }
    
    bool dfs(int val, int parent,unordered_map<int, bool> &visi, vector<int> adj[]){
        visi[val] = true;
        for(int &num: adj[val]){
            if(!visi[num]){
                bool ans = dfs(num, val, visi, adj);
                if(ans) return true;
            }
            else if(num != parent){
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int, bool> visi; // visited values
        
        // adjacency list is adj here
        bool ans = false;
        // for(int i=0;i<V;i++){
        //     if(!visi[i]){
        //         ans = bfs(i, visi, adj);
        //     }
        //     if(ans) return true;
        // }
        for(int i=0;i<V;i++){
            if(!visi[i]){
                ans = dfs(i,-1 ,visi, adj);
            }
            if(ans) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends



class DSU{
public:
    vector<int>rank;
    vector<int>sizee;
    vector<int> par;
    DSU(int n){
        rank.resize(n, 0);
        sizee.resize(n, 1);
        for(int i=0;i < n;i++){
            par.push_back(i);
        }
    }
    
    int u_par(int node){
        if(node == par[node]) return node;
        return par[node] = u_par(par[node]); // path compression
    }
    
    void union_rank(int u, int v){
        int par_u = u_par(u);
        int par_v = u_par(v);
        if(par_u == par_v) return;
        else if(rank[par_u] > rank[par_v]){
            par[par_v] = par_u;
        }
        else if(rank[par_u] < rank[par_v]){
            par[par_u] = par_v;
        }
        else{
            par[par_v] = par_u; 
            rank[par_u]++;
        }
    }
    
    void union_size(int u, int v){
        int par_u = u_par(u);
        int par_v = u_par(v);
        
        if(par_u == par_v) return;
        else if(sizee[par_u] > sizee[par_v]){
            par[par_v] = par_u;
            sizee[par_u] += sizee[par_v];
        }
        else {
            par[par_u] = par_v;
            sizee[par_v] += sizee[par_u];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // // here we have a pq with dist, node
        
        // pq.push({0, 0});
        // vector<bool> vis(V, false);
        // int ans = 0;
        // while(!pq.empty()){
        //     int d = pq.top()[0];
        //     int node = pq.top()[1];
        //     pq.pop();
            
        //     if(vis[node]) continue;
        //     vis[node] = true;
        //     ans += d; // here we can add the edge as well
        //     for(auto i: adj[node]){
        //         if(!vis[i[0]]){
        //           pq.push({i[1], i[0]}); 
        //         }
        //     }
        // }
        // return ans;
        
        int ans = 0;
        vector<vector<int>> e;
        
        for(int i=0;i< V;i++){
            for(vector<int> j: adj[i]){
                e.push_back({j[1],i,j[0]});   
            }
        }
        
        sort(e.begin(), e.end());
        
        DSU dset(V);
        
        for(int i=0;i < e.size();i++){
            if(dset.u_par(e[i][1]) != dset.u_par(e[i][2])){
                ans += e[i][0];
                dset.union_rank(e[i][1], e[i][2]);
            }
        }
        
        return ans;
    }
};