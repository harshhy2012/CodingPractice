#include<bits/stdc++.h>

using namespace std;

bool saidHello(string s){
    string correct = "hello";
    int i=0,j=0;
    while(i<s.size() && j<correct.size()){
        if(s[i]==correct[j]){
            j++;
        }
        i++;
    }
    // cout<<"j : "<<j<<endl;
    if(j==correct.size())
        return true;
    else
        return false;
}

int main(){
    string s;
    cin>>s;
    if(saidHello(s))
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}