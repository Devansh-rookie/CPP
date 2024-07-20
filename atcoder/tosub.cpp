#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

// bool isPalin(string s){
//     int n = s.length();
//     for(int i=0; i<= n/2; i++){
//         if(s[i] != s[n - i- 1]) return false;
//     }
//     return true;
// }

// bool kPalin(string s, int k){
//     if(k < s.length()) return false;
    
//     for(int i=0;i <= s.length() - k;i++){
//         // if(isPalin(s.substr(i, k))) return true;

//     }
//     return false;
// }

string preprocessString(const string& s) {
    string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }
    return t;
}

vector<int> manacher(const string& s) {
    string T = preprocessString(s);
    int n = T.length();
    vector<int> P(n, 0);
    int C = 0, R = 0;

    for (int i = 0; i < n; ++i) {
        int mirr = 2 * C - i;
        if (i < R) {
            P[i] = min(R - i, P[mirr]);
        }
        while (i + P[i] + 1 < n && i - P[i] - 1 >= 0 && T[i + P[i] + 1] == T[i - P[i] - 1]) {
            P[i]++;
        }
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
    return P;
}

bool kPalin(string& s, int k) {
    if (k == 0) return true;
    if (k > s.length()) return false;

    vector<int> P = manacher(s);
    for (int length : P) {
        if ((k % 2 == 0 && length >= k / 2) || (k % 2 == 1 && length >= (k + 1) / 2)) {
            return true;
        }
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