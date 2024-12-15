#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int> >& edges, int src) {
        vector<int> dist(V, 1e8);  // Initialize distances to a large value
        dist[src] = 0;

        // Relax all edges (V - 1) times
        for (int i = 0; i < V - 1; i++) {
            for (vector<int> e : edges) {
                int u = e[0];
                int v = e[1];
                int w = e[2];
                if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                    dist[v] = w + dist[u];
                }
            }
        }

        // Check for negative-weight cycles
        for (vector<int> e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                return {-1};  // Indicating a negative-weight cycle
            }
        }

        return dist;
    }
};

// Main function to run the Bellman-Ford algorithm
int main() {
    int V, E, src;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int> > edges(E, vector<int>(3));
    cout << "Enter the edges (u v w):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cout << "Enter the source vertex: ";
    cin >> src;

    Solution solution;
    vector<int> result = solution.bellmanFord(V, edges, src);

    if (result[0] == -1) {
        cout << "Graph contains a negative weight cycle" << endl;
    } else {
        cout << "Shortest distances from source vertex " << src << ":" << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << "Vertex " << i << ": ";
            if (result[i] == 1e8)
                cout << "Unreachable" << endl;
            else
                cout << result[i] << endl;
        }
    }

    return 0;
}
