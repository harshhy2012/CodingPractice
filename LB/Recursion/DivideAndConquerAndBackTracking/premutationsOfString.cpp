#include<bits/stdc++.h>

using namespace std;

void printPermutation(string &s, int i){
    if(i==s.size()){
        cout<<s<<" ";
        return;
    }
    for(int j=i;j<s.size();j++){
        swap(s[i], s[j]);
        printPermutation(s,i+1);
        swap(s[i],s[j]);
    }
}

int main(){
    string s;
    cin>>s;
    printPermutation(s, 0);
    return 0;
}