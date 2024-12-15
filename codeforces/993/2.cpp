#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        string old;
        cin >> old;

        string nw = "";
        int n = old.size();
        for(int i= n -1; i>=0;i--){
            if(old[i] == 'w'){
                nw += 'w';
            }
            else if(old[i] == 'q'){
                nw += 'p';
            }
            else{
                nw += 'q';
            }
        }
        cout << nw << endl;
    }
    return 0;
}