#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string, string> m;
    pair<string, string> p("1", "Devansh");
    pair<string, string> p2 = make_pair("2", "Dev");
    m.insert(p);
    m.insert(p2);

    cout << m["12"] <<endl;// makes an empty string, if the value type was int it would have been 0
    cout << m.at("12") <<endl;

    cout<< m.size()<< endl;

    cout << m.erase("10")<< endl;
    cout<< m.size()<< endl;
    return 0;
}