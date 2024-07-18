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

pair<int, int> min_sum(const vector<int>& values, int required_sum) {
    int n = values.size();
    int current_sum = 0;
    int start= 0;
    for(int end = 0; end < n; ++end){
        current_sum += values[end];
        while(current_sum >=required_sum){
            if(current_sum >= required_sum){
                return {start, end};
            }
            current_sum -= values[start];
            ++start;
        }
    }
    return {-1, -1};
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int tot;
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);

        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        for(int i=0;i<n;i++) cin >> c[i];

        // int la, ra, lb1, rb1,lb2, rb2, lc, rc;
        tot = 0;
        for(int i=0;i<n;i++){
            tot += a[i];
        }
        int val = ceil(tot/3);
        // int left = 0;
        // int right = 0;
        // int suma = 0;
        auto [la, ra] = min_sum(a, val);
        if(la == -1){
            cout << -1 << endl;
            continue;
        }
        auto [lb1, rb1] = min_sum(vector<int>(b.begin()+ ra + 1, b.end()), val);
        auto [lb2, rb2] = min_sum(vector<int>(b.begin(), b.begin() + la+1), val);
        if(lb1 == -1&& lb2== -1){
            cout<< -1<<endl;
            continue;
        }
        int lb, lc;
        lb1 += ra + 1;
        if(lb1 == -1) lb1 = lb2;
        else if(lb2 == -1) lb2 = lb1;
        // case 1: 
        auto[lc1, rc1] = min_sum(vector<int>(c.begin() + lb1+1, c.end()), val);
        auto[lc2, rc2] = min_sum(vector<int>(c.begin() + lb2+1, c.end()), val);
        lc1 += lb1+1;
        lc2 += lb2 +1;
        // case 2
        auto[lc3, rc3] = min_sum(vector<int>(c.begin(),c.begin()+lb1+1), val);
        auto[lc4, rc4] = min_sum(vector<int>(c.begin(), c.begin() + lb2+1), val);
        if(lc1 == -1&& lc2== -1&&lc3 == -1&& lc4== -1){
            cout<< -1<<endl;
            continue;
        }
        if(lc1 == -1 && lc3 == -1 && (((la > rc2)|| ra < lc2)|| ((la > rc4)|| ra < lc4))){
            lb = lb2;
        }
        else if(lc2 == -1 && lc4 == -1  && (((la > rc2)|| ra < lc2)|| ((la > rc4)|| ra < lc4))){
            lb = lb1;
        }

    }
    return 0;
}