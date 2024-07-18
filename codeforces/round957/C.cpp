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
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m>> k;
        // really good question
        // n till m then from m to k then 1 to k
        for(int i = n;i>= k;i--){
            cout << i<< " ";
        }
        for(int i= m+1;i < k;i++){
            cout << i <<" ";
        }
        for(int i = 1;i <= m;i++){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}