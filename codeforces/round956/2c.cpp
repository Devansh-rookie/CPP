#include <iostream>
#include <vector>
using namespace std;

bool can_transform(const vector<vector<int>>& a, const vector<vector<int>>& b, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((a[i][j] - b[i][j]) % 3 != 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<int>> b(n, vector<int>(m));
        
        for (int i = 0; i < n; ++i) {
            string row;
            cin >> row;
            for (int j = 0; j < m; ++j) {
                a[i][j] = row[j] - '0';
            }
        }
        
        for (int i = 0; i < n; ++i) {
            string row;
            cin >> row;
            for (int j = 0; j < m; ++j) {
                b[i][j] = row[j] - '0';
            }
        }
        
        if (can_transform(a, b, n, m)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
