#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<char> chars = {'a','a','b','b','b','c','c'};
    int i = 2, count = 3;
    chars.erase(chars.begin()+i-count+1, chars.begin()+i);
    string s = "";
    reverse(s.begin(), s.end());
    cout<<s<<endl;
    return 0;
}