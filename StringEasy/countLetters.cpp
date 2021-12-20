#include<bits/stdc++.h>

using namespace std;

vector<int> countLetters(string &s){
    vector<int> ans(256,0);
    for(int i=0;i<s.size();i++){
        ans[s[i]]++;
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    vector<int> arr = countLetters(s);
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=0)
            cout<<(char)i<<" occurances : "<<arr[i]<<endl;
    }
    return 0;
}