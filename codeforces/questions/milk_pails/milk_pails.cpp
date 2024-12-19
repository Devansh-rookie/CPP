#include<bits/stdc++.h>
using namespace std;
/*
ifstream fin("problemname.in");
ofstream fout("problemname.out");

*/
// int solve(int x, int y, int m, int i, int j, vector<vector<int>>&dp){
//     if(i*x + j*y > m) return 0;
//     if(dp[i][j]!= -1) dp[i][j];
//     return dp[i][j] = max({i*x + j*y, solve(x, y, m, i+1, j, dp), solve(x, y, m, i, j+1, dp)});
// }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x, y, m;
    ifstream fin("pails.in");
    ofstream fout("pails.out");
    // cin >> x >> y >> m;
    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Error: Unable to open file(s)." << endl;
        return 1;
    }
    // cout << solve(x, y, m, 0, 0);
    fin >> x >> y >> m;
    // vector<vector<int>>dp(x, vector<int>(y, -1));
    // fout << solve(x, y, m, 0, 0, dp) << "\n";
    int maxx = 0;
     for (int i = 0; i * x <= m; i++)
    {
        for (int j = 0; i * x + j * y <= m; j++)
        {
            maxx = max(i * x + j * y, maxx);
        }
    }

    fout << maxx << "\n";
    return 0;
}