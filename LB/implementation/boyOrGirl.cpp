#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<bool> arr(257,0);
    arr[0]=-1;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        arr[s[i]-'0'] = true;
    }
    int distChars=0;
    for(int i=1;i<=256;i++){
        if(arr[i])
            distChars++;
    }
    if(distChars%2==0)
        cout<<"CHAT WITH HER!\n";
    else
        cout<<"IGNORE HIM!\n";

    return 0;
}