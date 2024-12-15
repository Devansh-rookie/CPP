#include <bits/stdc++.h>
using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] && color[i] == c) return false;
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>>& graph, int m, vector<int>& color, int v, vector<vector<int>>& ans) {
    if (v == graph.size()) {  // All vertices are colored
        ans.push_back(color);
        return true;
    }

    bool foundSolution = false;
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            foundSolution |= graphColoringUtil(graph, m, color, v + 1, ans);  // Continue to next vertex
            color[v] = 0;  // Backtrack
        }
    }
    return foundSolution;
}

bool graphColoring(vector<vector<int>>& graph, int m, vector<vector<int>>& ans) {
    vector<int> color(graph.size(), 0);
    return graphColoringUtil(graph, m, color, 0, ans);
}

int main() {
    int m = 3;
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    vector<vector<int>> ans;

    cout<< "Nodes are : " << endl;
    for(int i=0;i < graph.size();i++){
        cout << i << " ";
    }
    cout << endl;
    cout << "All the colours are : " << endl;
    cout << endl;

    if (!graphColoring(graph, m, ans) || ans.empty()) {
        cout << "No solution exists." << endl;
    } else {
        for (const vector<int>& solution : ans) {
            for (int color : solution) {
                cout << color << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
