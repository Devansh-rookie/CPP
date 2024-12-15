#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int n, a, b;
    cin >> t;   
    while(t--){
        cin >> n >> a>>b;   
        string s;
        cin >> s;
        int x = 0, y = 0;
        bool f = false;
        for(int i=0;i <50;i++){
            if(f) break;
            for(char c : s){
                if(c == 'N') y++;
                if(c == 'E') x++;
                if(c == 'S') y--;
                if(c == 'W') x--;
                if(x == a && y == b){
                    f = true;
                    cout << "yes" << endl;
                    break;
                }
            }
        }
        if(!f) cout << "no" << endl;
    }
    return 0;
}