#include<bits/stdc++.h>
using namespace std;
void util(vector<string> &ans, string nums, int index, int k, string &s){
        if(ans.size() == k){
            s = ans[k-1];
        }
        if(nums.length() == index){
            ans.push_back(nums);
            return;
        }
        if(s.length() == 0){
            for(int i= index;i < nums.length();i++){
                swap(nums[index], nums[i]);
                util(ans, nums, index+1, k, s);
            }
        }
    }
void getPermutation(int n, int k) {
    vector<string> ans;
    string nums ="";
    for(int i=1;i<=n;i++){
        nums+= (char)(i+48);
    }
    string s = "";
    util(ans, nums, 0, k, s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<< ans[i] <<endl;
    }
    cout<<endl<< s<<endl;
}

int main(){
    getPermutation(5,100);
    return 0;
}