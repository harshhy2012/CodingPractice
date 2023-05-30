#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string& s, int i){
    if(i>=s.size()/2){
        return true;
    }
    if(s[i]!=s[s.size()-1-i])
        return false;
    return isPalindrome(s,i+1);
}

int main(){
    string s;
    cin>>s;
    if(isPalindrome(s, 0))
        cout<<"PALINDROME\n";
    else
        cout<<"NOT PALINDROME\n";
    return 0;
}