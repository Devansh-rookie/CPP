#include <iostream>     // Input/output stream objects
#include <fstream>      // File stream objects
#include <sstream>      // String stream objects
#include <iomanip>      // Input/output manipulators
#include <string>       // String class and functions
#include <vector>       // Dynamic array
#include <list>         // Doubly linked list
#include <set>          // Set container
#include <map>          // Map container
#include <queue>        // Queue container
#include <stack>        // Stack container
#include <algorithm>    // Algorithms on sequences (e.g., sort, find)
#include <cmath>        // Mathematical functions
#include <ctime>        // Date and time functions
#include <cstdlib>      // General purpose functions (e.g., memory management)
#include <cstring>      // C-style string functions
#include <cctype>       // Character classification functions
#include <cassert>      // Assert function for debugging
#include <exception>    // Standard exceptions
#include <functional>   // Function objects
#include <iterator>     // Iterator classes
#include <limits>       // Numeric limits
#include <locale>       // Localization and internationalization
#include <numeric>      // Numeric operations (e.g., accumulate)
#include <random>       // Random number generators
#include <stdexcept>    // Standard exception classes
#include <typeinfo>     // Runtime type information
#include <utility>      // Utility components (e.g., std::pair)
using namespace std;

template <typename dataT>

class graph{
public:
    unordered_map<dataT, list<dataT>> m;
    // map with adjacent list of neighbours
    void addEdge(dataT u, dataT v, bool directive){// 0-> undirected graph, 1 -> directed graph
        m[u].push_back(v);
        if(directive == false){
            m[v].push_back(u);
        }
    }
    void printAsList(){
        for(auto i: m){
            cout<< i.first<< " -> ";
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    graph<int> g;
    int n,m;
    cout<< "Number of nodes and edges repectively: ";
    cin>>n>>m;
    for(int i=0;i < m;i++){
        int u,v;
        cin>> u>> v;
        // here 0 is for undirected graph
        g.addEdge(u,v , 0);
    }
    g.printAsList();
    return 0;
}
