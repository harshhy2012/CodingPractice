#include<bits/stdc++.h>

using namespace std;


void lastOcc(string& s, int i, char& ch, int &ans){
    if(i>=s.size()){
        return;
    }
    if(s[i]==ch)
        ans = i;
    lastOcc(s, i+1, ch, ans);
}

int main(){
    string s;
    cin>>s; // abcddefg
    char ch;
    cin>>ch;// d
    int i = 0, ans = -1;
    lastOcc(s, i, ch, ans);
    cout<<ans<<endl;
    return 0;
}