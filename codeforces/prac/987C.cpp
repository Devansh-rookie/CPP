#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        if(n <= 1){
            cout << -1 << endl;
            continue;
        }
        vector<int> arr(n);
        if(n % 2 == 0){
            int j = 1;
            for(int i=0; i < n;i += 2){
                arr[i] = j;
                arr[i+1] = j;
                j++;
            }
        }
        if(n == 3){
            cout << -1 << endl;
            continue;
        }
        else{
            int j = 1;
            for(int i=0; i < n;i += 2){
                arr[i] = j;
                arr[i+1] = j;
                j++;
            }
            arr[n-1] = arr[n-4];
        }

        for(int i: arr){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}