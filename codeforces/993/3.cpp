#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        long m, a, b, c;
        cin >> m >> a >> b >> c;

        long long ans = 0;

        long row1 = m, row2 = m;

        // seat in row 1;

        if(m >= a){
            row1 -= a;
            ans += a;
        }
        else{
            row1 = 0;
            ans += m;
        }

        if(m >= b){
            row2 -= b;
            ans += b;
        }
        else{
            row2 = 0;
            ans += m;
        }

        if(row1 > 0){
            if(c >= row1){
                ans += row1;
                c -= row1;
            }
            else{
                ans += c;
                c = 0;
            }
        }

        if(row2 > 0){
            if(c >= row2){
                ans += row2;
                c -= row2;
            }
            else{
                ans += c;
                c = 0;
            }
        }
        cout <<  ans << endl;
    }
    return 0;
}