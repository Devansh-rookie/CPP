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
        int x1,y1,x2,y2;
        cin >> x1>>y1;
        cin >> x2 >> y2;
        if((x1>y1 && x2>y2 )||(x1 < y1 && x2 < y2)){
            cout << "YES"<< endl;
        }
        else cout << "NO"<<endl;
    }
    return 0;
}