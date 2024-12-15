#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        vector<int> arr(k);
        for(int i=0;i < k;i++){
            cin >> arr[i];
        }
        int target = k-2;
        sort(arr.begin(), arr.end());
        bool flag = false;
        int left = 0;
        int right = k-1;
        while(left < right){
            int prod = arr[left]*arr[right];

            if(prod == target){
                cout << arr[left] << " " << arr[right] << endl;
                flag = true;
                break;
            }
            else if(prod < target){
                left++;
            }
            else{
                right--;
            }
        }
    }
   return 0;
}