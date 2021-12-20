#include<bits/stdc++.h>

using namespace std;

string solve(string&s){
    int n = s.size();
    int i=0;
    if(s[i]=='9')
        i++;
    for(;i<n;i++){
        if(s[i]-'0'>=5)
            s[i] = '0' + (9-(s[i]-'0'));
    }
    return s;
}

int main(){
    string s;
    cin>>s;
    cout<<solve(s)<<endl;
    return 0;
}