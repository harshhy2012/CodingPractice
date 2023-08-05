#include<bits/stdc++.h>

using namespace std;
// easy method
// void rev(string &s, string &ans, int i){
//     if(i<0)
//         return;
//     ans.push_back(s[i]);
//     rev(s,ans,i-1);
// }

void rev(string &s, int i){
    if(i>=s.size()/2)
        return;
    swap(s[i], s[s.size()-1-i]);
    rev(s, i+1);
}

int main(){
    string s;
    cin>>s;
    string ans = "";
    int i = 0;
    rev(s,i);
    cout<<s<<endl;
    return 0;
}