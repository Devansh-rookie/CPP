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


int main() {
    int t;
    cin >>t;
    while (t--) {
        int n,l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i +1]=pre[i] + a[i];
        }

        int start =0;
        int count = 0;

        for (int end =0; end < n; end++) {
            while(start <= end &&(pre[end + 1] -pre[start] > r)){
                start++;
            }
            if(start <= end&&l <=(pre[end + 1] -pre[start]) && (pre[end + 1] - pre[start]) <= r){
                count++;
                start = end + 1;
            }
        }
        cout<< count <<endl;
    }
    return 0;
}
