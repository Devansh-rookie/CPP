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
// int main()
// {
//     int t;
//     cin >> t;
//     while(t--){
//         int x, y, k;
//         cin >> x>> y>> k;
//         while(k--){
//             x++;
//             while(x % y == 0){
//                 x = x/y;
//             }
//         }
//         cout << x << endl;
//     }
//     return 0;
// }
int main()
{
    int t;
    cin >> t;
    while(t--){
        int x, y, k;
        cin >> x>> y>> k;
        while(k > 0){
            int val = (x)%y;
            int second = (x/y*y+1)*y - x;
            val = min(val, second);
            if(val - k > 0){
                x+= k;
                break;
            }
            k -= val;
            x += val;
            while(x % y == 0){
                x = x/y;
            }
            k--;
        }
        cout << x << endl;
    }
    return 0;
}