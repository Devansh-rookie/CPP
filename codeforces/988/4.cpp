// // // #include<bits/stdc++.h>
// // // using namespace std;

// // // int solve(int curr, vector<vector<int>> hurdles, vector<vector<int>> powerUps, int L, int jumping){
// // //     if();
// // // }

// // // int main()
// // // {
// // //     ios::sync_with_stdio(0);
// // //     cin.tie(0);
// // //     int t;
// // //     cin >> t;
// // //     while(t--){
// // //         int n, m, L;
// // //         cin >> n >> m >> L;
// // //         vector<vector<int>> hurdles(n, vector<int>(2, 0));
// // //         vector<vector<int>> powerUps(m);
// // //         for(int i=0;i < n;i++){
// // //             cin >> hurdles[i][0] >> hurdles[i][1];
// // //         }
// // //         for(int i=0;i < m;i++){
// // //             int x, val;
// // //             cin >> x;
// // //             cin >> val;
// // //             powerUps[x].push_back(val);
// // //         }
// // //         for(int i=0;i < m;i++){
// // //             sort(powerUps[i].rbegin(), powerUps[i].rend());
// // //         }


// // //     }
// // //    return 0;
// // // }

// // #include <bits/stdc++.h>
// // using namespace std;

// // int solve(int curr, vector<pair<int, int>> &events, int L, int jumping) {
// //     int powerUpsCollected = 0;
// //     priority_queue<int> pq; // Max-heap for power-ups

// //     for (int i = 0; i < events.size(); i++) {
// //         int pos = events[i].first;
// //         int type = events[i].second;

// //         // If it's a power-up, add to the heap
// //         if (type > 0) {
// //             pq.push(type);
// //             continue;
// //         }

// //         // If it's a hurdle, ensure we can jump over it
// //         int hurdle_start = pos;
// //         int hurdle_end = -type;

// //         while (curr + jumping < hurdle_start && curr < hurdle_start && !pq.empty()) {
// //             jumping += pq.top();
// //             pq.pop();
// //             powerUpsCollected++;
// //         }

// //         if (curr + jumping < hurdle_start) return -1; // Cannot proceed

// //         // Update current position to just after the hurdle
// //         curr = hurdle_end + 1;
// //     }

// //     // Final stretch to L
// //     while (curr + jumping < L && !pq.empty()) {
// //         jumping += pq.top();
// //         pq.pop();
// //         powerUpsCollected++;
// //     }

// //     return (curr + jumping >= L) ? powerUpsCollected : -1;
// // }

// // int main() {
// //     ios::sync_with_stdio(0);
// //     cin.tie(0);

// //     int t;
// //     cin >> t;
// //     vector<int> ans;
// //     while (t--) {
// //         int n, m, L;
// //         cin >> n >> m >> L;

// //         vector<pair<int, int>> events; // (position, type)
// //         for (int i = 0; i < n; i++) {
// //             int l, r;
// //             cin >> l >> r;
// //             events.push_back({l, -r}); // Hurdle represented as (-r)
// //         }

// //         for (int i = 0; i < m; i++) {
// //             int x, val;
// //             cin >> x >> val;
// //             events.push_back({x, val}); // Power-up represented as value
// //         }

// //         sort(events.begin(), events.end()); // Sort events by position
// //         // cout << solve(1, events, L, 1) << "\n"; // Start at position 1 with jump power 1
// //         ans.push_back(solve(1, events, L, 1));
// //     }
// //     for(int i: ans){
// //         cout << i << endl;
// //     }
// //     return 0;
// // }


// #include <bits/stdc++.h>
// using namespace std;

// const int INF = 1e9; // Large value to denote impossible states

// int solve(int curr, int jumping, int L, vector<pair<int, int>> &hurdles, 
//           map<int, vector<int>> &powerUps, unordered_map<int, unordered_map<int, int>> &dp) {
//     // Base cases
//     if (curr >= L) return 0; // Reached the end
//     if (dp.count(curr) && dp[curr].count(jumping)) return dp[curr][jumping]; // Memoization
//     for (auto &h : hurdles) {
//         if (curr >= h.first && curr <= h.second) return INF; // Position blocked by a hurdle
//     }

