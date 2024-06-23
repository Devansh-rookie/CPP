//all the header files included here
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
template <typename T>


class graph{
public:
    // adjacency list
    unordered_map<T, list<T>> adj; // int is the data type we are using otherwise just use the template type
    
    void addNode(T node1, T node2, bool direction){// node1 is connected to node2 by default 1->2 if directed graph else both are connected to each other obviously
        adj[node1].push_back(node2);
        if(direction == false){
            adj[node2].push_back(node1);
        }
    }

    void printAdjList(){
        cout<<endl;
        for(auto i: adj){
            cout<< i.first<<" -> ";
            for(auto j: i.second){
                cout<< j << ", ";
            }
            cout<< endl;
        }
        cout<< endl;
    }

    void undirectedBfs(T vertex){// bfs is to be started from this node
        unordered_map<T, bool> visited;// or use bool here
        queue<T> q;
        cout << endl;
        q.push(vertex);
        while(!q.empty()){
            T currVal = q.front();
            q.pop();
            // if not visited
            if(!visited[currVal]){
                for(auto i: adj[currVal]){
                    if(!visited[i]){
                        q.push(i);
                    }
                }
                cout << currVal << " ";
                visited[currVal] = true;
            }
        }
        cout<< endl;
    }
};


int main()
{
    // e.g. 5 4 0 3 1 3 1 4 1 2
    // we need sorted way then use set instead and use insert instead of pushback thats all
    graph<int> g;
    int n,m;
    cout << "Give the number of nodes and edges: ";
    cin >> n >> m;
    // single nodes means 1 edge as well in this scenario
    for(int i=0;i< m;i++){
        int node1, node2;
        cout << "From where to where:";
        cin>>node1 >> node2;
        g.addNode(node1, node2, 0);// undirected graph
    }
    g.printAdjList();
    // g.undirectedBfs(3);
    // g.undirectedBfs(0);
    int nVertex;
    cout << "number of vertex for BFS: ";
    cin >> nVertex;
    vector<int> arr(nVertex);
    cout << "Give all the vertex: ";
    int x;
    // useful to print multiple components of the graph
    for(int i=0;i < nVertex;i++){
        cin >> x;
        arr[i] = x;
    }
    for(auto vertex: arr){
        g.undirectedBfs(vertex);
    }
    return 0;
}