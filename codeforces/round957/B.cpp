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
        int n, k;
        cin >> n >> k;
        vector<int> arr;
        for(int i=0;i<k;i++){
            int val;
            cin >> val;
            arr.push_back(val);
        }
        sort(arr.begin(), arr.end());
        // int suma =0;
        int ans = 0;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i] != 1) ans += (arr[i]-1) + arr[i];
            else ans += 1;
        }
        cout << ans <<endl;
    }
    return 0;
}