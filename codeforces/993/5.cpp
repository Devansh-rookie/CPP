#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        // long k, l1, r1, l2, r2;
        // cin >> k >> l1>> r1 >> l2 >> r2;


        // long y = l2;
        // long x = l1;
        // ll ans = 0;


        // for(x = l1; x <= r1;x++){
        //     int n = 0;
        //     ll curr = x*(pow(k, 0));
        //     while(curr <= r2){
        //         if(curr == y) ans++;
        //         n++;
        //         curr = x*(pow(k, n));
        //     }
        // }

        // cout << ans << endl;

        // ll k, l1, r1, l2, r2;
        // cin >> k >> l1 >> r1 >> l2 >> r2;

        // ll ans = 0;

        // for (ll x = l1; x <= r1; ++x) {
        //     ll y = x; 
        //     while (y <= r2) {
        //         if (y >= l2) ans++; 
        //         if (y > r2 / k) break; 
        //         y *= k; 
        //     }
        // }

        // cout << ans << endl;

        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;

        ll ans = 0;
        ll power = 1; 

        while (power <= r2) { 
            ll min_x = max(l1, (l2 + power - 1) / power); 
            ll max_x = min(r1, r2 / power);

            if (min_x <= max_x) {
                ans += (max_x - min_x + 1);
            }

            if (power > r2 / k) break; 
            power *= k; 
        }

        cout << ans << endl;
    }
    return 0;
}