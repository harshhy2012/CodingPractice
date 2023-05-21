#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<char> chars = {'a','a','b','b','b','c','c'};
    for(auto ch: chars){
        cout<<ch<<" ";
    }
    cout<<endl;
    int i = 2, count = 3;
    chars.erase(chars.begin()+i-count+1, chars.begin()+i);
    for(auto ch: chars){
        cout<<ch<<" ";
    }
    cout<<endl;
    chars.insert(chars.begin()+1, '2');
    for(auto ch: chars){
        cout<<ch<<" ";
    }
    cout<<endl;
    string s = "";
    reverse(s.begin(), s.end());
    cout<<s<<endl;
    return 0;
}