#include<bits/stdc++.h>

using namespace std;

// find frequency of characters of a string using map

int main(){
    string s;
    cin>>s;
    unordered_map<char, int> freq;
    for(auto ch: s){
        freq[ch]++;
    }

    for(auto i: freq){
        cout<<i.first<<" -> "<<i.second<<endl;
    }
    return 0;
}