//     // Try all possible moves
//     int minPowerUps = INF;

//     // Process power-ups at the current position
//     if (powerUps.count(curr)) {
//         for (int pu : powerUps[curr]) {
//             minPowerUps = min(minPowerUps, 1 + solve(curr, jumping + pu, L, hurdles, powerUps, dp));
//         }
//     }

//     // Move to the next position within the jump range
//     minPowerUps = min(minPowerUps, solve(curr + 1, jumping, L, hurdles, powerUps, dp));

//     return dp[curr][jumping] = minPowerUps;
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int t;
//     cin >> t;

//     while (t--) {
//         int n, m, L;
//         cin >> n >> m >> L;

//         vector<pair<int, int>> hurdles(n); // {l, r}
//         map<int, vector<int>> powerUps;   // {position -> values}

//         for (int i = 0; i < n; i++) {
//             int l, r;
//             cin >> l >> r;
//             hurdles[i] = {l, r};
//         }

//         for (int i = 0; i < m; i++) {
//             int x, v;
//             cin >> x >> v;
//             powerUps[x].push_back(v);
//         }

//         // Sort hurdles by start point (not strictly necessary, but ensures consistency)
//         sort(hurdles.begin(), hurdles.end());

//         // Memoization table
//         unordered_map<int, unordered_map<int, int>> dp;

//         // Solve from position 1 with jump power 1
//         int result = solve(1, 1, L, hurdles, powerUps, dp);

//         // Output result
//         cout << (result >= INF ? -1 : result) << "\n";
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // Large value to represent impossible states

struct State {
    int pos, jumping, powerUpsUsed;
    bool operator<(const State &other) const {
        return powerUpsUsed > other.powerUpsUsed; // Min-heap based on powerUpsUsed
    }
};

int minPowerUps(int L, vector<pair<int, int>> &hurdles, map<int, vector<int>> &powerUps) {
    priority_queue<State> pq; // Min-heap for BFS
    pq.push({1, 1, 0});       // Start at position 1 with jump power 1 and 0 power-ups used

    set<pair<int, int>> visited; // To avoid revisiting states
    visited.insert({1, 1});

    while (!pq.empty()) {
        State curr = pq.top();
        pq.pop();

        int pos = curr.pos;
        int jumping = curr.jumping;
        int powerUpsUsed = curr.powerUpsUsed;

        // If we reached or surpassed L, return the result
        if (pos >= L) return powerUpsUsed;

        // Check if current position is in a hurdle
        bool blocked = false;
        for (auto &h : hurdles) {
            if (pos >= h.first && pos <= h.second) {
                blocked = true;
                break;
            }
        }
        if (blocked) continue;

        // Try collecting power-ups at this position
        if (powerUps.count(pos)) {
            for (int pu : powerUps[pos]) {
                int newJumping = jumping + pu;
                if (!visited.count({pos, newJumping})) {
                    pq.push({pos, newJumping, powerUpsUsed + 1});
                    visited.insert({pos, newJumping});
                }
            }
        }

        // Try moving to the next position
        if (!visited.count({pos + 1, jumping})) {
            pq.push({pos + 1, jumping, powerUpsUsed});
            visited.insert({pos + 1, jumping});
        }
    }

    return -1; // If no valid path to L
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m, L;
        cin >> n >> m >> L;

        vector<pair<int, int>> hurdles(n);
        map<int, vector<int>> powerUps;

        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            hurdles[i] = {l, r};
        }

        for (int i = 0; i < m; i++) {
            int x, v;
            cin >> x >> v;
            powerUps[x].push_back(v);
        }

        // Solve the problem
        int result = minPowerUps(L, hurdles, powerUps);

        cout << result << "\n";
    }

    return 0;
}
