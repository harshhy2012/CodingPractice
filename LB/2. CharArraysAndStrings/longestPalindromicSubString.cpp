#include<bits/stdc++.h>

using namespace std;

bool ispalindrome(string &s, int start, int end){
    while(start<end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

string longPalinStr(string s){
    string ans = "";
    int n = s.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(ispalindrome(s, j, i)){
                //cout<<"ANS: "<<ans<<" || "<<" substr:
                string x = s.substr(j,abs(j-i)+1);
                    ans = x.size() > ans.size() ? x : ans;
            }
        }
    }
    return ans;
}

int main(){
    string s;
    cin>>s;

    cout<<longPalinStr(s)<<endl;

    return 0;
}