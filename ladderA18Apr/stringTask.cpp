#include<bits/stdc++.h>

using namespace std;

bool isVowel(char c){
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='Y');
}

int main(){
    string s;
    cin>>s;
    string ans;
    for(int i=0;i<s.size();i++){
        if(!isVowel(s[i])){
            ans.push_back('.');
            ans.push_back(tolower(s[i]));
        }
    }   
    cout<<ans<<endl;
    return 0;
}