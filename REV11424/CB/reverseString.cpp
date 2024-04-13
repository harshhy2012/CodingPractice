#include<bits/stdc++.h>

using namespace std;

void revStr(string&s){
    for(int i=0;i<s.size()/2;i++){
        swap(s[i], s[s.size()-i-1]);
    }
}

int main(){
    string s;
    cin>>s;
    revStr(s);
    cout<<s<<endl;
    return 0;
}