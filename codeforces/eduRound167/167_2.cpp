// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <iomanip>
// #include <string>  
// #include <vector>
// #include <list>        
// #include <set> 
// #include <map>    
// #include <queue> 
// #include <stack>
// #include <algorithm>  
// #include <cmath> 
// #include <ctime> 
// #include <cstdlib>
// #include <cstring> 
// #include <cctype> 
// #include <cassert>
// #include <exception>   
// #include <functional>
// #include <iterator>
// #include <limits>  
// #include <locale>   
// #include <numeric>  
// #include <random> 
// #include <stdexcept> 
// #include <typeinfo> 
// #include <utility>
// using namespace std;
// int longest_common_subsequence(string &a, string &b, int m, int n, vector<vector<int>> &dp){
//     if(m == 0 || n== 0) return 0;
//     if(dp[m][n]!=-1) return dp[m][n];
//     if(a[m-1] == b[n-1]) return dp[m][n] = 1+longest_common_subsequence(a,b,m-1,n-1, dp);
    
//     return dp[m][n] = max(longest_common_subsequence(a,b,m,n-1, dp), longest_common_subsequence(a,b,m-1,n, dp)); 
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while(t--){
//         string a, b;
//         cin >>a;
//         cin >>b;
//         int ans =0;
//         vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, -1));
//         ans = a.length() + b.length() - longest_common_subsequence(a,b,a.length(), b.length(), dp);
//         cout << ans<<endl;
//     }
//     return 0;
// }
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to calculate the longest common subsequence using memoization
int longest_common_subsequence(const string &a, const string &b, int m, int n, vector<vector<int>> &dp) {
    if (m == 0 || n == 0) 
        return 0;
    if (dp[m][n] != -1) 
        return dp[m][n];
    if (a[m-1] == b[n-1]) 
        return dp[m][n] = 1 + longest_common_subsequence(a, b, m-1, n-1, dp);
    return dp[m][n] = max(longest_common_subsequence(a, b, m, n-1, dp), longest_common_subsequence(a, b, m-1, n, dp)); 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        int m = a.length();
        int n = b.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int lcs_length = longest_common_subsequence(a, b, m, n, dp);
        int result = m + n - lcs_length;
        cout << result << endl;
    }
    return 0;
}
