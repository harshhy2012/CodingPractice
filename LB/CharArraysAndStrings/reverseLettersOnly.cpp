#include<bits/stdc++.h>

using namespace std;

string reverseOnlyLetters(string s){
    if(s.empty()){
        return "";
    }
    string res;
    for(int i=0;i<s.size();i++){
        if( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') )
            res.push_back(s[i]);
    }
    reverse(res.begin(), res.end());
    string ans;
    int x = 0;
    for(int i=0;i<s.size();i++){
        if( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ){
            ans.push_back(res[x]);
            x++;
        }
        else{
            ans.push_back(s[i]);
        }
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<reverseOnlyLetters(s)<<endl;
    return 0;
}