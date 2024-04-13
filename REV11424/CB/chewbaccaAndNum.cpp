#include<bits/stdc++.h>

using namespace std;

void invertString(string&s){
    if(s[0] > '4' && s[0]!='9'){
        s[0] = '9'- s[0] + '0';
    }
    for(int i=1;i<s.size();i++){
        if(s[i] > '4'){
        s[i] = '9'- s[i] + '0';
        }
    }
}

int main(){
    string s;
    cin>>s;
    invertString(s);
    cout<<s<<endl;
    return 0;
}