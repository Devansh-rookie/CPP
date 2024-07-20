#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

bool isPalin(string s){
    int n = s.length();
    for(int i=0; i<= n/2; i++){
        if(s[i] != s[n - i- 1]) return false;
    }
    return true;
}

bool kPalin(string s, int k){
    for(int i=0;i <= s.length() - k;i++){
        // if(isPalin(s.substr(i, k))) return true;
        string sub = s.substr(i, k);
        string rev = sub;
        reverse(rev.begin(), rev.end());
        if();
    }
    return false;
}

void permute(string s, int index, int &c, int k, unordered_set<string>& done){
    if(index == s.length()){
        if(done.find(s) ==done.end() && !kPalin(s, k)){ 
            c++;
            done.insert(s);
        }
        return;
    }
    unordered_set<char> used;
    for(int i=index; i < s.length();i++){
        // if(s[i] != s[index] || i == index){
        //     std::swap(s[i], s[index]);
        //     permute(s, index+1, c, k, done);
        // }
        if (used.find(s[i]) == used.end()) {
            used.insert(s[i]);
            swap(s[i], s[index]);
            permute(s,index+1, c, k, done);
            swap(s[i], s[index]); 
        }
    }
    return;
}

int main(){
    int n, c, k;
    cin >> n >> k;
    string s;
    cin>> s;
    c=0;
    unordered_set<string> done;
    permute(s, 0, c, k, done);
    cout << c;
    return 0;
}