#include<bits/stdc++.h>

using namespace std;

string originalSong(string s){
    string wub = "WUB";
    string ans = "";
    for(int i=0;i<s.size();){
        if(s.substr(i,3) == wub){
            i+=2;    
            ans.push_back(' ');
        }
        else{
            ans.push_back(s[i]);
        }    
        i++;
    }
    while(ans[0] == ' '){
        reverse(ans.begin(), ans.end());
        ans.pop_back();
        reverse(ans.begin(), ans.end());
    }  
    return ans;
}

int main(){
    string s;
    cin>>s; 
    cout<<originalSong(s)<<endl;
    return 0;
}