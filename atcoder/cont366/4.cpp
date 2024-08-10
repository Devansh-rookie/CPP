// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     // Initializing the 3D grid
//     vector<vector<vector<int> > > grid(n, vector<vector<int> >(n, vector<int>(n,0)));

//     for (int x = 0; x < n; x++) {
//         for (int y = 0; y < n; y++) {
//             for (int z = 0; z < n; z++) {
//                 cin >> grid[x][y][z];
//             }
//         }
//     }
//     vector<vector<vector<int> > > grid(n, vector<vector<int> >(n, vector<int>(n,0)));
//     int q;
//     cin >> q;

//     while (q--) {
//         int lx, ly, lz, rx, ry, rz;
//         cin >> lx >> rx >> ly >> ry >> lz >> rz;

//         int ans = 0;

//         // Sum elements in the specified sub-region
//         for (int i = lx-1; i < rx; i++) {
//             for (int j = ly-1; j < ry; j++) {
//                 for (int k = lz-1; k < rz; k++) {
//                     ans += grid[i][j][k];
//                 }
//             }
//         }
//         cout << ans << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    // Initializing the 3D grid and prefix sum array
    vector<vector<vector<int> > > grid(n, vector<vector<int> >(n, vector<int>(n)));
    vector<vector<vector<int> > > prefix(n, vector<vector<int> >(n, vector<int>(n, 0)));

    // Input the grid
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < n; y++) {
            for(int z = 0; z< n; z++) {
                cin >> grid[x][y][z];
            }
        }
    }

    // Calculate the 3D prefix sum array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                prefix[i][j][k] = grid[i][j][k];

                if (i >0)prefix[i][j][k] += prefix[i-1][j][k];
                if (j >0)prefix[i][j][k] += prefix[i][j-1][k];
                if (k >0)prefix[i][j][k] += prefix[i][j][k-1];

                if (i > 0&&j > 0) prefix[i][j][k] -= prefix[i-1][j-1][k];
                if (i > 0 && k > 0) prefix[i][j][k] -= prefix[i-1][j][k-1];
                if (j > 0 && k > 0) prefix[i][j][k] -= prefix[i][j-1][k-1];

                if (i > 0 && j > 0 && k > 0) prefix[i][j][k] += prefix[i-1][j-1][k-1];
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int lx, ly, lz, rx, ry, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        lx--;ly--;lz--;rx--;ry--;rz--;
        int ans = prefix[rx][ry][rz];

        if (lx >0) ans -= prefix[lx-1][ry][rz];
        if (ly >0) ans -= prefix[rx][ly-1][rz];
        if (lz >0) ans -= prefix[rx][ry][lz-1];

        if (lx > 0 && ly > 0) ans +=prefix[lx-1][ly-1][rz];
        if (lx > 0 && lz > 0) ans+= prefix[lx-1][ry][lz-1];
        if (ly > 0 && lz > 0) ans += prefix[rx][ly-1][lz-1];
        if (lx > 0 && ly > 0 && lz > 0) ans -= prefix[lx-1][ly-1][lz-1];
        cout<<ans<<endl;
    }

    return 0;
}
