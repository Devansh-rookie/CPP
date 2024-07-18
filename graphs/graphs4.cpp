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