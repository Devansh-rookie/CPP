#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>  
#include <vector>
#include <list>        
#include <set> 
#include <map>    
#include <queue> 
#include <stack>
#include <algorithm>  
#include <cmath> 
#include <ctime> 
#include <cstdlib>
#include <cstring> 
#include <cctype> 
#include <cassert>
#include <exception>   
#include <functional>
#include <iterator>
#include <limits>  
#include <locale>   
#include <numeric>  
#include <random> 
#include <stdexcept> 
#include <typeinfo> 
#include <utility>
using namespace std;

int main()
{

    return 0;
}


void dfs(int node, unordered_map<int, bool> &visited, vector<int> &ansnode, unordered_map<int , list<int>> &adj) {
    ansnode.push_back(node);
    visited[node] = true;
    for (auto i: adj[node]) {
      if (!visited[i]) {
// dfs for each node until every thing is visited or other componenets like unjoined components are left
          dfs(i, visited, ansnode, adj);
      }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int , list<int>> adj;
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;
    for(int i=0;i< edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
// dfs for each node until every thing is visited or other componenets like unjoined components are left
// this part (for loop) is to check and completely traverse all the components of the graph
    for(int i=0;i< V;i++){
        if (!visited[i]) {
            vector<int> ansnode;
            dfs(i, visited, ansnode, adj);
            ans.push_back(ansnode);
        }
    }
    return ans;
}