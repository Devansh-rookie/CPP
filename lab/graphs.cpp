#include<bits/stdc++.h>
using namespace std;
template <typename T>

class graph{
public:
    unordered_map<T, list<T> > adj; 
    set<T>s;
    void addNode(T node1, T node2, bool direction){// node1 is connected to node2 by default 1->2 if directed graph else both are connected to each other obviously
        adj[node1].push_back(node2);
        if(direction == false){
            adj[node2].push_back(node1);
        }
        s.insert(node1);
        s.insert(node2);
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
    unordered_map<T, bool> visited;// or use bool here
    
    void bfs_helper(T vertex){// bfs is to be started from this node
        // cout << endl;
        queue<T> q;
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
        // cout<< endl;
        // visited.clear();
    }

    void bfs(){
        for(T curr : s){
            if(!visited[curr]){
                bfs_helper(curr);
            }
        }
        visited.clear();
        cout << endl;
    }



    void dfs_helper(T node){// just the starting node is required in the recursive relation
        cout << node << " ";
        visited[node] = true;
        for(auto curr : adj[node]){
            if(!visited[curr]){
                dfs_helper(curr);
            }
        }
        // cout << endl;
    }

    void dfs(){
        for(T curr : s){
            if(!visited[curr]){
                dfs_helper(curr);
            }
        }
        visited.clear();
        cout << endl;
    }
};


int main()
{

    graph<char> g;
    g.addNode('m', 'x', 1); // here start node is the first node that is m here and end is the x and since its a directed edge then direction = 1
    g.addNode('m', 'q', 1);
    g.addNode('m', 'r', 1);
    g.addNode('n', 'q', 1);
    g.addNode('n', 'u', 1);
    g.addNode('n', 'o', 1);
    g.addNode('q', 't', 1);
    g.addNode('o', 's', 1);
    g.addNode('o', 'r', 1);
    g.addNode('o', 'v', 1);
    g.addNode('v', 'w', 1);
    g.addNode('v', 'x', 1);
    g.addNode('s', 'r', 1);
    g.addNode('p', 's', 1);
    g.addNode('p', 'o', 1);
    g.addNode('p', 'z', 1);
    g.addNode('y', 'v', 1);
    g.addNode('w', 'z', 1);
    g.addNode('u', 't', 1);
    g.addNode('r', 'u', 1);
    g.addNode('r', 'y', 1);

    cout << "This is the Adjacency List of the given graph:";
    g.printAdjList();

    cout << "This is the BFS of the Graph: ";
    g.bfs();
    cout << "This is the DFS of the Graph: ";
    g.dfs();

   return 0;
}