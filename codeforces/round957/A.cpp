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
        int a, b, c;
        cin >> a>>b >>c;
        vector<int> abc(3);
        abc[0] = a;
        abc[1] = b;
        abc[2] = c;
        for(int j=0;j<5;j++){
            sort(abc.begin(), abc.end());
            abc[0]++;
        }
        cout << abc[0]*abc[1]*abc[2] << endl;
    }
    return 0;
}