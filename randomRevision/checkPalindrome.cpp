#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string s, int i){
    if(i>=s.size()/2)
        return true;
    if(s[i]==s[s.size()-i-1]){
        return isPalindrome(s, i+1);
    }
    else{
        return false;
    }
}

int main(){
    string s;
    cin>>s;
    if(isPalindrome(s, 0))
        cout<<"YES\n";
    else 
        cout<<"NO\n";
    return 0;
}