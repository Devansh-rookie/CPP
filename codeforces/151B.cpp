#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include <string>
#include<climits>
#include<vector>
using namespace std;



bool checkTaxi(string s){
    char first = s[0];
    for(int i=0;i< s.length();i++){
        if(s[i] == '-') continue;
        if(first != s[i]) return false;
    }
    return true;
}

bool checkPizza(string s){
    char prev = s[0];
    for(int i=1;i<s.length(); i++){
        if(s[i] == '-') continue;
        if(prev <= s[i]) return false;
        prev = s[i];
    }
    return true;
}


class Person{
    public:
        int taxi,pizza,girls;
        string name;
        Person(string namee){
            this->name = namee;
            this->girls=0;
            this->pizza=0;
            this->taxi=0;
        }
        void addNumber(string s){
            if(checkTaxi(s)){
                this->taxi++;
            }
            else if(checkPizza(s)) this->pizza++;
            else this->girls++;
        }
};



int main(){
    int n;
    cin>>n;
    vector<Person> arr;
    for(int i=0;i< n;i++){
        int num;
        string name;
        cin>>num >> name;
        Person p(name);
        
        for(int j=0;j < num;j++){
            string number;
            cin>>number;
            p.addNumber(number);
        }
        arr.push_back(p);
    }
    int maxG= INT_MIN;
    int maxT = INT_MIN;
    int maxP = INT_MIN;
    for(int i=0;i< arr.size();i++){
        
        if(maxG< arr[i].girls){
            maxG = arr[i].girls;
        }
        if(maxT< arr[i].taxi){
            maxT = arr[i].taxi;
        }
        if(maxP< arr[i].pizza){
            maxP = arr[i].pizza;
        }
    }
    string ans = "If you want to call a taxi, you should call: ";
    string ans2 = "If you want to order a pizza, you should call: ";
    string ans3 = "If you want to go to a cafe with a wonderful girl, you should call: ";

    for(int i=0;i< arr.size();i++){
        if(arr[i].taxi == maxT) ans += arr[i].name + ", ";
        if(arr[i].pizza == maxP) ans2 += arr[i].name + ", ";
        if(arr[i].girls == maxG) ans3 += arr[i].name + ", ";
    }

    ans = ans.substr(0, ans.length() - 2) + ".";
    ans2 = ans2.substr(0, ans2.length() - 2) + ".";
    ans3 = ans3.substr(0, ans3.length() - 2) + ".";

    cout << ans << endl;
    cout << ans2 << endl;
    cout << ans3 << endl;


    return 0;
}
// #include<iostream>
// #include<vector>
// #include<string>
// #include<climits>

// using namespace std;

// bool checkTaxi(string s){
//     char first = s[0];
//     for(char c : s){
//         if(c == '-') continue;
//         if(first != c) return false;
//     }
//     return true;
// }

// bool checkPizza(string s){
//     char prev = s[0];
//     for(int i=1; i < s.length(); i++){
//         if(s[i] == '-') continue;
//         if(prev <= s[i]) return false;
//         prev = s[i];
//     }
//     return true;
// }

// class Person {
// public:
//     int taxi, pizza, girls;
//     string name;
//     Person(string namee) : name(namee), taxi(0), pizza(0), girls(0) {}

//     void addNumber(string s){
//         if(checkTaxi(s)){
//             taxi++;
//         }
//         else if(checkPizza(s)) {
//             pizza++;
//         }
//         else {
//             girls++;
//         }
//     }
// };

// int main(){
//     int n;
//     cin >> n;
//     vector<Person> arr;
    
//     for(int i = 0; i < n; i++){
//         int num;
//         string name;
//         cin >> num >> name;
//         Person p(name);
        
//         for(int j = 0; j < num; j++){
//             string number;
//             cin >> number;
//             p.addNumber(number);
//         }
        
//         arr.push_back(p);
//     }

//     int maxG = INT_MIN, maxT = INT_MIN, maxP = INT_MIN;
//     for(const auto& person : arr){
//         if(maxG < person.girls) maxG = person.girls;
//         if(maxT < person.taxi) maxT = person.taxi;
//         if(maxP < person.pizza) maxP = person.pizza;
//     }

//     string ans = "If you want to call a taxi, you should call: ";
//     string ans2 = "If you want to order a pizza, you should call: ";
//     string ans3 = "If you want to go to a cafe with a wonderful girl, you should call: ";

//     for(const auto& person : arr){
//         if(person.taxi == maxT) ans += person.name + ", ";
//         if(person.pizza == maxP) ans2 += person.name + ", ";
//         if(person.girls == maxG) ans3 += person.name + ", ";
//     }

//     ans = ans.substr(0, ans.length() - 2) + ".";
//     ans2 = ans2.substr(0, ans2.length() - 2) + ".";
//     ans3 = ans3.substr(0, ans3.length() - 2) + ".";

//     cout << ans << endl;
//     cout << ans2 << endl;
//     cout << ans3 << endl;

//     return 0;
// }
