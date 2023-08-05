#include<bits/stdc++.h>

using namespace std;

string removeDuplicates(string s){
    string res = "";
    for(int i=0;i<s.size();i++){
        if(!s.empty() && s[i] == res[res.size()-1]){
            res.pop_back();
        }
        else{
            res.push_back(s[i]);
        }
    }
    return res;
}

int main(){
    string s;
    cin>>s;
    cout<<removeDuplicates(s)<<endl;
    return 0;
}