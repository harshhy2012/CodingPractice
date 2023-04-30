#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string s, int i, int j){
    while(i<=j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool canBePalindrome(string s){
    int i=0, j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j]){
            return isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1);
        }
        else{
            i++;
            j--;
        } 
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    // can deleting 1 char make the string palindrome.
    if(canBePalindrome(s)){
        cout<<"true\n";
    }
    else{
        cout<<"false\n";
    }
  
    return 0;
}